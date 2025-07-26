/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int i;
        bool on_domain;
        unordered_set<string> set;

        for (string &email: emails) {
            string res;
            res.reserve(email.size());
            on_domain = false;
            i = 0;

            while (email[i] != '\0') {
                if (email[i] == '.' && !on_domain) {
                    i++;
                } else if (email[i] == '+' && !on_domain) {
                    while (email[i] != '@') {
                        i++;
                    }
                    on_domain = true;
                } else if (email[i] == '@') {
                    on_domain = true;
                    res.push_back(email[i++]);
                } else {
                    res.push_back(email[i++]);
                }
            }
            set.insert(res);
        }
        return set.size();
    }
};
// @lc code=end

