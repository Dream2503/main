/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

#include <unordered_set>
// @lc code=start
class Solution {
public:
    std::vector<int>& relativeSortArray(std::vector<int>& arr1, const std::vector<int>& arr2) {
        std::unordered_map<int, int> hash;
        int i = 0;
        hash.reserve(arr2.size());

        for (const int element : arr2) {
            hash.emplace(element, i++);
        }
        std::sort(arr1.begin(), arr1.end(), [&hash](const int a, const int b) {
            const auto itr_a = hash.find(a), itr_b = hash.find(b);

            if (itr_a == hash.end()) {
                return false;
            }
            if (itr_b == hash.end()) {
                return true;
            }
            return hash[a] < hash[b];
        });
        const int last = arr2.back();
        i = arr1.size() - 1;

        while (i >= 0 && arr1[i] != last) {
            i--;
        }
        if (i < arr1.size() - 1) {
            std::sort(arr1.begin() + i + 1, arr1.end());
        }
        return arr1;
    }
};
// @lc code=end

