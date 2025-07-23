/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
    std::stack<int> queue1, queue2;

public:
    MyQueue() : queue1(), queue2() {}

    void push(const int x) { queue1.push(x); }

    int pop() noexcept {
        const int res = peek();
        queue2.pop();
        return res;
    }

    int peek() noexcept {
        if (queue2.empty()) {
            while (!queue1.empty()) {
                queue2.push(queue1.top());
                queue1.pop();
            }
        }
        return queue2.top();
    }

    bool empty() const noexcept { return queue1.empty() && queue2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
