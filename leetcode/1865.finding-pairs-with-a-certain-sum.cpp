/*
 * @lc app=leetcode id=1865 lang=cpp
 *
 * [1865] Finding Pairs With a Certain Sum
 */

// @lc code=start
class FindSumPairs {
    std::vector<int>&nums1, &nums2;
    std::unordered_map<int, int> hash;

public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) : nums1(nums1), nums2(nums2), hash(nums2.size()) {
        for (const int element : nums2) {
            hash[element]++;
        }
    }

    constexpr void add(const int index, const int val) noexcept {
        hash[nums2[index]]--;

        if (hash[nums2[index]] == 0) {
            hash.erase(nums2[index]);
        }
        nums2[index] += val;
        hash[nums2[index]]++;
    }

    constexpr int count(const int tot) noexcept {
        int res = 0;

        for (const int element : nums1) {
            const int difference = tot - element;

            if (hash.count(difference)) {
                res += hash[difference];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// @lc code=end
