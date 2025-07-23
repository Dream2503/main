/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> summaryRanges(const std::vector<int>& nums) {
        std::vector<std::string> res;

        if (nums.empty()) {
            return res;
        }
        const int size = nums.size();
        int start = nums[0];

        for (int i = 1; i <= size; i++) {
            if (i < size && nums[i] == nums[i - 1] + 1) {
                continue;
            }
            if (start == nums[i - 1]) {
                res.push_back(std::to_string(start));
            } else {
                res.push_back(std::to_string(start) + "->" + std::to_string(nums[i - 1]));
            }
            if (i < size) {
                start = nums[i];
            }
        }
        return res;
    }
};
// @lc code=end
