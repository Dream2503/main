/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        std::vector<int> seen;

        while (n != 1 && std::find(seen.begin(), seen.end(), n) == seen.end()) {
            seen.push_back(n);
            int sum = 0;

            while (n > 0) {
                const int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
// @lc code=end
