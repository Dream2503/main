/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class Solution {
public:
    int kthGrammar(const int n, int k) {
        int res = 0;
        k--;

        while (k > 0) {
            res += k % 2;
            k /= 2;
        }
        return res % 2;
    }
};
// @lc code=end
