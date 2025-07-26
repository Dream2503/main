/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<bool, int>> trusts;
        int res = 0;
        trusts.resize(n + 1);

        for (vector<int> &element: trust) {
            trusts[element[0]].first = true;
            trusts[element[1]].second++;
        }
        for (int i = 1; i <= n; i++) {
            if (!trusts[i].first) {
                if (res == 0 && trusts[i].second == n - 1) {
                    res = i;
                } else {
                    res = -1;
                }
            }
        }
        return res == 0 ? -1: res;
    }
};
// @lc code=end

