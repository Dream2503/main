/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
    }
};
// @lc code=end
