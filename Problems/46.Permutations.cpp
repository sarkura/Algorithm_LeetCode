/*
 * @lc app=leetcode id=46 lang=cpp
 * @lcpr version=30404
 *
 * [46] Permutations
 */
 
// Recursion.md
// Tree traversal
// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& Nums) {
        vector<vector<int>> Result;
        vector<int> Track = {};
        vector<bool> Used(Nums.size(), false);
        dfs(Nums, Result, Track, Used);
        return Result;
    }   
    void dfs(vector<int>& Nums, vector<vector<int>>& Result, vector<int>& Track, vector<bool>& Used) {
        if (Track.size() == Nums.size()) {
            Result.push_back(Track);
            return;
        }
        for(int i = 0; i < Nums.size(); i++)
        {
            if(Used[i]) continue;
            Track.push_back(Nums[i]);
            Used[i] = true;
            dfs(Nums, Result, Track, Used);
            Track.pop_back();
            Used[i] = false;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

