/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> letterCombinations(const std::string& digits) {
        static constexpr std::array<std::string, 8> codes = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector res(1, std::string(digits.size(), 'K'));
        int i = 0;

        if (digits.empty()) {
            return {};
        }
        for (const char ch : digits) {
            const int idx = ch - '0' - 2, size = codes[idx].length(), res_size = res.size();
            std::vector<std::string> temp;
            temp.reserve(res_size * size);

            for (std::string& element : res) {
                temp.insert(temp.end(), size, element);
            }
            res = std::move(temp);
            int j = 0;

            for (std::string& s : res) {
                s[i] = codes[idx][j];
                j = (j + 1) % size;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
