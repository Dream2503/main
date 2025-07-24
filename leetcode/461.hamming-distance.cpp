/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;

        while (x && y) {
            res += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
        }
        while (x) {
            res += x & 1;
            x >>= 1;
        }
        while (y) {
            res += y & 1;
            y >>= 1;
        }
        return res;
    }
};
// @lc code=end
