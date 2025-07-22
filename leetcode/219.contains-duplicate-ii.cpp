/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(const std::vector<int>& arr, const int k) {
        const int size = arr.size();
        std::unordered_map<int, int> hash;

        for (int i = 0; i < size; i++) {
            if (hash.find(arr[i]) != hash.end()) {
                if (i - hash[arr[i]] <= k) {
                    return true;
                }
                hash[arr[i]] = i;
            }
            hash.emplace(arr[i], i);
        }
        return false;
    }
};
// @lc code=end
