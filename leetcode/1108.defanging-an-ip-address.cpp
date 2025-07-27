/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start
class Solution {
public:
    std::string& defangIPaddr(std::string& address) {
        const int len = address.length() + 6;
        address.resize(len);
        int i = len - 7, j = len - 1;

        while (i >= 0) {
            if (address[i] == '.') {
                address[j--] = ']';
                address[j--] = address[i--];
                address[j--] = '[';
            } else {
                address[j--] = address[i--];
            }
        }
        return address;
    }
};
// @lc code=end

