/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(std::vector<int>& nums, int k) {
        const int size = nums.size();
        int i = 0;
        std::sort(nums.begin(), nums.end());

        while (i < size && nums[i] < 0 && k > 0) {
            nums[i++] = -nums[i];
            k--;
        }
        if (k % 2 != 0) {
            if (i == size) {
                nums[i - 1] = -nums[i - 1];
            } else if (i == 0 || nums[i - 1] > nums[i]) {
                nums[i] = -nums[i];
            } else if (i == size) {
                nums[i - 1] = -nums[i - 1];
            } else {
                nums[i - 1] = -nums[i - 1];
            }
        }
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end
