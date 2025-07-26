/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hash;

        for (std::string& element : strs) {
            std::string temp(element);
            sort(temp.begin(), temp.end());
            hash[temp].push_back(std::move(element));
        }
        std::vector<std::vector<std::string>> res;
        res.reserve(hash.size());

        for (auto& [key, value] : hash) {
            res.push_back(std::move(value));
        }
        return res;
    }
};

// @lc code=end
