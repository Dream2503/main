/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    std::string addBinary(const std::string& a, const std::string& b) {
        int i = a.size() - 1, j = b.size() - 1, k = std::max(i, j) + 2, carry = 0;
        const auto res = new char[k + 1];
        res[k--] = 0;

        while (i >= 0 || j >= 0) {
            int temp = 0;

            if (i >= 0) {
                temp += a[i] - '0';
            }
            if (j >= 0) {
                temp += b[j] - '0';
            }
            temp += carry;
            carry = 0;

            if (temp == 2) {
                carry = 1;
                res[k] = '0';
            } else if (temp == 3) {
                carry = 1;
                res[k] = '1';
            } else {
                res[k] = temp + '0';
            }
            i--;
            j--;
            k--;
        }
        if (carry) {
            res[k] = carry + '0';
        }
        return res[0] == '1' ? res : res + 1;
    }
};
// @lc code=end
