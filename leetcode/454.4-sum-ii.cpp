/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(const std::vector<int>& nums1, const std::vector<int>& nums2, const std::vector<int>& nums3,
                     const std::vector<int>& nums4) {
        std::unordered_map<int, int> hash;
        int cnt = 0;

        for (const int a : nums1) {
            for (const int b : nums2) {
                hash[a + b]++;
            }
        }
        for (const int c : nums3) {
            for (const int d : nums4) {
                cnt += hash[-c - d];
            }
        }
        return cnt;
    }
};
// @lc code=end
