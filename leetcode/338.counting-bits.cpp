/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    std::vector<int> countBits(const int n) {
        std::vector<int> res;
        res.reserve(n + 1);
        res.push_back(0);

        for (int i = 1; i <= n; i++) {
            res.push_back(res[i >> 1] + (i & 1));
        }
        return res;
    }
};
// @lc code=end
