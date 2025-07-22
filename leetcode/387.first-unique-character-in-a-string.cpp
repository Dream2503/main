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
        hash.fill(0);

        for (int i = 0; i < len; i++) {
            hash[s[i] - 'a']++;
        }
        int res = INT32_MAX;

        for (int i = 0; i < 26; i++) {
            if (hash[i] == 1) {
                res = std::min(res, static_cast<int>(s.find(i + 'a')));
            }
        }
        return res == INT32_MAX ? -1 : res;
    }
};
// @lc code=end
