/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int size = deck.size(), cnt = 0, i = 0, k, current;

        while (i < size && deck[i] == deck[0]) {
            cnt++; i++;
        }
        if (cnt <= 1) {
            return false;
        }
        while (i < size) {
            k = i++;
            current = 1;

            while (i < size && deck[i] == deck[k]) {
                current++; i++;
            }
            cnt = gcd(current, cnt);

            if (cnt == 1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

