/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>>& flipAndInvertImage(std::vector<std::vector<int>>& image) {
        for (std::vector<int>& row : image) {
            for (int i = 0, j = row.size() - 1; i <= j; i++, j--) {
                if (row[i] == row[j]) {
                    row[i] = !row[i];

                    if (i != j) {
                        row[j] = !row[j];
                    }
                }
            }
        }
        return image;
    }
};
// @lc code=end
