/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(const std::vector<int>& nums, const int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int res = sum;
        const int size = nums.size();

        for (int i = k; i < size; i++) {
            sum += nums[i] - nums[i - k];
            res = std::max(res, sum);
        }
        return res / static_cast<double>(k);
    }
};

// @lc code=end
