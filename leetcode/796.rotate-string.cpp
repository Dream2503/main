/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution {
public:
    bool rotateString(const std::string& s, const std::string& goal) {
        const int len = s.size();

        if (len != goal.size()) {
            return false;
        }
        for (int shift = 0; shift < len; shift++) {
            int i = 0;

            while (i < len && s[(shift + i) % len] == goal[i]) {
                i++;
            }
            if (i == len) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
