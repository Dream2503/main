/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
class RecentCounter {
    std::queue<int> pings;

public:
    RecentCounter() : pings() {}

    int ping(const int t) {
        const int min = t - 3000;
        pings.push(t);

        while (min > pings.front()) {
            pings.pop();
        }
        return pings.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
