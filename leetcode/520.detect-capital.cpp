/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(const std::string& word) {
        const int size = word.size();
        int i = 0;
        auto is_upper = [](const char ch) { return ch >= 'A' && ch <= 'Z'; };

        if (is_upper(word[i])) {
            if (is_upper(word[++i])) {
                while (i < size) {
                    if (!is_upper(word[i++])) {
                        return false;
                    }
                }
            } else {
                while (i < size) {
                    if (is_upper(word[i++])) {
                        return false;
                    }
                }
            }
        } else {
            while (i < size) {
                if (is_upper(word[i++])) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
