/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(const std::string& moves) {
        std::array<int, 2> array{0, 0};

        for (const char ch : moves) {
            switch (ch) {
            case 'R':
                array[0]++;
                break;

            case 'L':
                array[0]--;
                break;

            case 'U':
                array[1]++;
                break;

            case 'D':
                array[1]--;
                break;
            default:
            }
        }
        return !array[0] && !array[1];
    }
};
// @lc code=end
