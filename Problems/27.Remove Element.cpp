/*
 * @lc app=leetcode id=27 lang=cpp
 * @lcpr version=30404
 *
 * [27] Remove Element
 */


// Array.md TwoPointer.md
// Array TwoPointer

#include <vector>
using namespace std;
// @lc code=start
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            if (nums[start] == val)
            {
                nums[start] = nums[end];
                end--;
            }
            else
            {
                start++;
            }
        }

        return start;
    }
};
// @lc code=end
