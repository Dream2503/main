/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
public:
    std::string toHex(const int num) {
        if (!num) {
            return "0";
        }
        std::string res;
        unsigned int u_num = static_cast<unsigned int>(num);

        while (u_num) {
            const int temp = u_num & 0xF;
            res.push_back(temp >= 10 ? 'a' - 10 + temp : temp + '0');
            u_num >>= 4;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
