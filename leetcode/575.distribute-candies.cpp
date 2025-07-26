/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(std::vector<int>& candyType) {
        std::sort(candyType.begin(), candyType.end());
        const auto itr = std::unique(candyType.begin(), candyType.end());
        return std::min<int>(itr - candyType.begin(), candyType.size() / 2);
    }
};
// @lc code=end
