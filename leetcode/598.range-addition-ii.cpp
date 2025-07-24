/*
 * @lc app=leetcode id=598 lang=cpp
 *
 * [598] Range Addition II
 */

// @lc code=start
class Solution {
public:
    int maxCount(const int m, const int n, const std::vector<std::vector<int>>& ops) {
        int row = m, column = n;

        for (const std::vector<int>& element : ops) {
            row = min(row, element[0]);
            column = min(column, element[1]);
        }
        return row * column;
    }
};
// @lc code=end
