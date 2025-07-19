/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;

        while (num) {
            num = num % 2 ? num - 1 : num / 2;
            res++;
        }
        return res;
    }
};
// @lc code=end
