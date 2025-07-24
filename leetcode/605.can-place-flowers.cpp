/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        const int size = flowerbed.size();
        int i = 0;

        if (!flowerbed[0] && size == 1) {
            return true;
        }
        if (!flowerbed[0] && !flowerbed[1]) {
            flowerbed[0] = 1;
            n--;
            i++;
        }
        if (!flowerbed[size - 1] && !flowerbed[size - 2]) {
            n--;
        }
        while (i < size - 3) {
            if (!flowerbed[i] && !flowerbed[i + 1] && !flowerbed[i + 2]) {
                n--;
                i++;
            }
            i++;
        }

        return n < 1;
    }
};
// @lc code=end
