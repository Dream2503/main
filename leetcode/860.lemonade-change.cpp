/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(const std::vector<int>& bills) {
        int bill_5 = 0, bill_10 = 0;

        for (const int element : bills) {
            switch (element) {
            case 5:
                bill_5++;
                break;

            case 10:
                if (bill_5 < 1) {
                    return false;
                }
                bill_5--;
                bill_10++;
                break;

            case 20:
                if (bill_10 >= 1 && bill_5 >= 1) {
                    bill_10--;
                    bill_5--;
                } else if (bill_5 >= 3) {
                    bill_5 -= 3;
                } else {
                    return false;
                }
                break;

            default:
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
