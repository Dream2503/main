/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        const int size = nums.size();
        std::sort(nums.begin(), nums.end());
        int i = 0, res = 0;

        for (int j = 0; j < size; j++) {
            while (nums[j] - nums[i] > 1) {
                i++;
            }

            if (nums[j] - nums[i] == 1) {
                res = std::max(res, j - i + 1);
            }
        }
        return res;
    }
};
// @lc code=end
