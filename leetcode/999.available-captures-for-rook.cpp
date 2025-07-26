/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 */

// @lc code=start
class Solution {
public:
    int numRookCaptures(const std::vector<std::vector<char>>& board) {
        std::pair<int, int> target;
        int i, j, res = 0;

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    target = {i, j};
                }
            }
        }
        i = target.first - 1;

        while (i >= 0) {
            if (board[i][target.second] == '.') {
                i--;
            } else {
                if (board[i][target.second] == 'p') {
                    res++;
                }
                break;
            }
        }
        i = target.first + 1;

        while (i < 8) {
            if (board[i][target.second] == '.') {
                i++;
            } else {
                if (board[i][target.second] == 'p') {
                    res++;
                }
                break;
            }
        }
        j = target.second - 1;

        while (j >= 0) {
            if (board[target.first][j] == '.') {
                j--;
            } else {
                if (board[target.first][j] == 'p') {
                    res++;
                }
                break;
            }
        }
        j = target.second + 1;

        while (j < 8) {
            if (board[target.first][j] == '.') {
                j++;
            } else {
                if (board[target.first][j] == 'p') {
                    res++;
                }
                break;
            }
        }
        return res;
    }
};
// @lc code=end
