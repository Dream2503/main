/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

// @lc code=start
class Solution {
public:
    std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();
        int i = 0, j = 0;
        bool up = true;
        std::vector<int> res;
        res.reserve(m * n);

        while (true) {
            res.push_back(mat[i][j]);

            if (up) {
                if (j + 1 < n) {
                    j++;

                    if (i - 1 >= 0) {
                        i--;
                    } else {
                        up = false;
                    }
                } else if (i + 1 < m) {
                    i++;
                    up = false;
                } else {
                    break;
                }
            } else {
                if (i + 1 < m) {
                    i++;

                    if (j - 1 >= 0) {
                        j--;
                    } else {
                        up = true;
                    }
                } else if (j + 1 < n) {
                    j++;
                    up = true;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
