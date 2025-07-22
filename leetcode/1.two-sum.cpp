/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, const int target) {
        const int size = nums.size();
        std::unordered_map<int, int> hash;

        for (int i = 0; i < size; i++) {
            if (hash.find(nums[i]) == hash.end()) {
                hash.emplace(target - nums[i], i);
            } else {
                return {hash[nums[i]], i};
            }
        }
        return {};
    }
};
// @lc code=end
