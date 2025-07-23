/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(const int n) { return static_cast<int>((-1 + std::sqrt(1.0 + 8.0 * n)) / 2); }
    // x * (x + 1) / 2 = n
};
// @lc code=end
