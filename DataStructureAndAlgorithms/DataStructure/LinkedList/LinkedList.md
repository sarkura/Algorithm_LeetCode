### The Core Concept
    Node-link perspective
        A linked list is discrete nodes plus pointers, not one contiguous block.
        Data-structure keywords: traversal and access.
        Core actions: insert, delete, search, update.
        No shift on insert / delete once the node is in hand; index access must walk the chain.
        [707] Design Linked List: doubly linked list with a dummy head, a dummy tail, and a Size of live nodes.

        1. Nodes are discrete in memory
            Each node holds a value, next, and prev. Nodes can sit anywhere on the heap.
            The list is the chain, not a base address plus offset. Walking is pointer hops, not sequential cache lines.
            Dummy nodes are sentinels, not data. They are not in Size and not in the index space.
            Empty list: virtualhead <-> virtualtail. Live nodes always sit strictly between them.
            Destructor walks from virtualhead and deletes every node, including the two dummies.

        2. Access by index is O(n)
            There is no pointer arithmetic to index i. get starts at virtualhead->next and follows next i times.
            Valid indices are 0 .. Size-1. Index 0 is virtualhead->next, not the dummy.
            Search by value is the same walk: O(n). Update of a known node is O(1) (write val).
            Dummy head / tail make the walk uniform: you never special-case a null first or last pointer.

        3. Insert and delete at a known node are O(1)
            The chain does not have to stay contiguous, so the tail does not shift.
            Insert before node: link new <-> node and new <-> node->prev (four pointers), then Size++.
            Delete node: node->prev <-> node->next, delete node, then Size--.
            addAtHead / addAtTail are this splice against the dummy, so they are O(1) and work on an empty list.
            addAtIndex(i): if i > Size do nothing; if i == Size splice before virtualtail (append); else walk to i and splice before that node.
            Finding the node is still O(n). The O(1) is only the relink after you arrive.

        4. Size is live nodes, not capacity
            No Capacity and no Reallocate. Each insert allocates one node; each delete frees one node.
            Size is the number of real nodes between the dummies. Empty means Size == 0, dummies still exist.
            addAtIndex(Size, val) is a legal tail insert. get / deleteAtIndex reject index >= Size.

        How to choose
            Need frequent insert / delete in the middle (or at both ends) → linked list (relink, no shift).
            Need index access or a compact sequential scan → dynamic array (O(1) address, shift in the middle).
            Need lookup by key, not by position → hash table on top of arrays.
            First write the O(n) walk to the node (brute-force). Dummy head / tail is the structure trade that makes end and empty-list splices the same as the middle case.
