/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
class Solution {
public:
    bool checkIfExist(const std::vector<int>& arr) {
        const int size = arr.size();

        for (int i = 0; i < size; i++) {
            const double num = arr[i];

            for (int j = i + 1; j < size; j++) {
                if (arr[j]) {
                    const double res = num / arr[j];

                    if (res == 2 || res == 0.5) {
                        return true;
                    }
                } else if (!num) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
