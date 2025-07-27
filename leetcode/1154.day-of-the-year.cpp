/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 */

// @lc code=start
class Solution {
public:
    int dayOfYear(const std::string& date) {
        static constexpr std::array<int, 12> cumulative_days{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        const int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        const int month = (date[5] - '0') * 10 + (date[6] - '0');
        const int day = (date[8] - '0') * 10 + (date[9] - '0');
        const bool is_leap = (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
        return cumulative_days[month - 1] + day + (is_leap && month > 2);
    }
};
// @lc code=end
