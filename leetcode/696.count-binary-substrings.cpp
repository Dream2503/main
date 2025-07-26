/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(const std::string& s) {
        const int len = s.length();
        int prev = 0, current = 1, cnt = 0;

        for (int i = 1; i < len; i++) {
            if (s[i] == s[i - 1]) {
                current++;
            } else {
                cnt += std::min(prev, current);
                prev = current;
                current = 1;
            }
        }
        return cnt + std::min(prev, current);
    }
};
// @lc code=end
