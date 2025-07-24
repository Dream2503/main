/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
class Solution {
public:
    std::string licenseKeyFormatting(const std::string& s, const int k) {
        int size = 0;

        for (const char ch : s) {
            if (ch != '-') {
                size++;
            }
        }
        const int first = size % k, len = s.length();
        int i = 0, j = 0;
        std::string res;
        res.reserve(size + size / k);

        while (j < first) {
            if (s[i] != '-') {
                res.push_back(toupper(s[i]));
                j++;
            }
            i++;
        }
        if (first) {
            res.push_back('-');
        }

        while (i < len) {
            j = 0;

            while (j < k && i < len) {
                if (s[i] != '-') {
                    res.push_back(toupper(s[i]));
                    j++;
                }
                i++;
            }
            if (i < len) {
                res.push_back('-');
            }
        }
        while (!res.empty() && res.back() == '-') {
            res.pop_back();
        }
        return res;
    }
};
// @lc code=end
