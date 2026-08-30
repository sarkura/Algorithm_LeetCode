/*
 * @lc app=leetcode id=509 lang=cpp
 * @lcpr version=30404
 *
 * [509] Fibonacci Number
 */

// Recursion.md
// decomposition problem

// @lc code=start
class Solution {
public:
    int fib(int n) 
    {
        // dilivery method  (brute-force & Binary Tree) 
        /*if( n == 0 || n == 1)
        {
            return n;
        }
        return fib(n - 1) + fib(n - 2);*/

        // dynamic programming method   (space trade to time & Array)
        /* vector<int> Fib = {0, 1};
        for(int i = 2; i <= n; i++)
        {
            Fib.push_back(Fib[i - 1] + Fib[i - 2]);
        }
        return Fib[n]; */

        // dynamic programming method with space optimization (balanced space & two variables)
        if( n == 0 || n == 1)
            return n;
        int Pre = 0, Next = 1;
        for(int i = 2; i <= n; i++)
        {
            int Temp = Pre + Next;
            Pre = Next;
            Next = Temp;
        }
        return Next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

