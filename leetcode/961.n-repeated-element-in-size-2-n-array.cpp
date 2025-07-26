/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
class Solution {
public:
    int repeatedNTimes(const std::vector<int>& nums) {
        const int size = nums.size();

        for (int i = 0; i < size - 2; ++i) {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
                return nums[i];
        }
        return nums[nums.size() - 1];
    }
};
// @lc code=end
