/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(const int n) {
        if (n == 1) {
            return n;
        }
        int prev = 1, current = 1;

        for (int i = 2; i <= n; i++) {
            const int temp = current;
            current = prev + current;
            prev = temp;
        }
        return current;
    }
};
// @lc code=end
