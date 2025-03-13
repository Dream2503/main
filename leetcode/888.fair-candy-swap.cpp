/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * [888] Fair Candy Swap
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = 0, sum2 = 0, target, i = 0, j = 0;

        for (int element: aliceSizes) {
            sum1 += element;
        }
        for (int element: bobSizes) {
            sum2 += element;
        }
        target = (sum1 - sum2) / 2;
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
        return {};
    }
};
// @lc code=end