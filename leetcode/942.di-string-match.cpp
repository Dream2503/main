/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */

// @lc code=start
class Solution {
public:
    std::vector<int> diStringMatch(const std::string& s) {
        const int len = s.length();
        int low = 0, high = len;
        std::vector<int> res;
        res.reserve(len + 1);

        for (const char ch : s) {
            if (ch == 'I') {
                res.push_back(low++);
            } else {
                res.push_back(high--);
            }
        }
        res.push_back(low);
        return res;
    }
};
// @lc code=end
