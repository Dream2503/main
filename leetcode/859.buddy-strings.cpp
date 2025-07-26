/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(const std::string& s, const std::string& goal) {
        const int len = s.length();
        int i = 0;

        if (len != goal.size()) {
            return false;
        }
        while (i < len && s[i] == goal[i]) {
            i++;
        }
        const int k = i++;

        if (k >= len) {
            std::array<int, 26> hash{};

            for (const char ch : s) {
                if (++hash[ch - 'a'] > 1) {
                    return true;
                }
            }
            return false;
        }
        while (i < len && s[i] == goal[i]) {
            i++;
        }
        if (i < len) {
            return s[k] == goal[i] && s[i] == goal[k] &&
                std::string_view(s).substr(i + 1) == std::string_view(goal).substr(i + 1) &&
                std::string_view(s).substr(0, k) == std::string_view(goal).substr(0, k);
        }
        return false;
    }
};
// @lc code=end
