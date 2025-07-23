/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> readBinaryWatch(const int turnedOn) {
        std::vector<std::string> res;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (std::__popcount(h) + std::__popcount(m) == turnedOn) {
                    res.push_back(std::to_string(h) + (m < 10 ? ":0" : ":") + std::to_string(m));
                }
            }
        }
        return res;
    }
};
// @lc code=end
