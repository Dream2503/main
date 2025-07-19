/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    std::vector<int> getRow(const int rowIndex) {
        auto comb = [](const int n, int r) -> int {
            if (r > n - r) {
                r = n - r;
            }
            long res = 1;

            for (int i = 0; i < r; i++) {
                res *= n - i;
                res /= i + 1;
            }
            return static_cast<int>(res);
        };
        std::vector<int> res;
        res.reserve(rowIndex + 1);

        for (int i = 0; i <= rowIndex; i++) {
            res.push_back(comb(rowIndex, i));
        }
        return res;
    }
};
// @lc code=end
