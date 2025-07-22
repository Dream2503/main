/*
 * @lc app=leetcode id=519 lang=cpp
 *
 * [519] Random Flip Matrix
 */

#include <bitset>
// @lc code=start
class Solution {
    const int m, n;
    std::set<std::pair<int, int>> set;

public:
    Solution(const int m, const int n) : m(m), n(n), set() {}

    std::vector<int> flip() {
        int row, col;
        do {
            row = std::rand() % m;
            col = std::rand() % n;
        } while (!set.emplace(row, col).second);
        return {row, col};
    }

    void reset() { set.clear(); }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end
