/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(const std::vector<std::vector<int>>& grid) {
        const int row = grid.size(), col = grid[0].size();
        int res = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
                    if (i - 1 < 0 || !grid[i - 1][j]) {
                        res++;
                    }
                    if (i + 1 == row || !grid[i + 1][j]) {
                        res++;
                    }
                    if (j - 1 < 0 || !grid[i][j - 1]) {
                        res++;
                    }
                    if (j + 1 == col || !grid[i][j + 1]) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
