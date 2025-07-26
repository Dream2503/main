/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution {
public:
    int calPoints(const std::vector<std::string>& operations) {
        std::stack<int> stk;
        int sum;

        for (const std::string& str : operations) {
            if (str[0] == '+') {
                int temp = stk.top();
                stk.pop();
                sum = stk.top() + temp;
                stk.push(temp);
                stk.push(sum);
            } else if (str[0] == 'D') {
                stk.push(2 * stk.top());
            } else if (str[0] == 'C') {
                stk.pop();
            } else {
                stk.push(stoi(str));
            }
        }
        sum = 0;

        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};
// @lc code=end
