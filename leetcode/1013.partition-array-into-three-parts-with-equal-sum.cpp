/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int>& arr) {
        const int size = arr.size();
        int target = std::accumulate(arr.begin(), arr.end(), 0), i = 0, j, sum = 0;

        if (target % 3 != 0) {
            return false;
        }
        target /= 3;

        for (j = 0; j < 3; j++) {
            sum = 0;

            while (i < size && sum != target) {
                sum += arr[i++];
            }
        }
        return j == 3 && sum == target;
    }
};
// @lc code=end
