/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution {
    std::array<int, 26> dict{};

public:
    bool isAlienSorted(const std::vector<std::string>& words, const std::string& order) {
        for (int i = 0; i < 26; i++) {
            dict[order[i] - 'a'] = i;
        }

        return std::is_sorted(words.begin(), words.end(), [this](const std::string& str1, const std::string& str2) {
            return std::lexicographical_compare(
                str1.begin(), str1.end(), str2.begin(), str2.end(),
                [this](const char a, const char b) { return dict[a - 'a'] < dict[b - 'a']; });
        });
    }
};
// @lc code=end
