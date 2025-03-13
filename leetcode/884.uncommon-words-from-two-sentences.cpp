/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string, int> word_count;
        stringstream ss(s1 + " " + s2);
        string word;

        while (ss >> word) {
            word_count[word]++;
        }
        for (pair<string, int> element: word_count) {
            if (element.second == 1) {
                res.push_back(element.first);
            }
        }
        return res;
    }
};
// @lc code=end

