/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue heap(std::less<int>(), std::move(stones));

        while (heap.size() > 1) {
            const int stone1 = heap.top();
            heap.pop();
            const int stone2 = heap.top();
            heap.pop();

            if (stone1 != stone2) {
                heap.push(stone1 - stone2);
            }
        }
        return heap.empty() ? 0 : heap.top();
    }
};
// @lc code=end
