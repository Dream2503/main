/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
class Solution {
public:
    int numUniqueEmails(const std::vector<std::string>& emails) {
        std::unordered_set<std::string> seen;
        std::string res;

        for (const std::string& email : emails) {
            res.clear();
            int i = 0;

            while (email[i] != '@') {
                if (email[i] == '.') {
                    i++;
                } else if (email[i] == '+') {
                    while (email[i] != '@') {
                        i++;
                    }
                } else {
                    res.push_back(email[i++]);
                }
            }
            std::copy(email.begin() + i, email.end(), std::back_inserter(res));
            seen.insert(std::move(res));
        }
        return seen.size();
    }
};
// @lc code=end
