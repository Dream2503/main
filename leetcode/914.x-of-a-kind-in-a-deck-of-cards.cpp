/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(std::vector<int>& deck) {
        const int size = deck.size();
        std::sort(deck.begin(), deck.end());
        int cnt = 0, i = 0;

        while (i < size && deck[i] == deck[0]) {
            cnt++;
            i++;
        }
        if (cnt <= 1) {
            return false;
        }
        while (i < size) {
            const int k = i++;
            int current = 1;

            while (i < size && deck[i] == deck[k]) {
                current++;
                i++;
            }
            cnt = std::gcd(current, cnt);

            if (cnt == 1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
