/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
#include <string>

class Solution {
public:
    std::string& reverseOnlyLetters(std::string& s) {
        const int len = s.size();
        int i = 0, j = len - 1;

        while (i < j) {
            while (i < j && !isalpha(s[i])) {
                i++;
            }
            while (i < j && !isalpha(s[j])) {
                j--;
            }
            if (i < j) {
                std::swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
// @lc code=end
