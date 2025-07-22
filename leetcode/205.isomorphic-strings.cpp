/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(std::string& s, std::string& t) {
        static std::array<char, 95> hash;
        hash.fill(0);
        const int len = s.length();

        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < len; i++) {
                if (!hash[s[i] - 32]) {
                    hash[s[i] - 32] = t[i];
                } else if (hash[s[i] - 32] != t[i]) {
                    return false;
                }
            }
            hash.fill(0);
            std::swap(s, t);
        }
        return true;
    }
};
// @lc code=end
