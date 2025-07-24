/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
        std::nth_element(nums.begin(), nums.begin() + 3, nums.end(), std::greater<int>());
        const int res = nums[0] * nums[1] * nums[2];
        const int max = *std::max_element(nums.begin(), nums.begin() + 3);
        std::nth_element(nums.begin(), nums.begin() + 2, nums.end());
        return std::max(nums[0] * nums[1] * max, res);
    }
};
// @lc code=end
