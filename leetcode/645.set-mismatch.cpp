/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
    std::vector<int> findErrorNums(const std::vector<int>& nums) {
        const int size = nums.size();
        std::vector<int> res(2);
        std::vector<uint8_t> bits((size + 7) / 8, 0);

        for (int element : nums) {
            element--;

            if (!(bits[element / 8] & 1 << (element % 8))) {
                bits[element / 8] |= 1 << (element % 8);
            } else {
                res[0] = element + 1;
            }
        }
        for (int i = 0; i < size; i++) {
            if (!(bits[i / 8] & 1 << (i % 8))) {
                res[1] = i + 1;
                break;
            }
        }
        return res;
    }
};
// @lc code=end
