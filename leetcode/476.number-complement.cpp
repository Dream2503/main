/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int cnt = 0, temp = num;

        while (temp) {
            cnt++;
            temp >>= 1;
        }
        num = ~num << (32 - cnt);
        return num >> (32 - cnt);
    }
};
// @lc code=end
