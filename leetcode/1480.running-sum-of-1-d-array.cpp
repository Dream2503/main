/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& runningSum(std::vector<int>& nums) {
        const int size = nums.size();

        for (int i = 1; i < size; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
// @lc code=end
