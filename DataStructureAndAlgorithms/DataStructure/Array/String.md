### The Core Concept
    Character-array perspective
        A string is a dynamic array of char: a contiguous block, a Size (length), and a Capacity.
        Data-structure keywords: traversal and access.
        Core actions: insert, delete, search, update.
        Everything true for a dynamic array is true here; the extra rules are about '\0', copies, and whole-string operations.
        [151] Reverse Words in a String: remove extra spaces in place, reverse the whole string, then reverse each word.

        1. Characters are continuous in memory
            s[i] is at base + i. Walking 0..size()-1 is sequential reads.
            std::string keeps a '\0' after the last char for c_str(); size() does not count it.
            Small strings (about 15 chars) live inside the string object (SSO), no heap allocation.
            char arithmetic works on the code: c - 'a' maps 'a'..'z' to 0..25 (an array of 26 can replace a hash map).

        2. Access by index is O(1), whole-string operations are O(n)
            s[i] read / write is pointer arithmetic, like operator[] on a dynamic array. at(i) checks bounds.
            Compare (==, <), find, substr all walk characters: O(n) or O(k) for length k.
            substr copies into a new string. Calling it inside a loop quietly adds O(n) per iteration.
            Naive find(pattern) is O(n * m). KMP makes it O(n + m).

        3. Insert and delete in the middle are O(n)
            insert / erase at i shift the tail, same as a dynamic array.
            s += c and push_back are amortized O(1). s = s + c builds a new string every time: n appends become O(n^2).
            In-place filtering uses two pointers: fast reads every char, slow writes only the kept ones, then resize(slow).
                [151] removeExtraSpaces: copy each word forward and insert one space between words; O(n) time, O(1) extra space.

        4. Reverse is the core in-place trick
            reverse(begin, end) swaps from both ends toward the middle: O(n) time, O(1) space.
            Reversing the whole string, then each part, reorders the parts without extra memory.
                [151] reverse whole string → reverse each word → words come out in reverse order, each word reads forward.
            The same trick does rotate-by-k: reverse all, reverse [0, k), reverse [k, n).

        How to choose
            Need to edit characters in place → work on the string as a char array with indices / two pointers.
            Need to build a result piece by piece → append with += (or reserve first), not s = s + piece.
            Need to count or look up characters → int[26] / int[128] when the alphabet is small, otherwise a hash table.
            First write the version with split and a new string (brute-force, O(n) extra space). Two pointers and in-place reverse are the trade that removes the extra buffer.
