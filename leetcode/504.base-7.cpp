/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
class Solution {
public:
    std::string convertToBase7(int num) {
        if (!num) {
            return "0";
        }
        const bool neg = num < 0;

        if (neg) {
            num = -num;
        }
        std::string res;

        while (num) {
            res += num % 7 + '0';
            num /= 7;
        }
        if (neg) {
            res += '-';
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
