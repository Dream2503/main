/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
    std::vector<int> queue;
    int left, right, size;

public:
    MyCircularQueue(const int k) : queue(k + 1), left(0), right(0), size(k + 1) {}

    bool enQueue(const int value) noexcept {
        if (!isFull()) {
            queue[right] = value;
            right = (right + 1) % size;
            return true;
        }
        return false;
    }

    bool deQueue() noexcept {
        if (!isEmpty()) {
            left = (left + 1) % size;
            return true;
        }
        return false;
    }

    int Front() const noexcept { return isEmpty() ? -1 : queue[left]; }

    int Rear() const noexcept { return isEmpty() ? -1 : queue[right ? right - 1 : size - 1]; }

    bool isEmpty() const noexcept { return right == left; }

    bool isFull() const noexcept { return (right + 1) % size == left; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
