/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    std::vector<int> sortedSquares(const std::vector<int>& nums) {
        std::vector<int> res;
        const int size = nums.size();
        res.reserve(size);
        int i = 0;

        while (i < size && nums[i] < 0) {
            i++;
        }
        int j = i - 1;

        while (i < size && j >= 0) {
            if (std::abs(nums[i]) < std::abs(nums[j])) {
                res.push_back(nums[i] * nums[i]);
                i++;
            } else {
                res.push_back(nums[j] * nums[j]);
                j--;
            }
        }
        while (i < size) {
            res.push_back(nums[i] * nums[i]);
            i++;
        }
        while (j >= 0) {
            res.push_back(nums[j] * nums[j]);
            j--;
        }
        return res;
    }
};
// @lc code=end
