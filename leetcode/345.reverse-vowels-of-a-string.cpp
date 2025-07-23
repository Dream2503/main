/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
#define IS_VOWEL(ch)                                                                                                   \
    (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' ||           \
     ch == 'O' || ch == 'U')

class Solution {

public:
    std::string& reverseVowels(std::string& s) {
        int low = 0, high = s.size() - 1;

        while (low < high) {
            while (low < high && !IS_VOWEL(s[low])) {
                low++;
            }
            while (low < high && !IS_VOWEL(s[high])) {
                high--;
            }
            if (low < high)
                std::swap(s[low++], s[high--]);
        }
        return s;
    }
};
// @lc code=end
