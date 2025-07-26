/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */

// @lc code=start
class Solution {
public:
    const std::string& shortestCompletingWord(const std::string& licensePlate, const std::vector<std::string>& words) {
        std::array<int, 26> main_hash{}, word_hash;

        for (const char ch : licensePlate) {
            if (std::isalpha(ch)) {
                main_hash[std::tolower(ch) - 'a']++;
            }
        }
        const std::string* res = nullptr;
        int i;

        for (const std::string& word : words) {
            std::fill(word_hash.begin(), word_hash.end(), 0);

            for (const char ch : word) {
                word_hash[ch - 'a']++;
            }
            for (i = 0; i < 26; i++) {
                if (word_hash[i] < main_hash[i]) {
                    break;
                }
            }
            if (i == 26) {
                if (res && res->size() <= word.size()) {
                    continue;
                }
                res = &word;
            }
        }
        return *res;
    }
};
// @lc code=end
