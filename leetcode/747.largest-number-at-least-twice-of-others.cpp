/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(std::vector<int>& nums) {
        const int res = std::max_element(nums.begin(), nums.end()) - nums.begin();
        std::nth_element(nums.begin(), nums.begin() + 2, nums.end(), std::greater<int>());

        if (nums[0] * 2 <= nums[1] || nums[1] * 2 <= nums[0]) {
            return res;
        }
        return -1;
    }
};
// @lc code=end
