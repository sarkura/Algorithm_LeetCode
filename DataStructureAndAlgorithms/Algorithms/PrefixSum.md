### The Core Concept
    Decomposition perspective
        Prefix sum is divide-and-conquer on an immutable range query.
        Brute-force: walk every element in the interval on each query.
        Decompose: the interval answer is a combination of a few origin-to-here subproblem answers.
        The array does not change, so those subproblems can be cached once. Query time becomes O(1).
        Same idea as Recursion decomposition: parent answer is built from child answers; here the children are prefixes, combined by + / -.

        1. What is being decomposed
            A range is not a new walk. It is a large prefix minus a smaller prefix (and, in 2D, extra strips).
            Define a function that answers "sum from the origin to this cell", then build any query from those answers.
            Overlapping subproblems: many queries share the same origin prefixes. Cache them in an array.
            Space trade for time: one preprocess pass, then each query is a constant number of lookups.

        2. 1D range: [303] Range Sum Query - Immutable
            Subproblem: prefix[i] = sum of [0..i].
            Recurrence: prefix[i] = prefix[i - 1] + nums[i].
            Combine: sum(left, right) = prefix[right] - prefix[left - 1].
            If the prefix array is not padded at 0, that is prefix[right] - prefix[left] + nums[left].
            Brute-force scans [left, right]. Decomposition uses two (or three) prefix values.

        3. 2D range: [304] Range Sum Query 2D - Immutable
            Subproblem: prefix[i][j] = sum of the rectangle [0..i] × [0..j].
            Recurrence: prefix[i][j] = top + left - topleft + matrix[i][j].
            Top and left both contain the top-left rectangle, so subtract it once (inclusion-exclusion).
            Combine: sumRegion(r1, c1, r2, c2)
                = prefix[r2][c2] - top strip - left strip + top-left corner.
            The corner was subtracted twice, so add it back.
            2D is the same 1D split, applied on both axes.

        How to think
            First write the nested sum (brute-force, correctness).
            Ask which origin prefixes are shared; precompute them; query = a few +/-.
            1D: one cut (right prefix minus left prefix).
            2D: two cuts (bottom-right minus extra top minus extra left plus overlap).
            Use when the data is immutable and range sum is queried many times.
            If the data mutates, prefix alone is not enough (need Fenwick / segment tree).
