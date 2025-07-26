/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0;
        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < size; i++) {
            res = std::max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};
// @lc code=end
