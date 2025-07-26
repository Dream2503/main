/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
class Solution {
public:
    std::string mostCommonWord(const std::string& paragraph, std::vector<std::string>& banned) {
        const int len = paragraph.length();
        std::string word;
        std::unordered_map<std::string, int> hash;
        std::unordered_set<std::string> ban;
        ban.reserve(banned.size());
        ban.insert(std::make_move_iterator(banned.begin()), std::make_move_iterator(banned.end()));
        int i = 0;

        while (i < len) {
            while (i < len && std::isalpha(paragraph[i])) {
                word.push_back(std::tolower(paragraph[i++]));
            }
            if (!word.empty()) {
                hash[std::move(word)]++;
                word.clear();
            }
            i++;
        }
        std::string res;
        int max = 0;

        for (const auto& [word, count] : hash) {
            if (!ban.count(word) && count > max) {
                res = word;
                max = count;
            }
        }
        return res;
    }
};
// @lc code=end
