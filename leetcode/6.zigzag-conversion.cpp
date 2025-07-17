/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    std::string& convert(std::string& s, const int numRows) {
        const int len = s.length();
        int k = 0;
        bool forwards = true;
        std::string all[numRows];

        if (numRows == 1) {
            return s;
        }
        for (const char ch : s) {
            all[k].push_back(ch);

            if (forwards) {
                k++;
                if (k == numRows) {
                    forwards = false;
                    k -= 2;
                }
            } else {
                k--;

                if (k == -1) {
                    forwards = true;
                    k += 2;
                }
            }
        }
        k = 0;

        for (const std::string& str : all) {
            for (const char ch : str) {
                s[k] = ch;
                k++;
            }
        }
        return s;
    }
};
// @lc code=end
