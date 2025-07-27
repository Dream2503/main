/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start
class Solution {

public:
    int numEquivDominoPairs(const std::vector<std::vector<int>>& dominoes) {
        std::unordered_map<int, int> hash;
        int res = 0;

        for (const std::vector<int>& d : dominoes) {
            int key = std::min(d[0], d[1]) * 10 + std::max(d[0], d[1]);
            res += hash[key]++;
        }
        return res;
    }
};
// @lc code=end
