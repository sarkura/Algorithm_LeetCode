/*
 * @lc app=leetcode id=48 lang=cpp
 * @lcpr version=30404
 *
 * [48] Rotate Image
 */

// Array.md
// Array

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++) 
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) 
        {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */

