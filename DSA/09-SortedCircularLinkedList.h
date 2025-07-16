#pragma once
#include "08-CircularLinkedList.h"

template <class type>
class SortedCircularLinkedList : public CircularLinkedList<type> {
    using Node = typename CircularLinkedList<type>::Node;
    using CircularLinkedList<type>::head;
    std::string mode = "asc";

    using CircularLinkedList<type>::append;
    using CircularLinkedList<type>::extend;
    using CircularLinkedList<type>::is_sorted;
    using CircularLinkedList<type>::leftRotate;
    using CircularLinkedList<type>::rightRotate;
    using CircularLinkedList<type>::sort;

public:
    SortedCircularLinkedList() {}

    SortedCircularLinkedList(const std::initializer_list<type>& list, const std::string& mode = "asc") {
        this->mode = mode;

        for (const type& element : list) {
            insert(element);
        }
    }

    SortedCircularLinkedList(const SortedCircularLinkedList& list) : CircularLinkedList<type>(list), mode(list.mode) {}

    SortedCircularLinkedList(const type* list, const size_t size, const std::string& mode = "asc") {
        this->mode = mode;

        for (size_t i = 0; i < size; i++)
            insert(list[i]);
    }

    constexpr SortedCircularLinkedList(SortedCircularLinkedList&& list) noexcept {
        std::swap(head, list.head);
        std::swap(mode, list.mode);
    }

    SortedCircularLinkedList copy() const { return SortedCircularLinkedList(*this); }

    constexpr size_t count(const type& value) const noexcept {
        Node* current = head;
        size_t cnt = 0;

        do {
            if (current->data == value) {
                do {
                    cnt++;
                    current = current->next;
                } while (current != head && current->data == value);
                return cnt;
            }
            current = current->next;
        } while (current != head);
        return cnt;
    }

    void extend(const SortedCircularLinkedList& list) { *this += list; }

    void insert(const type& value) {
        if (!head) {
            head = new Node(value);
            head->next = head;
            return;
        }
        Node *current = head, *prev = nullptr;

        do {
            if ((mode == "asc" && current->data >= value) || (mode == "dsc" && current->data <= value)) {
                if (!prev) {
                    prev = new Node(value, current);
                    do {
                        current = current->next;
                    } while (current->next != head);

                    head = prev;
                    current->next = head;
                } else {
                    prev->next = new Node(value, current);
                }
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
        prev->next = new Node(value, head);
    }

    constexpr type max() const noexcept {
        if (!head) {
            return type();
        }
        if (mode == "dsc") {
            return head->data;
        }
        Node* current = head;

        do {
            current = current->next;
        } while (current->next != head);
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

        do {
            current = current->next;
        } while (current->next != head);
        return current->data;
    }

    constexpr SortedCircularLinkedList& operator=(SortedCircularLinkedList list) {
        if (this != &list) {
            std::swap(head, list.head);
            std::swap(mode, list.mode);
        }
        return *this;
    }

    SortedCircularLinkedList operator+(const SortedCircularLinkedList& list) {
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
        SortedCircularLinkedList res;
        Node *current1 = head, *current2 = list.head;

        if ((mode == "asc" && current1->data < current2->data) || (mode == "dsc" && current1->data > current2->data)) {
            res.head = new Node(current1->data);
            current1 = current1->next;
        } else {
            res.head = new Node(current2->data);
            current2 = current2->next;
        }
        Node* current = res.head;
        res.head->next = res.head;

        do {
            if ((mode == "asc" && current1->data < current2->data) ||
                (mode == "dsc" && current1->data > current2->data)) {
                current->next = new Node(current1->data, res.head);
                current1 = current1->next;
            } else {
                current->next = new Node(current2->data, res.head);
                current2 = current2->next;
            }
            current = current->next;
        } while (current1 != head && current2 != list.head);
        while (current1 != head){
            current->next = new Node(current1->data, res.head);
            current = current->next;
            current1 = current1->next;
        }
        while (current2 != list.head) {
            current->next = new Node(current2->data, res.head);
            current = current->next;
            current2 = current2->next;
        }
        if (flag) {
            reverse();
        }
        return res;
    }

    void operator+=(const SortedCircularLinkedList& list) { *this = *this + list; }

    SortedCircularLinkedList operator*(const size_t num) const {
        if (!head || !num) {
            return SortedCircularLinkedList();
        }
        if (num == 1) {
            return *this;
        }
        SortedCircularLinkedList res;
        Node *current = res.head = new Node(head->data), *current1 = head->next;
        res.head->next = res.head;

        for (size_t i = 1; i < num; i++) {
            current->next = new Node(head->data, res.head);
            current = current->next;
        }

        do {
            for (size_t i = 0; i < num; i++) {
                current->next = new Node(current1->data, res.head);
                current = current->next;
            }
            current1 = current1->next;
        } while (current1 != head);
        return res;
    }

    void operator*=(const size_t num) { *this = *this * num; }

    constexpr bool operator==(const SortedCircularLinkedList& list) const noexcept {
        if (mode != list.mode) {
            throw std::invalid_argument("Different type of sorted linked lists can't be compared");
        }
        return CircularLinkedList<type>::operator==(list);
    }

    constexpr bool operator!=(const SortedCircularLinkedList& list) const noexcept { return !operator==(list); }

    void reverse() noexcept {
        mode = mode == "asc" ? "dsc" : "asc";
        CircularLinkedList<type>::reverse();
    }
};
