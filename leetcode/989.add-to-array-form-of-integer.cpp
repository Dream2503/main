/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0, i = num.size() - 1;

        while (i >= 0 && k != 0) {
            num[i] += (k % 10) + carry;
            k /= 10;
            carry = num[i] / 10;
            num[i] %= 10;
            i--;
        }
        while (k != 0) {
            num.insert(num.begin(), (k % 10) + carry);
            k /= 10;
            carry = num[0] / 10;
            num[0] %= 10;
        }
        while (carry) {
            if (i >= 0) {
                num[i] += carry;
                carry = num[i] / 10;
                num[i] %= 10;
                i--;
            } else {
                num.insert(num.begin(), carry);
                carry = num[0] / 10;
                num[0] %= 10;
            }
        }
        return num;
    }
};
// @lc code=end

