/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(const std::string& s) {
        int num = 0, i = 0;
        bool is_negative = false;

        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            is_negative = true;
            i++;
        } else if (s[i] == '+') {
            is_negative = false;
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9') {
            const char digit = s[i] - '0';

            if (num > INT32_MAX / 10 || (num == INT32_MAX / 10 && digit > INT32_MAX % 10)) {
                if (is_negative) {
                    return INT32_MIN;
                }
                return INT32_MAX;
            }
            num = num * 10 + digit;
            i++;
        }
        return is_negative ? -num : num;
    }
};
// @lc code=end
