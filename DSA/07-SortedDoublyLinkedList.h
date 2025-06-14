#pragma once
#include "06-DoublyLinkedList.h"

template <class type>
class SortedDoublyLinkedList : public DoublyLinkedList<type> {
    using Node = typename DoublyLinkedList<type>::Node;
    using DoublyLinkedList<type>::head;
    std::string mode = "asc";

    constexpr bool operators(const SortedDoublyLinkedList& array, const std::string& opr) const noexcept {
        if (mode != array.mode) {
            throw std::invalid_argument("Different type of sorted arrays can't be compared");
        }
        return DoublyLinkedList<type>::operators(array, opr);
    }

    using DoublyLinkedList<type>::append;
    using DoublyLinkedList<type>::extend;
    using DoublyLinkedList<type>::is_sorted;
    using DoublyLinkedList<type>::leftRotate;
    using DoublyLinkedList<type>::leftShift;
    using DoublyLinkedList<type>::rightRotate;
    using DoublyLinkedList<type>::rightShift;
    using DoublyLinkedList<type>::sort;

public:
    SortedDoublyLinkedList() {}

    SortedDoublyLinkedList(const std::initializer_list<type>& list, const std::string& mode = "asc") {
        this->mode = mode;

        for (const type& element : list) {
            insert(element);
        }
    }

    SortedDoublyLinkedList(const SortedDoublyLinkedList& list) : DoublyLinkedList<type>(list), mode(list.mode) {}

    SortedDoublyLinkedList(const type* list, const size_t size, const std::string& mode = "asc") {
        this->mode = mode;

        for (size_t i = 0; i < size; i++)
            insert(list[i]);
    }

    SortedDoublyLinkedList(SortedDoublyLinkedList&& list) noexcept {
        head = list.head;
        list.head = nullptr;
    }

    SortedDoublyLinkedList copy() const { return SortedDoublyLinkedList(*this); }

    constexpr size_t count(const type& value) const noexcept {
        Node* current = head;
        size_t cnt = 0;

        while (current) {
            if (current->data == value) {
                while (current->data == value) {
                    cnt++;
                    current = current->next;
                }
                return cnt;
            }
            current = current->next;
        }
        return cnt;
    }

    void extend(const SortedDoublyLinkedList& list) { *this += list; }

    void insert(const type& value) {
        if (!head) {
            head = new Node(value);
            return;
        }
        Node *current = head, *prev = nullptr;

        while (current) {
            if ((mode == "asc" && current->data >= value) || (mode == "dsc" and current->data <= value)) {
                if (!prev) {
                    prev = new Node(value, nullptr, current);
                    current->prev = prev;
                    head = prev;
                } else {
                    prev->next = new Node(value, prev, current);
                    current->prev = prev->next;
                }
                return;
            }
            prev = current;
            current = current->next;
        }
        prev->next = new Node(value, prev);
    }

    constexpr type max() const noexcept {
        if (!head) {
            return type();
        }
        if (mode == "dsc") {
            return head->data;
        }
        Node* current = head;

        while (current->next) {
            current = current->next;
        }
        return current->data;
    }

    constexpr type min() const noexcept {
        if (!head) {
            return type();
        }
        if (mode == "asc") {
            return head->data;
        }
        Node* current = head;

        while (current->next) {
            current = current->next;
        }
        return current->data;
    }

    SortedDoublyLinkedList& operator=(SortedDoublyLinkedList list) {
        if (this != &list) {
            std::swap(head, list.head);
            std::swap(mode, list.mode);
        }
        return *this;
    }

    SortedDoublyLinkedList operator+(const SortedDoublyLinkedList& list) {
        if (!head) {
            return list;
        }
        if (!list.head) {
            return *this;
        }
        if (mode != list.mode) {
            reverse();
        }
        SortedDoublyLinkedList result;
        Node *current1 = head, *current2 = list.head;

        if ((mode == "asc" && current1->data < current2->data) || (mode == "dsc" && current1->data > current2->data)) {
            result.head = new Node(current1->data);
            current1 = current1->next;
        } else {
            result.head = new Node(current2->data);
            current2 = current2->next;
        }
        Node* current = result.head;

        while (current1 && current2) {
            if ((mode == "asc" && current1->data < current2->data) ||
                (mode == "dsc" && current1->data > current2->data)) {
                current->next = new Node(current1->data, current);
                current1 = current1->next;
            } else {
                current->next = new Node(current2->data, current);
                current2 = current2->next;
            }
            current = current->next;
        }
        while (current1) {
            current->next = new Node(current1->data, current, current1->next);
            current = current->next;
            current1 = current1->next;
        }
        while (current2) {
            current->next = new Node(current2->data, current, current2->next);
            current = current->next;
            current2 = current2->next;
        }
        return result;
    }

    void operator+=(const SortedDoublyLinkedList& list) { *this = *this + list; }

    SortedDoublyLinkedList operator*(const size_t num) const {
        if (!head) {
            return SortedDoublyLinkedList();
        }
        if (num == 1) {
            return *this;
        }
        SortedDoublyLinkedList result;
        Node *current = result.head = new Node(head->data), *current1 = head->next;

        for (size_t i = 1; i < num; i++) {
            current->next = new Node(head->data, current);
            current = current->next;
        }

        while (current1) {
            for (size_t i = 0; i < num; i++) {
                current->next = new Node(current1->data, current);
                current = current->next;
            }
            current1 = current1->next;
        }
        return result;
    }

    void operator*=(const size_t num) { *this = *this * num; }

    void reverse() noexcept {
        mode = mode == "asc" ? "dsc" : "asc";
        DoublyLinkedList<type>::reverse();
    }
};
