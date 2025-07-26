/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(const std::vector<std::vector<char>>& board) {
        uint16_t hash = 0;

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                for (int m = i; m < i + 3; m++) {
                    for (int n = j; n < j + 3; n++) {
                        if (board[m][n] != '.') {
                            const int shift = board[m][n] - '1';

                            if (hash & (1 << shift)) {
                                return false;
                            }
                            hash |= 1 << shift;
                        }
                    }
                }
                hash = 0;
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    const int shift = board[i][j] - '1';

                    if (hash & (1 << shift)) {
                        return false;
                    }
                    hash |= 1 << shift;
                }
            }
            hash = 0;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    const int shift = board[j][i] - '1';

                    if (hash & (1 << shift)) {
                        return false;
                    }
                    hash |= 1 << shift;
                }
            }
            hash = 0;
        }
        return true;
    }
};
// @lc code=end
