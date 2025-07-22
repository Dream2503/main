/*
 * @lc app=leetcode id=478 lang=cpp
 *
 * [478] Generate Random Point in a Circle
 */

// @lc code=start
class Solution {
    double radius, x_center, y_center;
    const double constant;

public:
    Solution(const double radius, const double x_center, const double y_center) :
        radius(radius), x_center(x_center), y_center(y_center), constant(2 * radius / (RAND_MAX + 1.0)) {}

    std::vector<double> randPoint() {
        const double angle = 2 * M_PI * (static_cast<double>(rand()) / RAND_MAX);
        const double r = std::sqrt(static_cast<double>(rand()) / RAND_MAX) * radius;
        return {x_center + r * cos(angle), y_center + r * sin(angle)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end
