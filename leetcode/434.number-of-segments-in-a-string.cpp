/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(const std::string& s) {
        const int len = s.length();
        int i = 0, cnt = 0;

        while (i < len && s[i] == ' ')
            i++;

        while (i < len) {
            cnt++;

            while (i < len && s[i] != ' ') {
                i++;
            }
            while (i < len && s[i] == ' ') {
                i++;
            }
        }
        return cnt;
    }
};
// @lc code=end
