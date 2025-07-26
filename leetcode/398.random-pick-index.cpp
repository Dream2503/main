/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
    std::unordered_map<int, std::vector<int>> hash;

public:
    Solution(const std::vector<int>& nums) : hash() {
        const int size = nums.size();

        for (int i = 0; i < size; i++) {
            hash[nums[i]].push_back(i);
        }
    }

    int pick(const int target) {
        const std::vector<int>& temp = hash[target];
        return temp[std::rand() % temp.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
