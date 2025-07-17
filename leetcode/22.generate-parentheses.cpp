/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    void recursive_generator(std::vector<std::string>& vec, std::string& s, const int open, const int close,
                             const int n) {
        if (open == close && open == n) {
            vec.push_back(s);
        }
        if (open != n) {
            s.push_back('(');
            recursive_generator(vec, s, open + 1, close, n);
            s.pop_back();
        }
        if (close < open) {
            s.push_back(')');
            recursive_generator(vec, s, open, close + 1, n);
            s.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(const int n) {
        std::vector<std::string> vec;
        std::string s;
        s.reserve(2 * n);
        recursive_generator(vec, s, 0, 0, n);
        return vec;
    }
};
// @lc code=end
