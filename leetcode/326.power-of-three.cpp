/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
constexpr int INT_POWER_3_MAX = 1162261467;

class Solution {
public:
    bool isPowerOfThree(const int n) { return n > 0 && INT_POWER_3_MAX % n == 0; }
};
// @lc code=end
