/*
 * @lc app=leetcode id=303 lang=cpp
 * @lcpr version=30404
 *
 * [303] Range Sum Query - Immutable
 */

// Array.md, PrefixSum.md
// Array, PrefixSum

// @lc code=start

#include <vector>
using namespace std;

class NumArray 
{
public:
    NumArray(vector<int>& nums) 
    {
        newnums = nums;
        subnums.resize(nums.size());
        int subnum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            subnum += nums[i];
            subnums[i] = subnum;
        }
    }
    
    int sumRange(int left, int right) 
    {
        return subnums[right] - subnums[left] + newnums[left];
    }
private:
    vector<int> subnums;
    vector<int> newnums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

// 1 3 6 -2 -6 -2 8
// 1 4 10 8 2 0 8

// (0 2)
// 10 - 1 + 1 = 10

// (3 6)
// 8 - 8 + -2 = -2




/*
// @lcpr case=start
// ["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]\n
// @lcpr case=end

 */

