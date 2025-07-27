/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
class Solution {
public:
    std::vector<bool> prefixesDivBy5(const std::vector<int>& nums) {
        std::vector<bool> res;
        int n = 0;
        res.reserve(nums.size());

        for (const int element : nums) {
            n = (n << 1 | element) % 5;
            res.push_back(n == 0);
        }
        return res;
    }
};
// @lc code=end

