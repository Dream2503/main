/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_5 = 0, bill_10 = 0;

        for (int element: bills) {
            switch (element) {
                case 5:
                    bill_5++;
                    break;
                
                case 10:
                    if (bill_5 < 1) {
                        return false;
                    } else {
                        bill_5--;
                        bill_10++;
                    }
                    break;
                
                case 20:
                    if (bill_10 < 1) {
                        if (bill_5 < 3) {
                            return false;
                        } else {
                            bill_5 -= 3;
                        }
                    } else {
                        if (bill_5 < 1) {
                            return false;
                        } else {
                            bill_5--;
                            bill_10--;
                        }   
                    }
                    break;
            }
        }
        return true;
    }
};
// @lc code=end

