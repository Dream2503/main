/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string res;

        while (columnNumber) {
            columnNumber--;
            res.push_back((columnNumber % 26) + 'A');
            columnNumber /= 26;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
