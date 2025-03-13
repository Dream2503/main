/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int i = 0, k, size = s.size();
        
        if (size != goal.size()) {
            return false;
        }
        while (i < size && s[i] == goal[i]) {
            i++;
        }
        k = i++;

        if (k >= size) {
            sort(s.begin(), s.end());
            sort(goal.begin(), goal.end());
            
            if (s != goal) {
                return false;
            }
            for (i = 0; i < size; i++) {
                if (s[i] == s[i+1]) {
                    return true;
                }
            }
            return false;
        }

        while (i < size && s[i] == goal[i]) {
            i++;
        }
        if (i < size) {
            swap(s[k], s[i]);
            return s == goal;
        } else {
            return false;
        }
    }
};
// @lc code=end

