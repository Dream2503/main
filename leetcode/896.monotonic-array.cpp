/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int size = nums.size(), i = 0;

        if (size == 1) {
            return true;
        }
        while (i < size - 1 && nums[i] == nums[i + 1]) {
            i++;
        }
        if (i == size - 1) {
            return true;
        }
        if (nums[i] - nums[i + 1] > 0) {
            for (; i < size - 1; i++) {
                if (nums[i] < nums[i + 1]) {
                    return false;
                }
            }
            return true;
        } else {
            for (; i < size - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    return false;
                }
            }
            return true;
        }
    }
};
// @lc code=end

