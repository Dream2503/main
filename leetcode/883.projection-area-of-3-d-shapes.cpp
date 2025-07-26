/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */

// @lc code=start
class Solution {
public:
    int projectionArea(const std::vector<std::vector<int>>& grid) {
        const int size = grid.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            int max = 0;
            res += *std::max_element(grid[i].begin(), grid[i].end());

            for (int j = 0; j < size; j++) {
                max = std::max(max, grid[j][i]);

                if (grid[j][i]) {
                    res++;
                }
            }
            res += max;
        }
        return res;
    }
};
// @lc code=end
