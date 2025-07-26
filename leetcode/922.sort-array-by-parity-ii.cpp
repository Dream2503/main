/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& sortArrayByParityII(std::vector<int>& nums) {
        const int size = nums.size();
        int even = 0, odd = 1;

        while (even < size && odd < size) {
            if (nums[even] % 2 == 0) {
                even += 2;
            } else if (nums[odd] % 2 == 1) {
                odd += 2;
            } else {
                std::swap(nums[even], nums[odd]);
                even += 2;
                odd += 2;
            }
        }
        return nums;
    }
};
// @lc code=end
