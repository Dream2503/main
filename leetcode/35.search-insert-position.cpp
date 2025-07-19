/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(const std::vector<int>& nums, const int target) {
        int low = 0, high = nums.size() - 1, mid = 0;

        while (low <= high) {
            mid = (low + high) / 2;

            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        if (low >= nums.size() || !low) {
            return low;
        }
        while (low != -1 and nums[low] >= target) {
            low--;
        }
        if (low != -1) {
            return low + 1;
        }
        return mid;
    }
};
// @lc code=end
