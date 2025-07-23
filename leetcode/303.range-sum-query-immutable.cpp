/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
    std::vector<int>& vec;

public:
    NumArray(std::vector<int>& nums) : vec(nums) {
        const int temp = vec.back();
        std::exclusive_scan(vec.begin(), vec.end(), vec.begin(), 0);
        vec.push_back(vec.back() + temp);
    }

    int sumRange(const int left, const int right) const noexcept { return vec[right + 1] - vec[left]; }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
