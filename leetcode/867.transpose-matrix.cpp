/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> res(column, vector<int>(row));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};
// @lc code=end

