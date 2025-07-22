/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
constexpr std::array<int, 31> get_array() {
    std::array<int, 31> res{};
    res[0] = 0;
    res[1] = 1;

    for (int i = 2; i < 31; i++) {
        res[i] = res[i - 1] + res[i - 2];
    }
    return res;
}
class Solution {
    static constexpr std::array<int, 31> res = get_array();

public:
    int fib(const int n) { return res[n]; }
};
// @lc code=end
