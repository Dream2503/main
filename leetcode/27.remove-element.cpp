/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(std::vector<int>& nums, const int val) {
        const int len = nums.size();

        if (len == 0) {
            return 0;
        }
        int i = 0, j = len - 1;

        while (i < j) {
            while (i < j && nums[i] != val) {
                i++;
            }
            while (i < j && nums[j] == val) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        }
        while (i < len && nums[i] != val) {
            i++;
        }
        return i;
    }
};
// @lc code=end
