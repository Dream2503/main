/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> findWords(const std::vector<std::string>& words) {
        static constexpr std::array<std::string, 3> hash{"eiopqrtuwy", "adfghjkls", "bcmnvxz"};
        std::vector<std::string> res;

        for (const std::string& word : words) {
            const int size = word.size();
            const char ch = std::tolower(word[0]);
            bool broke = false;

            for (int i = 0; i < 3; i++) {
                if (std::binary_search(hash[i].begin(), hash[i].end(), ch)) {
                    for (int j = 1; j < size; j++) {
                        if (!std::binary_search(hash[i].begin(), hash[i].end(), std::tolower(word[j]))) {
                            broke = true;
                            break;
                        }
                    }
                    if (!broke) {
                        res.push_back(std::move(word));
                    }
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
