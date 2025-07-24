/*
 * @lc app=leetcode id=521 lang=cpp
 *
 * [521] Longest Uncommon Subsequence I
 */

// @lc code=start
class Solution {
public:
    int findLUSlength(const std::string& a, const std::string& b) {
        return a == b ? -1 : std::max(a.length(), b.length());
    }
};
// @lc code=end
