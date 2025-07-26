/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> largeGroupPositions(const std::string& s) {
        const int len = s.size();
        int i = 0, j = 1;
        std::vector<std::vector<int>> res;

        while (j < len) {
            while (j < len && s[j] == s[i]) {
                j++;
            }
            if (j - i >= 3) {
                res.push_back({i, j - 1});
            }
            i = j;
            j++;
        }
        return res;
    }
};
// @lc code=end
