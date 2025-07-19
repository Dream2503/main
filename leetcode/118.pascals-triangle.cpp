/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> generate(const int numRows) {
        std::vector<std::vector<int>> res(numRows);
        res[0].push_back(1);

        for (int i = 1; i < numRows; i++) {
            res[i].reserve(i + 1);
            res[i].push_back(1);

            for (int j = 1; j < i; j++) {
                res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};
// @lc code=end
