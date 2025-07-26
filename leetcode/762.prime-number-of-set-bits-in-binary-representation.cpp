/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
class Solution {
public:
    int countPrimeSetBits(int left, const int right) {
        static constexpr uint32_t prime = 0b10100010100010101100; // prime position bits
        int res = 0;

        while (left <= right) {
            if (prime >> std::__popcount(left) & 1) {
                res++;
            }
            left++;
        }
        return res;
    }
};
// @lc code=end
