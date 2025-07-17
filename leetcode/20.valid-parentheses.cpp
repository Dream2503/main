/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
// @lc code=start
class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> stk;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                if (stk.empty()) {
                    return false;
                }
                const char chr = stk.top();
                stk.pop();

                if (chr == ch - 1 || chr == ch - 2) {
                    continue;
                }
                return false;
            }
        }
        return stk.empty();
    }
};
// @lc code=end
