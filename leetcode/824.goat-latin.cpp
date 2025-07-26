/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
class Solution {
public:
    std::string toGoatLatin(const std::string& sentence) {
        const int len = sentence.length();
        std::string res, word, end = "maa";
        res.reserve(len);
        int i = 0;
        auto is_vowel = [](const char ch) { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; };

        while (i < len) {
            char x = 0;

            if (!is_vowel(std::tolower(sentence[i]))) {
                x = sentence[i++];
            }
            while (i < len && sentence[i] != ' ') {
                word.push_back(sentence[i++]);
            }
            if (x) {
                word.push_back(x);
            }
            word += end;
            end.push_back('a');
            res += word;
            res.push_back(' ');
            word.clear();
            i++;
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
