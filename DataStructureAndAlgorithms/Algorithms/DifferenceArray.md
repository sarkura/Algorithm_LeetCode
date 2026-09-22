### The Core Concept
    Decomposition perspective
        Difference array is divide-and-conquer on a range update.
        Brute-force: walk every element in the interval on each update.
        Decompose: a range add is two boundary writes; the final array is the prefix of those diffs.
        Same idea as Recursion decomposition: parent answer is built from child answers.
        Here the children are the start mark and the end mark, combined later by a prefix walk.
        Difference is the inverse of prefix sum: prefix answers many range queries; difference absorbs many range updates.

        1. What is being decomposed
            A range add is not a new walk. It is +val at left and -val just after right.
            Define a function that answers "how much the value changes from the previous index", then rebuild nums by prefix.
            Recurrence: diff[0] = nums[0], diff[i] = nums[i] - nums[i - 1].
            Recover: nums[i] = nums[i - 1] + diff[i] (prefix of the difference array).
            Overlapping updates: many intervals share the same cells. Do not touch those cells until one reconstruct pass.
            Space trade for time: each update is O(1); one O(n) prefix pass after all updates.

        2. 1D range: [1109] Corporate Flight Bookings
            Update [left, right] += val: diff[left] += val, and if right + 1 is in range, diff[right + 1] -= val.
            The -val stops the add from leaking past right. If right is the last index, skip the minus.
            Combine: result[i] = result[i - 1] + diff[i] (result[0] = diff[0]).
            Brute-force writes every seat in [first, last]. Decomposition writes two slots per booking, then one prefix.

        3. 2D range: inverse of [304] Range Sum Query 2D
            Update rectangle [r1..r2] × [c1..c2] += val by four corners (inclusion-exclusion).
            diff[r1][c1] += val, diff[r1][c2 + 1] -= val, diff[r2 + 1][c1] -= val, diff[r2 + 1][c2 + 1] += val.
            The last +val puts back the corner that was subtracted twice.
            Recover with a 2D prefix: cell = top + left - topleft + diff[i][j].
            2D is the same 1D split, applied on both axes.

        How to think
            First write the nested range add (brute-force, correctness).
            Ask which interval updates can be delayed; mark boundaries; reconstruct with prefix.
            1D: two marks (start plus, end-plus-one minus).
            2D: four marks (same inclusion-exclusion as 2D prefix, reversed).
            Use when the data gets many range updates and you need the final array (or few reconstructions).
            Use prefix when the data stays still and you need many range sums.
            If you must mix frequent updates and frequent queries, difference / prefix alone is not enough (Fenwick / segment tree).
