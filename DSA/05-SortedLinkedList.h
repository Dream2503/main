#pragma once
#include "04-LinkedList.h"
using namespace std;

template <class type>
class SortedLinkedList : public LinkedList<type> {
    using Node = typename LinkedList<type>::Node;
    using LinkedList<type>::head;
    string mode = "asc";


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

    SortedLinkedList(const initializer_list<type>& list, const std::string& mode = "asc") {
        this->mode = mode;

        for (const type& element : list) {
            insert(element);
        }
    }

    SortedLinkedList(const SortedLinkedList& list) : LinkedList<type>(list), mode(list.mode) {}

    SortedLinkedList(const type* list, const int size, const std::string& mode = "asc") {
        this->mode = mode;

        for (int i = 0; i < size; i++)
            this->insert(list[i]);
    }

    SortedLinkedList copy() const { return SortedLinkedList(*this); }

    constexpr int count(const type& value) const noexcept {
        Node* current = head;
        int cnt = 0;

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

    void extend(const SortedLinkedList& list) { *this += list; }

    constexpr int index(const type& value) const noexcept {
        Node* current = head;
        int cnt = 0;

        while (current) {
            if (current->data == value) {
                return cnt;
            }
            current = current->next;
            cnt++;
        }
        return -1;
    }

    void insert(type value) {
        if (!head) {
            head = new Node(value);
            return;
        }
        Node *current = this->head, *prev = nullptr;

        while (current) {
            if ((mode == "asc" && current->data >= value) || (mode == "dsc" and current->data <= value)) {
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

    SortedLinkedList operator+(const SortedLinkedList& list) {
        if (!head) {
            return list;
        }
        if (!list.head) {
            return *this;
        }
        if (mode != list.mode) {
            reverse();
        }
        SortedLinkedList result;
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
                current->next = new Node(current1->data);
                current1 = current1->next;
            } else {
                current->next = new Node(current2->data);
                current2 = current2->next;
            }
            current = current->next;
        }
        while (current1) {
            current->next = new Node(current1->data, current1->next);
            current = current->next;
            current1 = current1->next;
        }
        while (current2) {
            current->next = new Node(current2->data, current2->next);
            current = current->next;
            current2 = current2->next;
        }
        return result;
    }

    void operator+=(const SortedLinkedList& list) { *this = *this + list; }

    SortedLinkedList operator*(const int num) const {
        if (num < 0) {
            throw std::invalid_argument("Invalid Number");
        }
        if (!head) {
            return SortedLinkedList();
        }
        if (num == 1) {
            return *this;
        }
        SortedLinkedList result;
        Node *current = result.head = new Node(head->data), *current1 = head->next;

        for (int i = 1; i < num; i++) {
            current->next = new Node(head->data);
            current = current->next;
        }

        while (current1) {
            for (int i = 0; i < num; i++) {
                current->next = new Node(current1->data);
                current = current->next;
            }
            current1 = current1->next;
        }
        return result;
    }

    void operator*=(const int num) { *this = *this * num; }

    void reverse() noexcept {
        mode = mode == "asc" ? "dsc" : "asc";
        LinkedList<type>::reverse();
    }

    SortedLinkedList(SortedLinkedList&&) noexcept = default;
    SortedLinkedList& operator=(SortedLinkedList&&) noexcept = default;
};
