/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(const std::vector<std::vector<int>>& mat, const int r, const int c) {
        const int m = mat.size(), n = mat[0].size();

        if (r == m && c == n || r * c != m * n) {
            return mat;
        }
        std::vector res(r, std::vector<int>(c));

        for (int i = 0; i < m * n; i++) {
            res[i / c][i % c] = mat[i / n][i % n];
        }
        return res;
    }
};
// @lc code=end
