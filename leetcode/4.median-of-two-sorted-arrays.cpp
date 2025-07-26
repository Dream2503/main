/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        const int size1 = nums1.size(), size2 = nums2.size(), total = size1 + size2;
        const int target = total % 2 == 0 ? total / 2 - 1 : total / 2;
        int i = 0, j = 0, value = 0;

        if (!total) {
            return 0;
        }
        if (total == 1) {
            return size1 ? nums1[0] : nums2[0];
        }
        while (i < size1 && j < size2) {
            if (nums1[i] < nums2[j]) {
                value = nums1[i];
                i++;
            } else {
                value = nums2[j];
                j++;
            }
            if (i + j - 1 == target) {
                break;
            }
        }
        if (i + j - 1 != target) {
            while (i < size1 && i + j - 1 != target) {
                value = nums1[i];
                i++;
            }
            while (j < size2 && i + j - 1 != target) {
                value = nums2[j];
                j++;
            }
        }
        if (total % 2 == 0) {
            if (i < size1 && j < size2) {
                if (nums1[i] < nums2[j]) {
                    value += nums1[i];
                } else {
                    value += nums2[j];
                }
            } else {
                if (i < size1) {
                    value += nums1[i];
                } else {
                    value += nums2[j];
                }
            }
            return value / 2.0;
        }
        return value;
    }
};
// @lc code=end
