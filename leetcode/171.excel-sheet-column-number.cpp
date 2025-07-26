/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(const std::string& columnTitle) {
        int res = 0;

        for (const char ch : columnTitle) {
            res = res * 26 + (ch - 'A' + 1);
        }
        return res;
    }
};
// @lc code=end
