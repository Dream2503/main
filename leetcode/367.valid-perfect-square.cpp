/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(const int num) {
        int low = 1, high = num;

        while (low <= high) {
            const int mid = low + (high - low) / 2, div = num / mid;

            if (mid == div && num % mid == 0) {
                return true;
            }
            if (mid > div) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end
