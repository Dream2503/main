/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(const std::string& ransomNote, const std::string& magazine) {
        static std::array<int, 26> hash;

        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        hash.fill(0);

        for (const char ch : ransomNote) {
            hash[ch - 'a']++;
        }
        for (const char ch : magazine) {
            hash[ch - 'a']--;
        }
        for (const int element : hash) {
            if (element > 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
