/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
// @lc code=start
class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> stack;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            } else {
                if (stack.empty()) {
                    return false;
                }
                const char chr = stack.top();
                stack.pop();

                if (chr == ch - 1 || chr == ch - 2) {
                    continue;
                }
                return false;
            }
        }
        return stack.empty();
    }
};
// @lc code=end
