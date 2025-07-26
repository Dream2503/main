/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(const std::vector<char>& letters, const char target) {
        const auto itr = std::upper_bound(letters.begin(), letters.end(), target);

        if (itr == letters.end()) {
            return letters[0];
        }
        return *itr;
    }
};
// @lc code=end
