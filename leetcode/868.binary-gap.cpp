/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
class Solution {
public:
    int binaryGap(int n) {
        int max = 0, current = -32;

        while (n) {
            if (n & 1) {
                max = std::max(max, current);
                current = 1;
            } else {
                current++;
            }
            n >>= 1;
        }
        return max;
    }
};
// @lc code=end
