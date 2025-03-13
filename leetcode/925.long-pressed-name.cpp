/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, current_size, typed_size;
        char current_char;

        while (name[i] != '\0') {
            current_char = name[i];
            current_size = 1;
            i++;

            while (name[i] != '\0' && name[i] == current_char) {
                current_size++; i++;
            }
            typed_size = 0;

            while (typed[j] != '\0' && typed[j] == current_char) {
                typed_size++; j++;
            }
            if (current_size > typed_size) {
                return false;
            }
        }
        return typed[j] == '\0';
    }
};
// @lc code=end

