/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    std::vector<int>& sortArrayByParity(std::vector<int>& nums) {
        const int size = nums.size();
        int i = 0, j = size - 1;

        while (i < j) {
            while (i < size && nums[i] % 2 == 0) {
                i++;
            }
            while (j >= 0 && nums[j] % 2 == 1) {
                j--;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
                i++; j--;
            }
        }
        return nums;
    }
};
// @lc code=end

