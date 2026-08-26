/*
 * @lc app=leetcode id=1 lang=cpp
 * @lcpr version=30404
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> HashMap = {};
        int N = nums.size();
        for(int i = 0; i < N; i++)
        {
            HashMap[nums[i]] = i;
        }
        vector<int> Ans = {};
        for(int i = 0; i < N; i++)
        {
            int HashMapData = target - nums[i];
            if(HashMap.find(HashMapData) != HashMap.end() && HashMap[HashMapData] != i)
            {
                Ans.push_back(i);
                Ans.push_back(HashMap[HashMapData]);
                break;
            }
        }
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

