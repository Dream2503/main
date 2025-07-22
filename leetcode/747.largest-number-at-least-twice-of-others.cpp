/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(std::vector<int>& nums) {
        const int size = nums.size(), res = std::max_element(nums.begin(), nums.end()) - nums.begin();

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }
        if (nums[size - 1] >= nums[size - 2] * 2) {
            return res;
        }
        return -1;
    }
};
// @lc code=end
