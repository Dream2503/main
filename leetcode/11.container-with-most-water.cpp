/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;

        while (i < j) {
            const int current = std::min(height[i], height[j]) * (j - i);

            if (current > res) {
                res = current;
            }
            height[i] < height[j] ? i++ : j--;
        }
        return res;
    }
};
// @lc code=end
