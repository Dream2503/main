/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> commonChars(const std::vector<std::string>& words) {
        static std::array<int, 26> prev, next;
        const int size = words.size();
        prev.fill(0);
        next.fill(0);

        for (const char ch : words[0]) {
            prev[ch - 'a']++;
        }
        for (int i = 1; i < size; i++) {
            for (const char ch : words[i]) {
                if (prev[ch - 'a']) {
                    prev[ch - 'a']--;
                    next[ch - 'a']++;
                }
            }
            std::swap(prev, next);
            next.fill(0);
        }
        std::vector<std::string> res;

        for (int i = 0; i < 26; i++) {
            while (prev[i]) {
                res.emplace_back(1, 'a' + i);
                prev[i]--;
            }
        }
        return res;
    }
};
// @lc code=end
