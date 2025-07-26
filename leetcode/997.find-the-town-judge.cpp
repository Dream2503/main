/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
    int findJudge(const int n, const std::vector<std::vector<int>>& trust) {
        std::vector<std::pair<bool, int>> trusts;
        trusts.resize(n + 1);

        for (const std::vector<int>& element : trust) {
            trusts[element[0]].first = true;
            trusts[element[1]].second++;
        }
        for (int i = 1; i <= n; i++) {
            if (!trusts[i].first && trusts[i].second == n - 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
