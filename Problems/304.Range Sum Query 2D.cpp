/*
 * @lc app=leetcode id=304 lang=cpp
 * @lcpr version=30404
 *
 * [304] Range Sum Query 2D - Immutable
 */

// Array.md, PrefixSum.md
// Array, PrefixSum

// @lc code=start

#include <vector>
using namespace std;

class NumMatrix 
{
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        sourcematrix = matrix;
        nummatrix =   vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                int top = i == 0 ? 0 : nummatrix[i - 1][j];
                int left = j == 0 ? 0 : nummatrix[i][j - 1];
                int topleft = i == 0 || j == 0 ? 0 : nummatrix[i - 1][j - 1];
                nummatrix[i][j] = top + left - topleft + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int top = row1 == 0 ? 0 : nummatrix[row1 - 1][col2];
        int left = col1 == 0 ? 0 : nummatrix[row2][col1 - 1];
        int topleft = row1 == 0 || col1 == 0 ? 0 : nummatrix[row1 - 1][col1 - 1];
        return nummatrix[row2][col2] - top - left + topleft;
    }
private:
    vector<vector<int>> nummatrix;
    vector<vector<int>> sourcematrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]\n
// @lcpr case=end

 */

