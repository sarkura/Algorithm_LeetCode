/*
 * @lc app=leetcode id=1109 lang=cpp
 * @lcpr version=30404
 *
 * [1109] Corporate Flight Bookings
 */

// Array.md, DifferenceArray.md
// Array, Difference Array

// @lc code=start

#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        vector<int> difference(n, 0);

        for (auto &booking : bookings) 
        {
            int startingIndex = booking[0] - 1;
            difference[startingIndex] += booking[2];
            int endingIndex = startingIndex + booking[1] - booking[0] + 1;
            if (endingIndex >= startingIndex && endingIndex < n) 
            {
                difference[endingIndex] -= booking[2];
            }
        }
        vector<int> result(n, 0);
        
        for (int i = 0; i < n; i++) 
        {
            if (i == 0)
            {
                result[i] = difference[i];
            }
            else 
            {
                result[i] = result[i - 1] + difference[i];
            }
        }
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,10],[2,3,20],[2,5,25]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,10],[2,2,15]]\n2\n
// @lcpr case=end

 */

