
/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int i = nums.size() - 3, a, b, c;
        sort(nums.begin(), nums.end());
        
        while (i >= 0) {
            a = nums[i], b = nums[i + 1], c = nums[i + 2];

            if (a + b > c && b + c > a && a + c > b) {
                return a + b + c;
            }
            i--;
        }
        return 0;
    }
};
// @lc code=end

