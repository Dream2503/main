/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution {
public:
    int findNumbers(const std::vector<int>& nums) {
        int res = 0;

        for (const int num : nums) {
            res += (static_cast<int>(std::log10(num)) + 1) % 2 == 0;
        }
        return res;
    }
};
// @lc code=end
