/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(const int target, const std::vector<int>& nums) {
        const int size = nums.size();
        int i = 0, sum = 0, res = INT32_MAX;

        for (int j = 0; j < size; j++) {
            sum += nums[j];

            while (sum >= target) {
                res = std::min(res, j - i + 1);
                sum -= nums[i++];
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};
// @lc code=end
