/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        const int size = nums.size();
        std::vector res(size, 1);
        int prev = 1;

        for (int i = 0; i < size; i++) {
            res[i] = prev;
            prev *= nums[i];
        }
        int next = 1;

        for (int i = size - 1; i >= 0; i--) {
            res[i] *= next;
            next *= nums[i];
        }
        return res;
    }
};
// @lc code=end
