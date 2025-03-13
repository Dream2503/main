/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        auto min_max = minmax_element(nums.begin(), nums.end());
        int diff = *min_max.second - *min_max.first - k;

        if (diff <= k) {
            return 0;
        } else {
            return diff - k;
        }
    }
};
// @lc code=end

