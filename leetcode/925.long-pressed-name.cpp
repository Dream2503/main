/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
#include <string>

class Solution {
public:
    bool isLongPressedName(const std::string& name, const std::string& typed) {
        const int name_len = name.length(), typed_len = typed.length();
        int i = 0, j = 0;

        while (i < name_len) {
            const char current_char = name[i++];
            int count = 1;

            while (i < name_len && name[i] == current_char) {
                count++;
                i++;
            }
            while (j < typed_len && typed[j] == current_char) {
                count--;
                j++;
            }
            if (count > 0) {
                return false;
            }
        }
        return j == typed_len;
    }
};
// @lc code=end
