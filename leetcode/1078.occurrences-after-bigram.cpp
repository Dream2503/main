/*
 * @lc app=leetcode id=1078 lang=cpp
 *
 * [1078] Occurrences After Bigram
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> findOcurrences(const std::string& text, const std::string& first,
                                            const std::string& second) {
        const int len = text.length();
        int k = 0, i = 0;
        const std::string_view first_view = first, second_view = second;
        std::string_view prev1, prev2;
        std::vector<std::string> res;

        while (i <= len) {
            if (i == len || text[i] == ' ') {
                std::string_view word(text.data() + k, i - k);

                if (prev1 == first_view && prev2 == second_view) {
                    res.emplace_back(std::string(word));
                }
                prev1 = prev2;
                prev2 = word;
                k = i + 1;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
