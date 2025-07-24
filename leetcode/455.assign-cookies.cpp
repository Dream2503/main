/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        const int g_size = g.size(), s_size = s.size();
        int i = 0, j = 0;

        while (i < g_size && j < s_size) {
            if (g[i] <= s[j]) {
                i++;
            }
            j++;
        }
        return i;
    }
};
// @lc code=end
