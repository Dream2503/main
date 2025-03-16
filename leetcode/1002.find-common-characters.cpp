/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        string res = words[0];
        int i, j, size1, size2;
        sort(res.begin(), res.end());

        for (string &word: words) {
            sort(word.begin(), word.end());
            if (res == word) {
                continue;
            }
            i = j = 0;
            size1 = res.size();
            size2 = word.size();

            while (i < size1 && j < size2) {
                while (i < size1 && res[i] < word[j]) {
                    res.erase(res.begin() + i);
                    size1--;
                }
                while (j < size2 && res[i] > word[j]) {
                    word.erase(word.begin() + j);
                    size2--;
                }
                i++; j++;
            }
            if (i < size1) {
                res.erase(res.begin() + i, res.end());
            }
            if (j < size2) {
                word.erase(word.begin() + j, word.end());
            }
            res = res.size() > word.size() ? word : res;
        }
        vector<string> rtn;
        rtn.reserve(res.size());
        transform(res.begin(), res.end(), back_inserter(rtn), [](char c){return string(1, c);});
        return rtn;
    }
};
// @lc code=end

