/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
class Solution {
public:
    std::vector<int> selfDividingNumbers(int left, const int right) {
        std::vector<int> res;
        bool divisible = true;

        while (left < 10) {
            res.push_back(left++);
        }
        while (left <= right) {
            int temp = left;

            while (temp) {
                if (!(temp % 10) || left % (temp % 10) != 0) {
                    divisible = false;
                    break;
                }
                temp /= 10;
            }
            if (divisible) {
                res.push_back(left);
            } else {
                divisible = true;
            }
            left++;
        }
        return res;
    }
};
// @lc code=end
