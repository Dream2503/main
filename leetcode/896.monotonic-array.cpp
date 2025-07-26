/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
class Solution {
public:
    bool isMonotonic(const std::vector<int>& nums) {
        const int size = nums.size();
        int i = 0;

        while (i < size - 1 && nums[i] == nums[i + 1]) {
            i++;
        }
        if (i < size - 1) {
            if (nums[i] - nums[i + 1] > 0) {
                while (i < size - 1) {
                    if (nums[i] < nums[i + 1]) {
                        return false;
                    }
                    i++;
                }
            } else {
                while (i < size - 1) {
                    if (nums[i] > nums[i + 1]) {
                        return false;
                    }
                    i++;
                }
            }
        }
        return true;
    }
};
// @lc code=end
