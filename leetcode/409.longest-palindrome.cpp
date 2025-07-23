/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(const std::string& s) {
        std::array<int, 52> hash;
        int res = 0, flag = 0;

        for (const char ch : s) {
            if (ch >= 'a') {
                hash[ch - 'a']++;
            } else {
                hash[ch - 'A' + 26]++;
            }
        }
        for (const int element : hash) {
            if (element % 2 == 0) {
                res += element;
            } else {
                flag = true;
                res += element - 1;
            }
        }
        return res + flag;
    }
};
// @lc code=end
