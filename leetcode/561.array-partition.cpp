/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition
 */

// @lc code=start
class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0, i = 1;
        sort(nums.begin(), nums.end());

        while (i < size) {
            res += std::min(nums[i - 1], nums[i]);
            i += 2;
        }
        return res;
    }
};
// @lc code=end
