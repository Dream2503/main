/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(const std::vector<int>& nums, const int k) {
        const auto [min, max] = minmax_element(nums.begin(), nums.end());
        return std::max(0, *max - *min - 2 * k); // range -> (max - k) - (min + k)
    }
};
// @lc code=end
