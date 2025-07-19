/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(const std::vector<int>& nums) {
        int res = 0, current = 0, i = 0, size = nums.size();

        while (i < size) {
            if (nums[i]) {
                while (i < size && nums[i]) {
                    current++;
                    i++;
                }
                res = std::max(res, current);
                current = 0;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
