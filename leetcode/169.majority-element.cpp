/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        const int size = nums.size();
        std::nth_element(nums.begin(), nums.begin() + (size / 2), nums.end());
        return nums[size / 2];
    }
};
// @lc code=end
