/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(const std::string& s) {
        static std::array<int, 26> hash;
        const int len = s.length();
        hash.fill(len);

        for (int i = 0; i < len; i++) {
            if (hash[s[i] - 'a'] == len) {
                hash[s[i] - 'a'] = i;
            } else {
                hash[s[i] - 'a'] = -i;
            }
        }
        int res = len;

        for (int i = 0; i < 26; i++) {
            if (hash[i] >= 0) {
                res = std::min(res, hash[i]);
            }
        }
        return res == len ? -1 : res;
    }
};
// @lc code=end
