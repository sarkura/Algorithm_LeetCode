/*
 * @lc app=leetcode id=283 lang=cpp
 * @lcpr version=30404
 *
 * [283] Move Zeroes
 */
// Array.md TwoPointer.md
// Array TwoPointer

#include <vector>
using namespace std;

// @lc code=start
class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++)
        {
            if(nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        for(int i = slow; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

