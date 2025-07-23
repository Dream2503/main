/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(const std::string& s, const std::string& t) {
        const int s_len = s.size(), t_len = t.size();
        int i = 0, j = 0;

        while (j < t_len) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i >= s_len;
    }
};
// @lc code=end
