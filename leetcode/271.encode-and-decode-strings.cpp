/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    std::string encode(const std::vector<std::string>& strs) {
        std::string res;

        for (const std::string& str : strs) {
            res += str;
            res.push_back(-1);
        }
        return res;
    }

    std::vector<std::string> decode(const std::string& s) {
        std::vector<std::string> res;
        std::string current;

        for (const char ch : s) {
            if (ch == -1) {
                res.push_back(std::move(current));
                current.clear();
            } else {
                current.push_back(ch);
            }
        }
        return res;
    }
};
// @lc code=end
