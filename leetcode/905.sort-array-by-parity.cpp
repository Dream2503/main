/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& sortArrayByParity(std::vector<int>& nums) {
        const int size = nums.size();
        int i = 0, j = size - 1;

        while (i < j) {
            while (i < size && nums[i] % 2 == 0) {
                i++;
            }
            while (j >= 0 && nums[j] % 2 == 1) {
                j--;
            }
            if (i < j) {
                std::swap(nums[i++], nums[j--]);
            }
        }
        return nums;
    }
};
// @lc code=end
