/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */

// @lc code=start
class Solution {
public:
    std::string& toLowerCase(std::string& s) {
        for (char& ch : s) {
            ch += (ch >= 'A' && ch <= 'Z') * 32;
        }
        return s;
    }
};
// @lc code=end
