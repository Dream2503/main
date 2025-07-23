/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    std::string addStrings(const std::string& num1, const std::string& num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0, add;
        std::string res;
        res.reserve(std::max(i, j) + 2);

        while (i != -1 && j != -1) {
            add = num1[i--] + num2[j--] - '0' - '0' + carry;
            carry = add / 10;
            res.push_back((add % 10) + '0');
        }
        while (i != -1) {
            add = num1[i--] + carry - '0';
            carry = add / 10;
            res.push_back((add % 10) + '0');
        }
        while (j != -1) {
            add = num2[j--] + carry - '0';
            carry = add / 10;
            res.push_back((add % 10) + '0');
        }
        if (carry) {
            res.push_back(carry + '0');
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
