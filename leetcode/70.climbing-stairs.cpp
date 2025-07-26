/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
constexpr std::array<int, 46> get_array() {
    std::array<int, 46> res{};
    res[0] = 1;
    res[1] = 1;

    for (int i = 2; i < 46; i++) {
        res[i] = res[i - 1] + res[i - 2];
    }
    return res;
}

class Solution {
    constexpr static std::array<int, 46> res = get_array();

public:
    int climbStairs(const int n) { return res[n]; }
};
// @lc code=end
