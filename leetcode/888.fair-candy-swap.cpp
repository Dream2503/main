/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * [888] Fair Candy Swap
 */

// @lc code=start
class Solution {
public:
    std::vector<int> fairCandySwap(std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
        const int target = (std::accumulate(aliceSizes.begin(), aliceSizes.end(), 0) -
                            std::accumulate(bobSizes.begin(), bobSizes.end(), 0)) / 2;
        int i = 0, j = 0;
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());

        while (true) {
            if (aliceSizes[i] - bobSizes[j] < target) {
                i++;
            } else if (aliceSizes[i] - bobSizes[j] > target) {
                j++;
            } else {
                return {aliceSizes[i], bobSizes[j]};
            }
        }
    }
};
// @lc code=end
