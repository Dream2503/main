/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        const int size = nums.size();
        static int array[3];
        int len = 0;

        for (int i = 0; i < size && len < 3; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
            if (std::find(array, array + len, nums[size - i - 1]) == array + len) {
                array[len++] = nums[size - i - 1];
            }
        }
        if (len == 1) {
            return array[0];
        }
        if (len == 2) {
            return std::max(array[0], array[1]);
        }
        return array[2];
    }
};
// @lc code=end
