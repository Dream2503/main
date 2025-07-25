/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        const int size = cost.size();

        for (int i = 2; i < size; i++) {
            cost[i] += std::min(cost[i - 1], cost[i - 2]);
        }
        return std::min(cost[size - 1], cost[size - 2]);
    }
};
// @lc code=end
