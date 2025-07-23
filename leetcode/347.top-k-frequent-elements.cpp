/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    std::vector<int> topKFrequent(const std::vector<int>& nums, const int k) {
        std::unordered_map<int, int> hash;

        for (const int element : nums) {
            hash[element]++;
        }
        using pair = std::pair<const int, int>;
        auto comparator = [](const pair* a, const pair* b) { return a->second > b->second; };
        std::priority_queue<pair*, std::vector<pair*>, decltype(comparator)> heap(comparator);

        for (pair& element : hash) {
            if (heap.size() < k) {
                heap.push(&element);
            } else if (element.second > heap.top()->second) {
                heap.pop();
                heap.push(&element);
            }
        }
        std::vector<int> res;
        res.reserve(k);

        while (!heap.empty()) {
            res.push_back(heap.top()->first);
            heap.pop();
        }
        return res;
    }
};
// @lc code=end
