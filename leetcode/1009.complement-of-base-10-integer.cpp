/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(const int n) {
        if (n == 0) {
            return 1;
        }
        const int width = 32 - std::__bit_width(n);
        return (~n << width) >> width;
    }
};
// @lc code=end
