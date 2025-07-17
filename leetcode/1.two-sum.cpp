/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, const int target) {
        const size_t size = nums.size();

        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (nums[i] + nums[j] == target)
                    return {i, j};

        return {};
    }
};
// @lc code=end
