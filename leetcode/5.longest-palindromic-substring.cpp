/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    std::string longestPalindrome(const std::string& s) {
        const int len = s.length();
        int start = 0, max_len = 1;

        auto expand = [&](int left, int right) -> void {
            while (left >= 0 && right < len && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > max_len) {
                start = left + 1;
                max_len = right - left - 1;
            }
        };
        for (int i = 0; i < len; i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(start, max_len);
    }
};
// @lc code=end
