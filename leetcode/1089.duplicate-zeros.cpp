/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        const int size = arr.size();
        std::vector<int> temp;
        temp.reserve(size);
        int i = 0, j = 0;

        while (i < size && j < size) {
            if (arr[j]) {
                temp.push_back(arr[j++]);
            } else {
                temp.push_back(0);
                i++;

                if (i < size) {
                    temp.push_back(arr[j++]);
                }
            }
            i++;
        }
        if (i != j) {
            arr = std::move(temp);
        }
    }
};
// @lc code=end
