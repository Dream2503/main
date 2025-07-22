/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(const std::string& jewels, const std::string& stones) {
        static int64_t hash;
        int res = 0;
        hash = 0;

        for (const char ch : jewels) {
            if (ch >= 'a') {
                hash |= 1l << (ch - 'a');
            } else {
                hash |= 1l << (ch - 'A' + 26);
            }
        }
        for (const char ch : stones) {
            if (ch >= 'a' && hash & (1l << (ch - 'a')) || ch <= 'Z' && hash & (1l << (ch - 'A' + 26))) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
