#pragma once
#include <iostream>

template <class type>
class DequeLinkedList {
    struct Node {
        type data;
        Node *prev, *next;
        Node(const type data = type(), Node* prev = nullptr, Node* next = nullptr) :
            data(data), prev(prev), next(next) {}
    };
    Node *left = nullptr, *right = nullptr;

public:
    DequeLinkedList() {}

    void clear() noexcept {
        if (left) {
            Node* current = left->next;

            while (current) {
                delete left;
                left = current;
                current = current->next;
            }
            left = right = nullptr;
        }
    }

    DequeLinkedList copy() const { return DequeLinkedList(*this); }

    void display() const noexcept { operator<<(std::cout, *this); }

    type delete_left() noexcept {
        type res;

        if (is_empty()) {
            std::cerr << "The deque is empty" << std::endl;
            return type();
        }
        if (!left->next) {
            res = left->data;
            delete left;
            left = right = nullptr;
            return res;
        }
        res = left->data;
        left = left->next;
        delete left->prev;
        return res;
    }

    type delete_right() noexcept {
        if (is_empty()) {
            std::cerr << "The deque is empty" << std::endl;
            return type();
        }
        if (!right->prev) {
            return delete_left();
        }
        type res = right->data;
        right = right->prev;
        delete right->next;
        return res;
    }

    void insert_left(const type& value) {
        left = new Node(value, nullptr, left);

        if (left->next) {
            left->next->prev = left;
        }
        if (!right) {
            right = left;
        }
    }

    void insert_right(const type& value) {
        right = new Node(value, right);

        if (right->prev) {
            right->prev->next = right;
        }
        if (!left) {
            left = right;
        }
    }

    constexpr bool is_empty() const noexcept { return !left; }

    constexpr type peek_left() const noexcept  {
        if (is_empty()) {
            std::cerr << "The deque is empty" << std::endl;
            return type();
        }
        return left->data;
    }

    constexpr type peek_right() const noexcept {
        if (is_empty()) {
            std::cerr << "The deque is empty" << std::endl;
            return type();
        }
        return right->data;
    }

    friend std::ostream& operator<<(std::ostream& out, const DequeLinkedList& deque) noexcept {
        if (!deque.is_empty()) {
            Node* current = deque.left;
            out << '[';

            while (current != deque.right) {
                out << current->data << ", ";
                current = current->next;
            }
            out << deque.right->data << ']' << std::endl;
        }
        return out;
    }
};
