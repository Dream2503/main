/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, const int target) {
        std::sort(nums.begin(), nums.end());
        const int size = nums.size();
        int left, right, res = 0, tol = INT32_MAX;

        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            left = i + 1, right = size - 1;

            while (left < right) {
                const int sum = nums[left] + nums[right] + nums[i];

                if (std::abs(target - sum) < tol) {
                    tol = abs(target - sum);
                    res = sum;
                }
                if (sum == target) {
                    left++;
                    right--;
                } else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};
// @lc code=end
