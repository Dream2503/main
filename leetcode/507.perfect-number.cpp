/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(const int num) {
        // all possible perfect number < INT32_MAX
        return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;
    }
};
// @lc code=end
