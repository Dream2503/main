/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
constexpr std::array<int, 38> get_array() {
    std::array<int, 38> res{};
    res[0] = 0;
    res[1] = 1;
    res[2] = 1;

    for (int i = 3; i < 38; i++) {
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];
    }
    return res;
}
class Solution {
    static constexpr std::array<int, 38> res = get_array();

public:
    int tribonacci(const int n) { return res[n]; }
};
// @lc code=end
