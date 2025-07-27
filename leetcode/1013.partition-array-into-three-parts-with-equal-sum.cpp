/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(const std::vector<int>& arr) {
        int target = std::accumulate(arr.begin(), arr.end(), 0);

        if (target % 3 != 0) {
            return false;
        }
        const int size = arr.size();
        int sum = 0, count = 0;
        target /= 3;

        for (int i = 0; i < size; i++) {
            sum += arr[i];

            if (sum == target) {
                count++;
                sum = 0;

                if (count == 2 && i < size - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
