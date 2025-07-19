/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& replaceElements(std::vector<int>& arr) {
        const int size = arr.size();
        int i = size - 2, value = arr[size - 1];
        arr[size - 1] = -1;

        while (i >= 0) {
            if (arr[i] > value) {
                std::swap(arr[i], value);
            } else {
                arr[i] = value;
            }
            i--;
        }
        return arr;
    }
};
// @lc code=end
