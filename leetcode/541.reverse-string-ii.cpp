/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    std::string& reverseStr(std::string& s, const int k) {
        const int len = s.length();
        int i = 0;

        while (i < len) {
            if (i + k - 1 < len) {
                std::reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
            i += 2 * k;
        }
        return s;
    }
};
// @lc code=end
