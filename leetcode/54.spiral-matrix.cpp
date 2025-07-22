/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        char direction = 'r';
        int i = 0, j = 0, edge[4] = {0, 1, m, n}; // {left, up, down, right}
        std::vector<int> res;
        res.reserve(m * n);

        while (true) {
            res.push_back(matrix[i][j]);

            switch (direction) {
            case 'r':
                if (j + 1 < edge[3]) {
                    j++;
                } else {
                    direction = 'd';
                    edge[3]--;
                    i++;

                    if (i == edge[2]) {
                        return res;
                    }
                }
                break;

            case 'd':
                if (i + 1 < edge[2]) {
                    i++;
                } else {
                    direction = 'l';
                    edge[2]--;
                    j--;

                    if (j == edge[0] - 1) {
                        return res;
                    }
                }
                break;

            case 'l':
                if (j - 1 >= edge[0]) {
                    j--;
                } else {
                    direction = 'u';
                    edge[0]++;
                    i--;

                    if (i == edge[1] - 1) {
                        return res;
                    }
                }
                break;

            default:
                if (i - 1 >= edge[1]) {
                    i--;
                } else {
                    direction = 'r';
                    edge[1]++;
                    j++;

                    if (j == edge[3]) {
                        return res;
                    }
                }
            }
        }
        return {};
    }
};
// @lc code=end
