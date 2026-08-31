### The Core Concept
    Enumeration perspective
        Brute-force is enumerating every possible state until the answer is covered.
        All algorithms come from brute-force.
        First write the full enumeration (correctness), then cut waste (time and space).
        To optimize time and space, an algorithm uses a different structure or a different thought on the same search.

        1. What brute-force does
            List every candidate or every decision; stop only when the space is fully covered or the answer is found.
            Nested loops, recursion, and backtracking are all brute-force if they walk the full space.
            Completeness first: a wrong but fast method is useless; a slow but complete method is the baseline.

        2. The search tree
            Each choice is a branch; the whole process is a tree (same tree as Recursion).
            Root is the empty / initial state. Each edge is one decision. Leaves are complete answers or dead ends.
            Full brute-force visits every node. Time is the number of nodes; stack or extra arrays are the space.
            The tree is often exponential or factorial. Repeated nodes and hopeless branches are the usual waste.

        3. How to optimize (same tree, less work)
            Prune: skip a branch as soon as it cannot lead to a valid answer.
            Cache: overlapping nodes → memo / DP, so a repeated subtree is O(1).
            Structure: faster access or order (hash lookup, sort, heap) so each step costs less.
            Shrink: do not walk the whole tree (two pointers, binary search, greedy) when a smaller slice still covers the answer.
            Trade: extra space to save time, or drop unused space after the recurrence is clear.

        How to think
            First draw or write the full enumeration (the tree or the nested loops).
            Ask where the waste is: repeated nodes, dead branches, slow lookup, extra copies.
            Then apply one cut: prune, cache, better structure, or a smaller search.
            Recursion / backtracking is how you walk the tree; DP / greedy / binary search is how you shrink it.
