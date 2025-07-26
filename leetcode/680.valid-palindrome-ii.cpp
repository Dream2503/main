/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(const std::string& s) {
        int i = 0, j = s.size() - 1, k = 0, l = 0;
        bool check1 = false, check2 = false;

        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else if (!check1 && s[i] != s[j]) {
                check1 = true;
                k = i++;
                l = j;
            } else if (!check2) {
                i = k;
                j = --l;
                check2 = true;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
