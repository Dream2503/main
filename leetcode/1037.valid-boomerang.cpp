/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 */

// @lc code=start
class Solution {
public:
    bool isBoomerang(const std::vector<std::vector<int>>& points) {
        return (points[1][0] - points[0][0]) * (points[2][1] - points[0][1]) -
            (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]); // AB x AC = Xab * Yac - Yab * Xac
    }
};
// @lc code=end
