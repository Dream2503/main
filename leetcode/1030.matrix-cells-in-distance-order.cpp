/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> allCellsDistOrder(const int rows, const int cols, const int rCenter,
                                                    const int cCenter) {
        std::vector<std::vector<int>> res;
        res.reserve(rows * cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.push_back({i, j});
            }
        }
        std::sort(res.begin(), res.end(), [&](const auto& a, const auto& b) {
            return std::abs(a[0] - rCenter) + std::abs(a[1] - cCenter) <
                std::abs(b[0] - rCenter) + std::abs(b[1] - cCenter);
        });
        return res;
    }
};
// @lc code=end
