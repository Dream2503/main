/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
    std::queue<int> stack;

public:
    MyStack() : stack() {}

    void push(const int x) { stack.push(x); }

    int pop() noexcept {
        const int size = stack.size();

        for (int i = 1; i < size; i++) {
            stack.push(stack.front());
            stack.pop();
        }
        const int res = stack.front();
        stack.pop();
        return res;
    }

    int top() const noexcept { return stack.back(); }

    bool empty() const noexcept { return stack.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
