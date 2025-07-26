/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(const std::string& s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            while (i < j && !std::isalnum(s[i])) {
                i++;
            }
            while (i < j && !std::isalnum(s[j])) {
                j--;
            }
            if (i < j) {
                if (std::tolower(s[i++]) != std::tolower(s[j--])) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
