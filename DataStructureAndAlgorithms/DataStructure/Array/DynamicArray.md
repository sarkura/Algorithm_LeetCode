### The Core Concept
    Contiguous memory perspective
        A dynamic array is a contiguous block plus two lengths: Size (live elements) and Capacity (allocated slots).
        Data-structure keywords: traversal and access.
        Core actions: insert, delete, search, update.
        The block gives O(1) address access; the extra capacity avoids allocating on every write.

        1. Block is continuous in memory
            Elements sit in one linear buffer. Index i is at base + i * sizeof(T).
            Cache-friendly: walking 0..Size-1 is sequential reads.
            Size is how many objects are constructed. Capacity is how many slots the buffer can hold.
            Size <= Capacity. Empty slots in [Size, Capacity) are raw memory, not objects.
            Clear destroys live elements and sets Size = 0; the buffer (Capacity) stays.
            ShrinkToFit reallocates so Capacity == Size (or frees the buffer when Size is 0).

        2. Access by address is O(1)
            Random read / update by index is pointer arithmetic, not a walk.
            operator[] trusts the caller. At checks 0 <= index < Size and throws if not.
            Search by value is still a scan of the block: O(n), unless the array is sorted (then binary search).

        3. Add, insert, search, delete in the middle is O(n)
            The hole must stay contiguous, so the tail has to shift.
            Insert at index i: move [i, Size) one step right, then construct the new element.
            Delete at index i: destroy the element, then move [i + 1, Size) one step left.
            End operations are cheap when Capacity is enough: PushBack construct at Size, PopBack destroy Size - 1.
            Resize grows or shrinks Size: construct new slots or destroy extra ones; reallocate only if NewSize > Capacity.

        4. Capacity grows usually 2 times
            If Size == Capacity, the next PushBack must Reallocate.
            Reallocate: new buffer → move live elements → destroy old objects → delete old buffer → update Capacity.
            Doubling (empty → 2, then * 2) makes each element's move cost amortized O(1) over many PushBacks.
            A single grow is still O(n). Growing to exactly Size + 1 every time would make n PushBacks O(n^2).
            Resize may grow Capacity to NewSize only; PushBack uses the geometric factor.

        How to choose
            Need index access or a compact sequential scan → dynamic array.
            Need frequent insert / delete in the middle → linked list (no shift, no O(1) index).
            Need lookup by key, not by index → hash table on top of arrays.
            First write the O(n) shift (brute-force). Extra Capacity is the space trade that makes append cheap.
