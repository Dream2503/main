/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
class Solution {
public:
    int heightChecker(const std::vector<int>& heights) {
        std::vector<int> check = heights;
        std::sort(check.begin(), check.end());
        const int size = heights.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            if (heights[i] != check[i]) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
