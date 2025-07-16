#pragma once
#include "04-LinkedList.h"

template <class type>
class SortedLinkedList : public LinkedList<type> {
    using Node = typename LinkedList<type>::Node;
    using LinkedList<type>::head;
    std::string mode = "asc";

    using LinkedList<type>::append;
    using LinkedList<type>::extend;
    using LinkedList<type>::is_sorted;
    using LinkedList<type>::leftRotate;
    using LinkedList<type>::leftShift;
    using LinkedList<type>::rightRotate;
    using LinkedList<type>::rightShift;
    using LinkedList<type>::sort;

public:
    SortedLinkedList() {}

    SortedLinkedList(const std::initializer_list<type>& list, const std::string& mode = "asc") {
        this->mode = mode;

        for (const type& element : list) {
            insert(element);
        }
    }

    SortedLinkedList(const SortedLinkedList& list) : LinkedList<type>(list), mode(list.mode) {}

    SortedLinkedList(const type* list, const size_t size, const std::string& mode = "asc") {
        this->mode = mode;

        for (size_t i = 0; i < size; i++)
            insert(list[i]);
    }

    constexpr SortedLinkedList(SortedLinkedList&& list) noexcept {
        std::swap(head, list.head);
        std::swap(mode, list.mode);
    }

    SortedLinkedList copy() const { return SortedLinkedList(*this); }

    constexpr size_t count(const type& value) const noexcept {
        Node* current = head;
        size_t cnt = 0;

        while (current) {
            if (current->data == value) {
                while (current && current->data == value) {
                    cnt++;
                    current = current->next;
                }
                return cnt;
            }
            current = current->next;
        }
        return cnt;
    }

    void extend(const SortedLinkedList& list) { *this += list; }

    void insert(const type& value) {
        if (!head) {
            head = new Node(value);
            return;
        }
        Node *current = head, *prev = nullptr;

        while (current) {
            if ((mode == "asc" && current->data >= value) || (mode == "dsc" && current->data <= value)) {
                if (!prev) {
                    prev = new Node(value, current);
                    head = prev;
                } else {
                    prev->next = new Node(value, current);
                }
                return;
            }
            prev = current;
            current = current->next;
        }
        prev->next = new Node(value);
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

    constexpr SortedLinkedList& operator=(SortedLinkedList list) {
        if (this != &list) {
            std::swap(head, list.head);
            std::swap(mode, list.mode);
        }
        return *this;
    }

    SortedLinkedList operator+(const SortedLinkedList& list) {
        if (!head) {
            return list;
        }
        if (!list.head) {
            return *this;
        }
        bool flag = false;

        if (mode != list.mode) {
            flag = true;
            reverse();
        }
        SortedLinkedList res;
        Node *current1 = head, *current2 = list.head;

        if ((mode == "asc" && current1->data < current2->data) || (mode == "dsc" && current1->data > current2->data)) {
            res.head = new Node(current1->data);
            current1 = current1->next;
        } else {
            res.head = new Node(current2->data);
            current2 = current2->next;
        }
        Node* current = res.head;

        while (current1 && current2) {
            if ((mode == "asc" && current1->data < current2->data) ||
                (mode == "dsc" && current1->data > current2->data)) {
                current->next = new Node(current1->data);
                current1 = current1->next;
            } else {
                current->next = new Node(current2->data);
                current2 = current2->next;
            }
            current = current->next;
        }
        while (current1) {
            current->next = new Node(current1->data);
            current = current->next;
            current1 = current1->next;
        }
        while (current2) {
            current->next = new Node(current2->data);
            current = current->next;
            current2 = current2->next;
        }
        if (flag) {
            reverse();
        }
        return res;
    }

    void operator+=(const SortedLinkedList& list) { *this = *this + list; }

    SortedLinkedList operator*(const size_t num) const {
        if (!head) {
            return SortedLinkedList();
        }
        if (num == 1) {
            return *this;
        }
        SortedLinkedList res;
        Node *current = res.head = new Node(head->data), *current1 = head->next;

        for (size_t i = 1; i < num; i++) {
            current->next = new Node(head->data);
            current = current->next;
        }

        while (current1) {
            for (size_t i = 0; i < num; i++) {
                current->next = new Node(current1->data);
                current = current->next;
            }
            current1 = current1->next;
        }
        return res;
    }

    void operator*=(const size_t num) { *this = *this * num; }

    constexpr bool operator==(const SortedLinkedList& list) const noexcept {
        if (mode != list.mode) {
            throw std::invalid_argument("Different type of sorted linked lists can't be compared");
        }
        return LinkedList<type>::operator==(list);
    }

    constexpr bool operator!=(const SortedLinkedList& list) const noexcept { return !operator==(list); }

    void reverse() noexcept {
        mode = mode == "asc" ? "dsc" : "asc";
        LinkedList<type>::reverse();
    }
};
