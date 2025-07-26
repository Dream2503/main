/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(const std::string& s) {
        static const std::vector<std::pair<std::string, int>> roman = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50},
            {"XL", 40},  {"X", 10},   {"IX", 9},  {"V", 5},    {"IV", 4},  {"I", 1}};
        const int len = s.length();
        int res = 0, i = 0;

        for (const auto& [symbol, value] : roman) {
            while (symbol.length() == 1 && i < len && s[i] == symbol[0]) {
                res += value;
                i++;
            }
            while (symbol.length() == 2 && i < len - 1 && s.substr(i, 2) == symbol) {
                res += value;
                i += 2;
            }
        }
        return res;
    }
};
// @lc code=end
