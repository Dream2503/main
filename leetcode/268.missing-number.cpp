/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0, i;

        for (i = 0; i < size; i++) {
            res ^= i;
            res ^= nums[i];
        }
        res ^= i;
        return res;
    }
};
// @lc code=end
