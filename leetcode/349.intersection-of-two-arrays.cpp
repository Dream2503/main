/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        nums1.resize(std::unique(nums1.begin(), nums1.end()) - nums1.begin());
        std::sort(nums2.begin(), nums2.end());
        nums2.resize(std::unique(nums2.begin(), nums2.end()) - nums2.begin());
        std::vector<int> res;
        std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(res));
        return res;

        // const int size1 = nums1.size(), size2 = nums2.size();
        // int i = 0, j = 0;
        //
        // while (i < size1 && j < size2) {
        //     if (nums1[i] < nums2[j]) {
        //         i++;
        //     } else if (nums1[i] > nums2[j]) {
        //         j++;
        //     } else {
        //         res.push_back(nums1[i]);
        //         j++;
        //     }
        // }
        // return res;
    }
};
// @lc code=end
