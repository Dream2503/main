/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
class Solution {
public:
    std::vector<int> constructRectangle(const int area) {
        int w = static_cast<int>(std::sqrt(area));

        while (area % w) {
            w--;
        }
        return {area / w, w};
    }
};
// @lc code=end
