/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res;
        int size = s.size() + 1, low = 0, high = size - 1;
        res.reserve(size);
        s.push_back(*(s.end() - 1));

        for (char ch: s) {
            if (ch == 'I') {
                res.push_back(low);
                low = (low + 1) % size;
            } else {
                res.push_back(high--);
                
                if (high == -1) {
                    high = size;
                }
            }
        }
        return res;
    }
};
// @lc code=end

