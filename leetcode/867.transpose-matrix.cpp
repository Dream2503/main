/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
        const int row = matrix.size(), column = matrix[0].size();
        std::vector res(column, std::vector(row, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
