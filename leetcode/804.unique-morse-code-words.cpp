/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
class Solution {
public:
    int uniqueMorseRepresentations(const std::vector<std::string>& words) {
        static constexpr std::array<std::string, 26> morse{
            ".-", "-...", "-.-.", "-..",  ".",   "..-.", "--.", "....", "..",   ".---", "-.-",  ".-..", "--",
            "-.", "---",  ".--.", "--.-", ".-.", "...",  "-",   "..-",  "...-", ".--",  "-..-", "-.--", "--.."};
        std::unordered_set<std::string> unique;
        std::string code;

        for (const std::string& word : words) {
            for (const char ch : word) {
                code += morse[ch - 'a'];
            }
            unique.insert(std::move(code));
            code.clear();
        }
        return unique.size();
    }
};
// @lc code=end
