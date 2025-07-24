/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& nextGreaterElement(std::vector<int>& nums1, const std::vector<int>& nums2) {
        const int size = nums2.size();
        std::unordered_map<int, int> hash;
        hash.reserve(size);

        for (int i = 0; i < size; i++) {
            bool found = false;
            int j = i + 1;

            while (j < size) {
                if (nums2[j] > nums2[i]) {
                    hash.emplace(nums2[i], nums2[j]);
                    found = true;
                    break;
                }
                j++;
            }
            if (!found) {
                hash.emplace(nums2[i], -1);
            }
        }
        for (int& element : nums1) {
            element = hash[element];
        }
        return nums1;
    }
};
// @lc code=end
