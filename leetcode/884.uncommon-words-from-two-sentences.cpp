/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> uncommonFromSentences(const std::string& s1, const std::string& s2) {
        std::vector<std::string> res;
        std::unordered_map<std::string, int> hash;
        std::string word;
        int len = s1.length(), i = 0;

        while (i < len) {
            while (i < len && s1[i] != ' ') {
                word.push_back(s1[i++]);
            }
            hash[std::move(word)]++;
            word.clear();
            i++;
        }
        len = s2.length();
        i = 0;

        while (i < len) {
            while (i < len && s2[i] != ' ') {
                word.push_back(s2[i++]);
            }
            hash[std::move(word)]++;
            word.clear();
            i++;
        }
        for (const auto& [word, count] : hash) {
            if (count == 1) {
                res.push_back(word);
            }
        }
        return res;
    }
};
// @lc code=end
