/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
    int partition(int* array, int low, int high) {
        const int pivot = array[(low + high) / 2];

        while (low <= high) {
            while (array[low] < pivot) {
                low++;
            }
            while (array[high] > pivot) {
                high--;
            }
            if (low <= high) {
                std::swap(array[low++], array[high--]);
            }
        }
        return low;
    }

    void quick_sort(int* array, const int low, const int high) {
        if (low < high) {
            const int mid = partition(array, low, high);
            quick_sort(array, low, mid - 1);
            quick_sort(array, mid, high);
        }
    }

public:
    std::vector<int>& sortArray(std::vector<int>& nums) {
        quick_sort(nums.data(), 0, nums.size() - 1);
        return nums;
        // std::sort(nums.begin(), nums.end());
        // return nums;
    }
};
// @lc code=end
