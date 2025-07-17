/*
 * @lc app=leetcode id=3136 lang=cpp
 *
 * [3136] Valid Word
 */

// @lc code=start
class Solution {
public:
    bool isValid(const std::string& word) {
        if (word.length() < 3) {
            return false;
        }
        bool vowel = false, consonant = false;

        for (char ch : word) {
            if (ch == '@' || ch == '#' || ch == '$') {
                return false;
            }
            ch = std::tolower(ch);

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowel = true;
            } else if (ch < '0' || ch > '9') {
                consonant = true;
            }
        }
        return vowel && consonant;
    }
};
// @lc code=end
