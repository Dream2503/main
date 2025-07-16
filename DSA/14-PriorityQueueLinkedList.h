#pragma once
#include "05-SortedLinkedList.h"

template <typename type>
class PriorityQueueLinkedList {
    SortedLinkedList<type> queue;

public:
    PriorityQueueLinkedList(const std::string& mode = "max") {
        queue = SortedLinkedList<type>({}, mode == "max" ? "asc" : "dsc");
    }

    void push(const type& value) { queue.insert(value); }

    type pop() noexcept {
        if (is_empty()) {
            std::cerr << "The priority queue is empty" << std::endl;
            return type();
        }
        return queue.pop(queue.length() - 1);
    }

    constexpr type peek() const noexcept {
        if (is_empty()) {
            std::cerr << "The priority queue is empty" << std::endl;
            return type();
        }
        return queue[queue.length() - 1];
    }

    bool is_empty() const noexcept { return queue.is_empty(); }
};
