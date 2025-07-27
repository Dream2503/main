/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
public:
    std::string& gcdOfStrings(std::string& str1, const std::string& str2) {
        if (str1 + str2 != str2 + str1) {
            str1.clear();
        } else {
            str1.resize(std::gcd(str1.size(), str2.size()));
        }
        return str1;
    }
};
// @lc code=end
