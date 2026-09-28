### The Core Concept
    Circular-buffer perspective
        A deque (double-ended queue) is a contiguous block used as a ring: a Head index, a Size, and a Capacity.
        Data-structure keywords: traversal and access.
        Core actions: insert, delete, search, update.
        Both ends are open. The ring lets the front move without shifting, so both ends are O(1).

        1. Block is a ring in memory
            Logical index i sits at physical slot (Head + i) % Capacity.
            Front is Head. Back is (Head + Size - 1) % Capacity. The live range can wrap past the end of the buffer.
            Size <= Capacity. Empty means Size == 0; full means Size == Capacity.
            std::deque does not use one ring: it keeps a map of fixed-size chunks. Same O(1) ends, but not one contiguous block.

        2. Insert and delete at both ends are O(1)
            PushBack: construct at (Head + Size) % Capacity, then Size++.
            PushFront: Head = (Head - 1 + Capacity) % Capacity, construct at Head, then Size++.
            PopFront: destroy at Head, Head = (Head + 1) % Capacity, Size--.
            PopBack: destroy at (Head + Size - 1) % Capacity, Size--.
            A plain dynamic array makes PushFront / PopFront O(n) because everything shifts. The ring removes that shift.

        3. Access by index is O(1), middle insert / delete is O(n)
            Read / update by index is one modulo plus pointer arithmetic.
            Search by value is still a scan: O(n).
            Insert / delete in the middle shifts the shorter side toward the hole: still O(n).

        4. Capacity grows usually 2 times
            If Size == Capacity, the next push must Reallocate.
            Reallocate: new buffer → move elements in logical order (unroll the ring) → Head = 0 → free old buffer.
            Copying the raw buffer as-is would break the wrap; elements must be read through (Head + i) % OldCapacity.
            Amortized O(1) per push, same argument as dynamic-array doubling.

        Restricted forms
            Queue (First In, First Out): only PushBack and PopFront. BFS uses a queue level by level.
            Stack (Last In, First Out): only PushBack and PopBack. std::stack wraps std::deque by default.
            Monotonic queue: pop from the back while the new element beats it, pop from the front when it leaves the window.
                Sliding window maximum in O(n): each element enters and leaves once.

        How to choose
            Need O(1) at both ends → deque.
            Need only one end → stack; need FIFO → queue (both are a deque with fewer operations).
            Need frequent insert / delete in the middle → linked list.
            First write the O(k) scan of each window (brute-force, O(n * k)). The monotonic deque is the space trade that keeps only candidates and makes each step O(1) amortized.
