/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(const std::vector<int>& nums) {
        const int size = nums.size();
        std::unordered_map<int, std::vector<int>> hash;

        for (int i = 0; i < size; i++) {
            auto itr = hash.find(nums[i]);

            if (itr != hash.end()) {
                if (i < itr->second[1]) {
                    itr->second[1] = i;
                } else if (i > itr->second[2]) {
                    itr->second[2] = i;
                }
                itr->second[0]++;
            } else {
                hash.insert({nums[i], {1, i, i}});
            }
        }
        int degree = 0, res = size;

        for (const auto& [element, vec] : hash) {
            if (vec[0] > degree) {
                degree = vec[0];
                res = size;
            }
            if (vec[0] == degree) {
                res = std::min<int>(res, vec[2] - vec[1] + 1);
            }
        }
        return res;
    }
};
// @lc code=end
