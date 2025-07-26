/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> imageSmoother(const std::vector<std::vector<int>>& img) {
        const int size1 = img.size(), size2 = img[0].size();
        std::vector res(size1, std::vector<int>(size2));

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                int sum = img[i][j], cnt = 1;

                if (i - 1 >= 0) {
                    if (j - 1 >= 0) {
                        sum += img[i - 1][j - 1];
                        cnt++;
                    }
                    if (j + 1 < size2) {
                        sum += img[i - 1][j + 1];
                        cnt++;
                    }
                    sum += img[i - 1][j];
                    cnt++;
                }
                if (j - 1 >= 0) {
                    sum += img[i][j - 1];
                    cnt++;
                }
                if (j + 1 < size2) {
                    sum += img[i][j + 1];
                    cnt++;
                }
                if (i + 1 < size1) {
                    if (j - 1 > -1) {
                        sum += img[i + 1][j - 1];
                        cnt++;
                    }
                    if (j + 1 < size2) {
                        sum += img[i + 1][j + 1];
                        cnt++;
                    }
                    sum += img[i + 1][j];
                    cnt++;
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};

// @lc code=end
