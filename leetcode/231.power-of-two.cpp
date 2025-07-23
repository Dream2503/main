/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(const int &n) { return n > 0 && (INT32_MAX + 1l) % n == 0; }
};
// @lc code=end
