/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        const int size = nums.size();

        for (int i = 0; i < size; i++) {
            const int idx = std::abs(nums[i]) - 1;
            nums[idx] = -std::abs(nums[idx]);
        }
        std::vector<int> res;

        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end
