/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    std::string& reverseWords(std::string& s) {
        const int len = s.length();
        int i = 0, j = 0;

        while (j < len) {
            while (j < len && s[j] != ' ') {
                j++;
            }
            std::reverse(s.begin() + i, s.begin() + j);
            i = ++j;
        }
        return s;
    }
};
// @lc code=end
