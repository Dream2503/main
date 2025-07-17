/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    std::vector<int> findSubstring(const std::string& s, const std::vector<std::string>& words) {
        std::vector<int> result;
        if (words.empty() || s.empty()) {
            return result;
        }
        const int word_len = words[0].size(), total_words = words.size(), total_len = word_len * total_words;
        std::unordered_map<std::string, int> word_count;

        if (s.size() < total_len) {
            return result;
        }
        for (const std::string& word : words) {
            word_count[word]++;
        }
        for (int offset = 0; offset < word_len; offset++) {
            int left = offset;
            int count = 0;
            std::unordered_map<std::string, int> window;

            for (int right = offset; right + word_len <= s.size(); right += word_len) {
                std::string word = s.substr(right, word_len);

                if (word_count.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > word_count[word]) {
                        std::string left_word = s.substr(left, word_len);
                        window[left_word]--;
                        left += word_len;
                        count--;
                    }
                    if (count == total_words) {
                        result.push_back(left);
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + word_len;
                }
            }
        }
        return result;
    }
};
// @lc code=end
