/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int> res;
        std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(res));
        return res;

        // const int size1 = nums1.size(), size2 = nums2.size();
        // int i = 0, j = 0;

        // while (i < size1 && j < size2) {
        //     if (nums1[i] < nums2[j]) {
        //         i++;
        //     } else if (nums1[i] > nums2[j]) {
        //         j++;
        //     } else {
        //         res.push_back(nums1[i]);
        //         i++;
        //         j++;
        //     }
        // }
        // return res;
    }
};
// @lc code=end
