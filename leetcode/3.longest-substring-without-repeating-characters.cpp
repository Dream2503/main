/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        const int len = s.length();
        int left = 0, right = 1, max = 1;

        if (!len) {
            return 0;
        }
        while (right < len) {
            for (int i = right - 1; i >= left; i--) {
                if (s[i] == s[right]) {
                    left = i + 1;
                    break;
                }
            }
            max = std::max(right - left + 1, max);
            right++;
        }
        return max;
    }
};
// @lc code=end
