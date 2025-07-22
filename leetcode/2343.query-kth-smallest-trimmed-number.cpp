/*
 * @lc app=leetcode id=2343 lang=cpp
 *
 * [2343] Query Kth Smallest Trimmed Number
 */

// @lc code=start
class Solution {
public:
    std::vector<int> smallestTrimmedNumbers(const std::vector<std::string>& nums,
                                            const std::vector<std::vector<int>>& queries) {
        const int n = nums.size(), m = nums[0].size();
        std::vector<int> res;
        res.reserve(queries.size());
        std::vector<std::pair<std::string_view, int>> trimmed(n);

        for (const auto& query : queries) {
            for (int i = 0; i < n; i++) {
                trimmed[i] = {std::string_view(nums[i].data() + m - query[1], query[1]), i};
            }
            std::nth_element(trimmed.begin(), trimmed.begin() + query[0] - 1, trimmed.end(),
                             [](const auto& a, const auto& b) {
                                 return a.first == b.first ? a.second < b.second : a.first < b.first;
                             });
            res.push_back(trimmed[query[0] - 1].second);
        }
        return res;
    }
};
// @lc code=end
