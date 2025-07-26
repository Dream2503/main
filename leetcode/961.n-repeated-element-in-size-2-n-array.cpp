/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size(), n = size / 2;
        sort(nums.begin(), nums.end());
        nums.push_back(-1);

        for (int i = 0; i < size - n + 1; i++) {
            if (nums[i] == nums[i + n - 1] && nums[i] != nums[i + n]) {
                return nums[i];
            }
        }
        return -1;
    }
};
// @lc code=end

