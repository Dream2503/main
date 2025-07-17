/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(const int dividend, const int divisor) {
        if (dividend == INT32_MIN && divisor == -1) {
            return INT32_MAX;
        }
        if (dividend == INT32_MIN && divisor == 1) {
            return INT32_MIN;
        }
        long a = std::abs(static_cast<long>(dividend));
        const long b = std::abs(static_cast<long>(divisor));
        int result = 0;

        while (a >= b) {
            long temp = b;
            int multiple = 1;

            while (2 * temp <= a) {
                temp *= 2;
                multiple *= 2;
            }
            a -= temp;
            result += multiple;
        }
        if ((dividend > 0) ^ (divisor > 0)) {
            result = -result;
        }
        return result;
    }
};
// @lc code=end
