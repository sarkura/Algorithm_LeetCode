### The Core Concept
    Shrink perspective
        Two pointers is a shrink of a nested scan into one pass.
        Brute-force: for each element, shift or rescan the rest of the array.
        Shrink: two indices move only one way. Each element is read a constant number of times.
        The result is written in place. Extra space stays O(1). Time becomes O(n).
        Same idea as Brute-force shrink: a smaller slice still covers the answer, so skip the full nested search.

        1. What is being shrunk
            The inner loop is the waste: erase shifts the tail, or a second scan looks for a match.
            Same direction: fast reads every element, slow writes only the kept ones. slow stays at or behind fast.
            Prefix [0, slow) is finished. The open gap is what fast has already rejected.
            Opposite direction: left and right walk toward each other. Outside that range is finished.
            They stop when they meet or cross. The unfinished slice only shrinks.
            State the invariant before the loop: what is already correct on each side of the pointers.

        2. Same direction, keep order: [26] [283] [83]
            A keep / drop rule, or a sorted run of duplicates, lets one forward scan find the next kept element.
            [26] Remove Duplicates from Sorted Array: slow is the last unique value.
                If nums[fast] != nums[slow], slow++, then write nums[fast] there.
                Return slow + 1. Empty input returns 0. Duplicates sit together because the array is sorted.
            [283] Move Zeroes: same write, keep non-zeros. Then set [slow, n) to 0.
                Non-zero order stays. The second loop only fills the hole the first loop left.
            [83] Remove Duplicates from Sorted List: slow is the last kept node, fast is slow->next.
                Equal: unlink fast, delete it, fast = slow->next. Different: both move forward one node.
            Brute-force erase shifts every tail element. Here each kept element is written once.

        3. Opposite direction, order may change: [27] Remove Element
            The kept values may be reordered, so a hole can be filled from the tail.
            start walks from the left, end from the right, while start <= end.
            If nums[start] == val, copy nums[end] onto start and end--. Leave start where it is: the copy may also be val.
            Else start++.
            Return start. That is the new length. Values past end are discarded.
            Brute-force erase at each val shifts the middle. This writes the two ends and leaves the middle still.
            Same family as reverse: swap inward from both ends ([151] reverse a range).

        How to think
            First write the nested erase or the second scan (brute-force, correctness).
            Ask whether relative order must survive.
            Keep order → same direction: fast reads, slow writes the kept prefix.
            Order may change → opposite ends: overwrite the rejected slot from the tail and shrink.
            Sorted pair with a target sum → opposite ends, move the side that misses the target.
            Use when one keep / drop / match rule covers every element, and each index moves only one way.
            If both ends must grow and shrink under a window constraint, that is a sliding window on the same two indices.
