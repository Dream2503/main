/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(const std::vector<int>& arr) {
        const int size = arr.size();
        int i = 0, j = size - 1;

        if (size < 3) {
            return false;
        }
        while (i < size - 1 && arr[i] < arr[i + 1]) {
            i++;
        }
        while (j > 0 && arr[j - 1] > arr[j]) {
            j--;
        }
        if (i != 0 && j != size - 1) {
            return i == j;
        }
        return false;
    }
};
// @lc code=end
