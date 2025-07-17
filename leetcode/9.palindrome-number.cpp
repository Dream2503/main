/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(const int x) {
        if (x < 0) {
            return false;
        }
        long rev = 0;
        int copy = x;

        while (copy) {
            rev = (rev * 10) + copy % 10;
            copy /= 10;
        }
        return rev == x;
    }
};
// @lc code=end
