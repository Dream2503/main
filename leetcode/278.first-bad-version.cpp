/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(const int n) {
        if (n == 1) {
            return n;
        }
        int low = 1, high = n, mid = low + (high - low) / 2;

        while (low <= high) {
            if (isBadVersion(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            if (!isBadVersion(mid) && isBadVersion(mid + 1)) {
                return mid + 1;
            }
            mid = low + (high - low) / 2;
        }
        return 1;
    }
};
// @lc code=end
