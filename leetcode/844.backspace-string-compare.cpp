/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(const std::string& s, const std::string& t) {
        std::string S, T;

        for (const char ch : s) {
            if (ch == '#' && !S.empty()) {
                S.pop_back();
            } else if (ch != '#') {
                S.push_back(ch);
            }
        }
        for (const char ch : t) {
            if (ch == '#' && !T.empty()) {
                T.pop_back();
            } else if (ch != '#') {
                T.push_back(ch);
            }
        }
        return S == T;
    }
};
// @lc code=end
