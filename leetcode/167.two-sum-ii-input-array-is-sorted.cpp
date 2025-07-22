/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& numbers, const int target) {
        int i = 0, j = numbers.size() - 1;

        while (i < j) {
            if (numbers[i] + numbers[j] < target) {
                i++;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                return {i + 1, j + 1};
            }
        }
        return {};
    }
};
// @lc code=end
