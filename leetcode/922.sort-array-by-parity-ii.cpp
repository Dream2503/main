/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
#include <vector>

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (nums[i] % 2 != i % 2) {
                for (int j = i + 1; j < size; j++) {
                    if (nums[j] % 2 != j % 2 && nums[j] % 2 == i % 2) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};
// @lc code=end

