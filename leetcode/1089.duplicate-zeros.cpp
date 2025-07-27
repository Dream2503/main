/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int size = arr.size(), cnt = 0, i = 0;

        while (i + cnt < size) {
            if (arr[i] == 0) {
                if (i + cnt == size - 1) {
                    arr[size - 1] = 0;
                    size--;
                    break;
                }
                cnt++;
            }
            i++;
        }
        int j = size - 1;
        i = size - cnt - 1;

        while (i >= 0) {
            if (arr[i] == 0) {
                arr[j--] = 0;
            }
            arr[j--] = arr[i--];
        }
    }
};
// @lc code=end
