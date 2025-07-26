/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */

// @lc code=start
class Solution {
public:
    double largestTriangleArea(const std::vector<std::vector<int>>& points) {
        const int size = points.size();
        double res = 0;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                for (int k = j + 1; k < size; k++) {
                    res = std::max(res, 0.5 * std::abs(points[i][0] * (points[j][1] - points[k][1]) +
                                                             points[j][0] * (points[k][1] - points[i][1]) +
                                                             points[k][0] * (points[i][1] - points[j][1])));
                }
            }
        }
        return res;
    }
};

// @lc code=end
