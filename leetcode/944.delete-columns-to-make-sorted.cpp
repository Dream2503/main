/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(const std::vector<std::string>& strs) {
        const int row = strs.size() - 1, column = strs[0].size();
        int res = 0;

        for (int j = 0; j < column; j++) {
            for (int i = 0; i < row; i++) {
                if (strs[i][j] > strs[i + 1][j]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
