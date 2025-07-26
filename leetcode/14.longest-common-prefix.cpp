/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        int i = 0;
        std::string res;

        for (const char ch : strs[0]) {
            for (const std::string& element : strs) {
                if (ch != element[i]) {
                    return res;
                }
            }
            res += ch;
            i++;
        }
        return res;
    }
};
// @lc code=end
