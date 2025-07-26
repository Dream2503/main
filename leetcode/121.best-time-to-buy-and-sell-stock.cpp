/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        const int size = prices.size();
        int buy = prices[0], res = 0;

        for (int i = 1; i < size; i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            }
            res = max(res, prices[i] - buy);
        }
        return res;
    }
};
// @lc code=end
