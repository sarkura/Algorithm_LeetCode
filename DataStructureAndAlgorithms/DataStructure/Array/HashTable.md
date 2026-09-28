### The Core Concept
    Key-to-index perspective
        A hash table is an array of buckets plus a hash function that turns a key into a bucket index.
        Data-structure keywords: traversal and access.
        Core actions: insert, delete, search, update.
        The array gives O(1) address access; the hash function turns "find by key" into "access by index".
        [1] Two Sum: unordered_map from value to index, so "does target - nums[i] exist" is one lookup, not a scan.

        1. Key maps to a bucket index
            index = hash(key) % BucketCount. The same key always lands in the same bucket.
            The table is still a contiguous array underneath; the key is not stored at a fixed offset, the hash picks it.
            Keys must be hashable and comparable for equality. Order of keys is not preserved (unordered).
            A good hash spreads keys evenly; a bad one piles keys into a few buckets.

        2. Access by key is O(1) on average
            Search: hash the key, go to the bucket, compare keys inside it.
            Insert / update: find the bucket, overwrite if the key exists, otherwise add a new entry.
            Delete: find the entry and remove it from the bucket.
            Worst case is O(n) when all keys collide into one bucket.
            operator[] on unordered_map inserts a default value when the key is missing. Use find / count to only check.

        3. Collisions must be resolved
            Two different keys can hash to the same bucket.
            Chaining: each bucket holds a linked list of entries (std::unordered_map does this).
            Open addressing: probe to the next free slot (linear / quadratic probing); delete needs a tombstone mark.
            Either way, cost per operation is proportional to how many entries share the bucket.

        4. Load factor drives rehash
            Load factor = Size / BucketCount. When it passes the limit (about 1.0 for unordered_map), the table rehashes.
            Rehash: allocate a bigger bucket array (about 2 times) → rehash every entry into its new bucket → free the old array.
            A single rehash is O(n); like dynamic-array doubling, it is amortized O(1) per insert.
            Rehash invalidates iterators. reserve(n) up front avoids repeated rehash when n is known.

        How to choose
            Need lookup / dedup / counting by key, order does not matter → hash table (unordered_map / unordered_set).
            Need keys in sorted order or range queries → balanced tree (map / set), O(log n).
            Need access by position → dynamic array.
            First write the O(n) scan for each element (brute-force, O(n^2) total). The hash table is the space trade that caches seen keys and makes each lookup O(1).
