/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if (x == INT32_MIN) {
            return 0;
        }
        const bool is_negative = x < 0;
        x = is_negative ? -x : x;
        std::vector<int> num(10);
        int len = 0;

        while (x) {
            num[len] = x % 10;
            x /= 10;
            len++;
        }
        for (int i = 0; i < len; i++) {
            if (x > INT32_MAX / 10 || (x == INT32_MAX / 10 && num[i] > INT32_MAX % 10)) {
                return 0;
            }
            x = x * 10 + num[i];
        }
        return is_negative ? -x : x;
    }
};
// @lc code=end
