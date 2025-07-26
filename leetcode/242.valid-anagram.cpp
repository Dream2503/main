/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(const std::string& s, const std::string& t) {
        static std::array<int, 26> array;
        std::fill(array.begin(), array.end(), 0);

        for (const char ch : s) {
            array[ch - 'a']++;
        }
        for (const char ch : t) {
            array[ch - 'a']--;
        }
        for (const int element : array) {
            if (element) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
