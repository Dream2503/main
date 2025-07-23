/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(const std::string& s, const std::string& t) {
        const int len = s.length();
        char res = 0;

        for (int i = 0; i < len; i++) {
            res ^= s[i];
            res ^= t[i];
        }
        return res ^ t[len];
    }
};
// @lc code=end
