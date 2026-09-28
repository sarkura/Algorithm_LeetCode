### The Core Concept
    One-open-end perspective
        A stack is a dynamic array (or linked list) that only allows access at one end: the top.
        Data-structure keywords: traversal and access.
        Core actions: insert, delete, search, update.
        Last In, First Out (LIFO). Restricting access to the top is what makes every operation O(1).

        1. Only the top is open
            On a dynamic array, top is index Size - 1. Push is PushBack, pop is PopBack.
            On a linked list, top is the head node. Push is addAtHead, pop is deleteAtIndex(0).
            std::stack is an adapter: by default it wraps std::deque; it can wrap vector or list.
            Empty means Size == 0. top / pop on an empty stack is undefined behavior: check empty() first.

        2. Push, pop, top are O(1)
            Push: construct at Size, then Size++. Amortized O(1) because the array doubles on grow.
            Pop: destroy Size - 1, then Size--. Capacity stays.
            Top: read Size - 1. No shift ever happens, because nothing below the top moves.
            std::stack::pop returns void. Read top() first, then pop().

        3. No middle access
            There is no index, no iterator, no search API. The only view is the top.
            Finding a value means popping until you see it: O(n), and it destroys the stack.
            If you need to look inside, the problem wants a vector used like a stack, not a real stack.

        4. LIFO matches "most recent unfinished thing"
            Matching pairs: brackets, tags. Push on open, pop and compare on close.
            Monotonic stack: keep the stack increasing / decreasing; each element is pushed and popped once, O(n) total.
                Used for next greater element, daily temperatures, largest rectangle in histogram.
            Recursion is an implicit stack (the call stack). DFS can be rewritten iteratively with an explicit stack.
            Reversal: push everything, pop everything, and the order is reversed.

        How to choose
            Need to undo / match / return to the most recent pending item → stack.
            Need First In, First Out → queue (deque restricted to push back, pop front).
            Need both ends → deque.
            First write the O(n) backward scan for each element (brute-force, O(n^2)). The monotonic stack is the space trade that keeps only useful candidates and makes each element O(1) amortized.
