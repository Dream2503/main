
/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
class Solution {
public:
    int largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        for (int i = nums.size() - 1; i >= 2; --i) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
};
// @lc code=end
