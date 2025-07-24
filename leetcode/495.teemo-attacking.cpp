/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(const std::vector<int>& timeSeries, const int duration) {
        const int size = timeSeries.size() - 1;
        int cnt = 0;

        if (!size) {
            return duration;
        }

        for (int i = 0; i < size; i++) {
            const int temp = timeSeries[i] + duration - 1;
            cnt += duration;

            if (temp >= timeSeries[i + 1]) {
                cnt -= temp - timeSeries[i + 1] + 1;
            }
        }
        return cnt + duration;
    }
};
// @lc code=end
