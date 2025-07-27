/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

// @lc code=start
class Solution {
public:
    std::vector<int> distributeCandies(int candies, const int num_people) {
        std::vector res(num_people, 0);
        int i = 1;

        while (candies - i > 0) {
            res[(i - 1) % num_people] += i;
            candies -= i++;
        }
        if (candies > 0) {
            res[(i - 1) % num_people] += candies;
        }
        return res;
    }
};
// @lc code=end
