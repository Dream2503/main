/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {

public:
    bool wordPattern(const std::string& pattern, const std::string& s) {
        std::array<std::string_view, 26> hash;
        const int len = s.length();
        int i = 0, j = 0;

        for (const char ch : pattern) {
            if (j >= len) {
                return false;
            }
            while (j < len && s[j] != ' ') {
                j++;
            }
            const auto word = std::string_view(s.data() + i, j - i);

            if (hash[ch - 'a'].empty()) {
                hash[ch - 'a'] = word;
            } else {
                if (hash[ch - 'a'] != word) {
                    return false;
                }
            }
            i = ++j;
        }
        if (j < len) {
            return false;
        }
        std::sort(hash.begin(), hash.end());
        i = 0;

        while (i < 26 && hash[i].empty()) {
            i++;
        }
        for (i = i + 1; i < 26; i++) {
            if (hash[i - 1] == hash[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
