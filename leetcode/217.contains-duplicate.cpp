/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        const int size = nums.size();
        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < size; i++) {
            if (nums[i - 1] == nums[i]) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
