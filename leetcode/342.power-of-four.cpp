/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(const int n) {
        if (n <= 0) {
            return false;
        }
        const double res = log(n) / log(4);
        return floor(res) == res;
    }
};
// @lc code=end
