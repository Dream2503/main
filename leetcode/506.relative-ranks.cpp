/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution {
public:
    std::vector<std::string> findRelativeRanks(const std::vector<int>& score) {
        const int size = score.size();
        std::vector<std::string> res;
        std::vector<int> copy = score;
        res.reserve(size);
        std::sort(copy.begin(), copy.end(), std::greater<int>());

        for (int i = 0; i < size; i++) {
            const int idx = std::lower_bound(copy.begin(), copy.end(), score[i], std::greater<int>()) - copy.begin();

            switch (idx) {
            case 0:
                res.push_back("Gold Medal");
                break;
            case 1:
                res.push_back("Silver Medal");
                break;
            case 2:
                res.push_back("Bronze Medal");
                break;
            default:
                res.push_back(std::to_string(idx + 1));
            }
        }
        return res;
    }
};
// @lc code=end
