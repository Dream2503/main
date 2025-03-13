/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        transform(nums.begin(), nums.end(), nums.begin(), [](int n) {return n * n;});
        sort(nums.begin(), nums.end());
        return nums;
    }
};
// @lc code=end

