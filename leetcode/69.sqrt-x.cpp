/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(const int x) {
        if (x < 2) {
            return x;
        }
        double n = x;

        while (true) {
            const double root = 0.5 * (n + x / n);

            if (std::abs(root - n) < 1e-5) {
                return static_cast<int>(n);
            }
            n = root;
        }
        return 0;
    }
};
// @lc code=end
