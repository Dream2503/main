/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = 1, current = 1, i = 0;

        while (i < size - 1) {
            int j = i + 1;

            while (j < size && nums[j - 1] < nums[j]) {
                current++;
                j++;
            }
            i = j;
            res = std::max(res, current);
            current = 1;
        }
        return res;
    }
};
// @lc code=end
