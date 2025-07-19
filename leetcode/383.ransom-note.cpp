/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(const std::string& ransomNote, const std::string& magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        int array[26] = {0};

        for (const char ch : ransomNote) {
            array[ch - 'a']++;
        }
        for (const char ch : magazine) {
            array[ch - 'a']--;
        }
        for (const int element : array) {
            if (element > 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
