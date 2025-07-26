/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        const std::unordered_set seen(nums.begin(), nums.end());
        int res = 0;

        for (const int n : seen) {
            if (!seen.count(n - 1)) {
                int current = n + 1, len = 1;

                while (seen.count(current++)) {
                    len++;
                }
                res = std::max(res, len);
            }
        }
        return res;
    }
};
// @lc code=end
