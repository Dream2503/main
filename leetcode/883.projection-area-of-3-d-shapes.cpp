/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int size = grid.size(), res = 0, max;

        for (int i = 0; i < size; i++) {
            max = 0;
            res += *max_element(grid[i].begin(), grid[i].end());

            for (int j = 0; j < size; j++) {
                if (max < grid[j][i]) {
                    max = grid[j][i];
                }
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

