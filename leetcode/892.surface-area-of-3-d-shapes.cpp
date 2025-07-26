/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 */

// @lc code=start

class Solution {
public:
    int surfaceArea(const std::vector<std::vector<int>>& grid) {
        const int size = grid.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j]) {
                    res += 2;

                    const int up = (i == 0) ? 0 : grid[i - 1][j];
                    res += std::max(grid[i][j] - up, 0);

                    const int left = (j == 0) ? 0 : grid[i][j - 1];
                    res += std::max(grid[i][j] - left, 0);

                    const int down = (i == size - 1) ? 0 : grid[i + 1][j];
                    res += std::max(grid[i][j] - down, 0);

                    const int right = (j == size - 1) ? 0 : grid[i][j + 1];
                    res += std::max(grid[i][j] - right, 0);
                }
            }
        }
        return res;
    }
};
// @lc code=end
