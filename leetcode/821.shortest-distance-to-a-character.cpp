/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
class Solution {
public:
    std::vector<int> shortestToChar(const std::string& s, const char c) {
        const int len = s.length();
        int i = INT32_MAX, j = s.find(c);
        std::vector<int> res;
        res.reserve(len);

        for (int k = 0; k < len; k++) {
            if (s[k] != c) {
                res.push_back(std::min(std::abs(k - i), std::abs(j - k)));
            } else {
                i = j;
                j = s.find(c, j + 1);
                res.push_back(0);
            }
        }
        return res;
    }
};
// @lc code=end
