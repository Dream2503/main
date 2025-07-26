/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& addToArrayForm(std::vector<int>& num, int k) {
        int carry = 0, i = num.size() - 1;

        while (i >= 0 && (k != 0 || carry)) {
            num[i] += (k % 10) + carry;
            k /= 10;
            carry = num[i] / 10;
            num[i--] %= 10;
        }
        while (k != 0 || carry) {
            num.insert(num.begin(), (k % 10) + carry);
            k /= 10;
            carry = num[0] / 10;
            num[0] %= 10;
        }
        return num;
    }
};
// @lc code=end
