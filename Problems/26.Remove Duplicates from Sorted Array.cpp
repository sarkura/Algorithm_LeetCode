/*
 * @lc app=leetcode id=26 lang=cpp
 * @lcpr version=30404
 *
 * [26] Remove Duplicates from Sorted Array
 */


// Array.md TwoPointer.md
// Array TwoPointer

#include <vector>
using namespace std;

// @lc code=start
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int slow = 0, fast = 0;
        if(nums.size() == 0) 
            return 0;
        for(fast = 0; fast < nums.size(); fast++)
        {
            if(nums[fast] != nums[slow])
            {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */

