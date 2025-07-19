/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(const std::vector<int>& nums) {
        int res = 0;

        for (const int num : nums) {
            res ^= num;
        }
        return res;
    }
};
// @lc code=end
