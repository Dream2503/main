/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        const size_t len = arr.size();
        int i = 0, res = -1;

        while (i < len) {
            if (i + arr[i] - 1 < len && arr[i] == arr[i + arr[i] - 1] &&
                (i + arr[i] < len && arr[i] != arr[i + arr[i]] || i + arr[i] >= len)) {
                res = std::max(arr[i], res);
                i += arr[i] - 1;
            }
            while (i + 1 < len && arr[i] == arr[i + 1]) {
                i++;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
