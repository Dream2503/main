/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    int size;

public:
    KthLargest(const int k, const std::vector<int>& nums) : size(k) {
        std::vector<int> temp;
        temp.reserve(k);
        heap = std::priority_queue(std::greater<int>(), std::move(temp));

        for (const int element : nums) {
            add(element);
        }
    }

    int add(const int val) {
        if (heap.size() < size) {
            heap.push(val);
        } else if (val > heap.top()) {
            heap.pop();
            heap.push(val);
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
