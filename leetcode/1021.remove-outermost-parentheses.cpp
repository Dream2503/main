/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
class Solution {
public:
    std::string removeOuterParentheses(const std::string& s) {
        const int len = s.length();
        std::string res;
        int i = 0, cnt = 0;
        bool is_open = false;

        while (i < len) {
            if (s[i] == '(') {
                if (!is_open) {
                    is_open = true;
                } else {
                    res.push_back('(');
                    cnt++;
                }
            } else {
                if (cnt > 0) {
                    cnt--;
                    res.push_back(')');
                } else {
                    is_open = false;
                }
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
