/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(const std::string& s) {
        const std::string doubled = s + s;
        const auto substr = std::string_view(doubled.data() + 1, doubled.size() - 2);
        return substr.find(s) != std::string_view::npos;
    }
};
// @lc code=end
