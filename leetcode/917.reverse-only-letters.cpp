/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
#include <string>

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int size = s.size(), i = 0, j = size - 1;

        while (i < j) {
            while (i < size && !isalpha(s[i])) {
                i++;
            }
            while (j >= 0 && !isalpha(s[j])) {
                j--;
            }

            if (i < j) {
                swap(s[i], s[j]);
                i++; j--;
            }
        }
        return s;
    }
};
// @lc code=end

