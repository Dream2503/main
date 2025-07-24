/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(const std::string& s) {
        const int len = s.length();
        int A = 0, L = 0, i = 0;

        while (i < len) {
            if (s[i] == 'A') {
                A++;
            } else if (s[i] == 'L') {
                while (i < len && s[i] == 'L' && L < 3) {
                    L++;
                    i++;
                }
                if (L > 2) {
                    return false;
                }
                L = 0;
                i--;
            }
            if (A > 1) {
                return false;
            }
            i++;
        }
        return true;
    }
};
// @lc code=end
