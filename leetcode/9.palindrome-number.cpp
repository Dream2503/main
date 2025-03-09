/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // string res = to_string(x);

        // for (int i = 0, j = res.size() - 1; i <= j; i++, j--) {
        //     if (res[i] != res[j]) {
        //         return false;
        //     }
        // }
        // return true;

        if (x < 0) {
            return false;
        }
        int rev = 0;

        while (x) {
            rev = (rev * 10) + x % 10;
            x /= 10;
        }
        return rev == x;
    }
};
// @lc code=end

