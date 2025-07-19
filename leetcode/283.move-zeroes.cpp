/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        const int size = nums.size();
        int i = 0;

        while (i < size && nums[i]) {
            i++;
        }
        int j = i + 1;

        while (j < size) {
            while (j < size && !nums[j]) {
                j++;
            }
            if (j < size) {
                nums[i++] = nums[j++];
            }
        }
        while (i < size) {
            nums[i++] = 0;
        }
    }
};
// @lc code=end
