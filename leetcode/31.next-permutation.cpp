/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        const int size = nums.size();
        int j = size - 1, min = size - 1;

        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                while (j > i) {
                    if (nums[i] < nums[j]) {
                        min = j;
                        break;
                    }
                    j--;
                }
                while (j > i) {
                    if (nums[j] < nums[min] && nums[j] > nums[i]) {
                        min = j;
                    }
                    j--;
                }
                std::swap(nums[i], nums[min]);
                std::reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        std::reverse(nums.begin(), nums.end());
    }
};
// @lc code=end
