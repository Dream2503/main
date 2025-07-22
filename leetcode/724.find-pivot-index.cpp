/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(const std::vector<int>& nums) {
        int res = 0, left_sum = 0, right_sum = std::accumulate(nums.begin() + 1, nums.end(), 0);
        const int size = nums.size();

        if (size == 1) {
            return 0;
        }
        while (left_sum != right_sum && res < size - 1) {
            left_sum += nums[res++];
            right_sum -= nums[res];
        }
        if (left_sum == right_sum) {
            return res;
        }
        return -1;
    }
};
// @lc code=end
