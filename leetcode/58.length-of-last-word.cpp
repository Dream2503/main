/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(const std::string& s) {
        int res = 0, i = s.length() - 1;

        while (s[i] == ' ') {
            i--;
        }
        while (i >= 0) {
            if (s[i] == ' ') {
                return res;
            }
            res++;
            i--;
        }
        return res;
    }
};
// @lc code=end
