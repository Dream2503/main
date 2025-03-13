/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> look_up;
        int size = words.size(), i, j, word1_size, word2_size;
        string word1, word2;
        look_up.reserve(26);

        for (i = 0; i < 26; i++) {
            look_up[order[i]] = i;
        }
        for (i = 0; i < size - 1; i++) {
            word1_size = words[i].size(); word2_size = words[i + 1].size();
            j = 0;

            while (j < word1_size && j < word2_size && words[i][j] == words[i + 1][j]) {
                j++;
            }
            if (j == word1_size || j == word2_size) {
                if (words[i] != words[i + 1] && word1_size > word2_size) {
                    return false;
                }
            } else {
                if (look_up[words[i][j]] > look_up[words[i + 1][j]]) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

