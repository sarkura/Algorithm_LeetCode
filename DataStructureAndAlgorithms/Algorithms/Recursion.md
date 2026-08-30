### The Core Concept
    Tree perspective
        Recursion is a function calling itself on a smaller input.
        Each call is a node; child calls are branches. The whole process is a tree.
        All recursive algorithms come from brute-force: first draw the tree, then walk it or shrink it.

        1. Brute-force: tree perspective
            Draw the recursion tree first. Every node is one function call; every edge is one recursive step.
            Leaves are base cases. Recursion needs a base case; without it the tree never stops and the stack overflows.
            What the tree shows
                Full brute-force enumerates every node.
                Overlapping subproblems: the same node appears in many subtrees.
                Naive recursion can be exponential in time; stack depth is the height of the tree.
            How to optimize (same tree, less work)
                Memoization: cache each node so a repeated subtree is O(1).
                Bottom-up DP: fill from leaves toward the root (space trade for time).
                Space-optimized DP: keep only the nodes the next step still needs.

        2. Traverse: tree traverse
            Think "I am standing on the current node. What do I do here, then walk the children?"
            Same idea as tree DFS: preorder (enter), inorder, postorder (leave).
            Use when the problem is "visit every state / every node".
            Backtracking is traverse plus undo: choose → recurse → un-choose so sibling branches stay correct.
            No return value is required. Side effects collect the result.

        3. Decomposition: decompose problem to small problem
            Think "what is the answer of this node, given the answers of its children?"
            Define a function that solves the whole problem, call it on smaller pieces, then combine.
            Use when the problem has a clear recurrence.
            Difference from traverse
                Traverse: walk the tree, do work at each node, often no return.
                Decomposition: each call returns a result; parent builds its answer from children.
            Postorder is the natural order: children must finish before the parent can combine.

        How to choose
            First draw the recursion tree (brute-force).
            If you only need to visit every path or state → traverse (plus undo if backtracking).
            If the parent answer is built from child answers → decomposition.
            If the tree has overlapping nodes → add memo / switch to DP.
