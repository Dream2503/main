/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int size = grid.size(), res = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j]) {
                    res += 2;

                    if (i == 0) {
                        res += grid[i][j];
                    } else if (grid[i][j] - grid[i - 1][j] > 0) {
                        res += grid[i][j] - grid[i - 1][j];
                    }

                    if (j == 0) {
                        res += grid[i][j];
                    } else if (grid[i][j] - grid[i][j - 1] > 0) {
                        res += grid[i][j] - grid[i][j - 1];
                    }

                    if (i == size - 1) {
                        res += grid[i][j];
                    } else if (grid[i][j] - grid[i + 1][j] > 0) {
                        res += grid[i][j] - grid[i + 1][j];
                    }

                    if (j == size - 1) {
                        res += grid[i][j];
                    } else if (grid[i][j] - grid[i][j + 1] > 0) {
                        res += grid[i][j] - grid[i][j + 1];
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

