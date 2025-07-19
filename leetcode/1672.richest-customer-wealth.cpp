/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
class Solution {
public:
    int maximumWealth(const std::vector<std::vector<int>>& accounts) {
        int res = 0;

        for (const std::vector<int>& customer : accounts) {
            res = std::max(res, std::accumulate(customer.begin(), customer.end(), 0));
        }
        return res;
    }
};
// @lc code=end
