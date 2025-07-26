/*
 * @lc app=leetcode id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 */

// @lc code=start
class Solution {
public:
    std::vector<int> numberOfLines(const std::vector<int>& widths, const std::string& s) {
        std::vector res(2, 0);

        for (const char ch : s) {
            res[1] += widths[ch - 'a'];

            if (res[1] > 100) {
                res[1] = widths[ch - 'a'];
                res[0]++;
            }
        }
        res[0]++;
        return res;
    }
};
// @lc code=end
