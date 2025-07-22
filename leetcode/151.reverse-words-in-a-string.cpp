/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    std::string& reverseWords(std::string& s) {
        int len = s.length();
        int i = 0, j = 0;

        while (s[len - 1] == ' ') {
            len--;
        }
        while (j < len && s[j] == ' ') {
            j++;
        }
        while (j < len) {
            while (j < len - 1 && s[j] == ' ') {
                j++;
            }
            if (j < len) {
                while (j < len && s[j] != ' ') {
                    if (i != j) {
                        s[i] = s[j];
                    }
                    i++;
                    j++;
                }
                if (j < len) {
                    s[i++] = s[j++];
                }
            }
        }
        s.resize(i);
        len = i;
        std::reverse(s.begin(), s.end());
        i = j = 0;

        while (j < len) {
            while (j < len && s[j] != ' ') {
                j++;
            }
            std::reverse(s.begin() + i, s.begin() + j);
            i = ++j;
        }
        return s;
    }
};
// @lc code=end
