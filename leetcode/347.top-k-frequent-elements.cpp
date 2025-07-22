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
        std::vector<int> res;
        res.reserve(k);

        for (const int element : nums) {
            hash[element]++;
        }
        std::vector<std::pair<int, int>> vec(hash.begin(), hash.end());
        std::partial_sort(vec.begin(), vec.begin() + k, vec.end(),
                          [](const auto& a, const auto& b) { return a.second > b.second; });

        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].first);
        }
        return res;
    }
};  
// @lc code=end
