/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(const std::string& s) {
        static std::stack<char> stk;
        const size_t len = s.length();
        int current = 0, res = 0, i = 0;

        while (!stk.empty()) {
            stk.pop();
        }
        while (i < len) {
            if (s[i] == '(') {
                stk.push(s[i]);
            } else {
                if (!stk.empty()) {
                    current++;
                    stk.pop();
                } else {
                    res = std::max(current * 2, res);
                }
            }
            i++;
        }
        return std::max(current * 2, res);
    }
};
// @lc code=end
