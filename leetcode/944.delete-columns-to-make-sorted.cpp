/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0, row = strs.size() - 1, column = strs[0].size();

        for (int j = 0; j < column; j++) {
            for (int i = 0; i < row; i++) {
                if (strs[i][j] > strs[i + 1][j]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

