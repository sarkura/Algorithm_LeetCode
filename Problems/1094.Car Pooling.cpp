/*
 * @lc app=leetcode id=1094 lang=cpp
 * @lcpr version=30404
 *
 * [1094] Car Pooling
 */

// Array.md, DifferenceArray.md
// Array, Difference Array
// @lc code=start

#include <vector>
using namespace std;

class Solution 
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<int> difference(1001, 0);
        for(auto &trip : trips)
        {
            int startingIndex = trip[1];
            int endingIndex = trip[2];
            difference[startingIndex] += trip[0];
            difference[endingIndex] -= trip[0];
        }
        int currentCapacity = 0;
        for(int i = 0; i < 1001; i++)
        {
            currentCapacity += difference[i];
            if(currentCapacity > capacity)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,5],[3,3,7]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,5],[3,3,7]]\n5\n
// @lcpr case=end

 */

