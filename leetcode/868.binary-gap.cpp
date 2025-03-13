/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
class Solution {
public:
    int binaryGap(int n) {
        int max = 0, current = 0;
        bool on_pair = false;

        while (n != 0) {
            if (n & 1) {
                if (on_pair) {
                    if (max < current) {
                        max = current;
                    }
                    current = 1;
                } else {
                    current++;
                    on_pair = true;
                }
            } else {
                if (on_pair) {
                    current++;
                }
            }
            n = n >> 1;
        }
        return max;
    }
};
// @lc code=end

