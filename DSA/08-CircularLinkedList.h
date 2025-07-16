#pragma once
#include <iostream>

template <typename type>
class CircularLinkedList {
protected:
    struct Node {
        type data;
        Node* next;
        Node(const type data = type(), Node* next = nullptr) : data(data), next(next) {}
    };
    Node* head = nullptr;

public:
    CircularLinkedList() {}

    CircularLinkedList(const std::initializer_list<type>& list) {
        Node* current = head = new Node(*list.begin());
        head->next = head;
        auto it = list.begin() + 1;

        while (it != list.end()) {
            current->next = new Node(*it, head);
            current = current->next;
            ++it;
        }
    }

    CircularLinkedList(const CircularLinkedList& list) {
        if (list.head) {
            Node *current1 = head = new Node(list.head->data), *current2 = list.head->next;
            head->next = head;

            do {
                current1->next = new Node(current2->data, head);
                current1 = current1->next;
                current2 = current2->next;
            } while (current2 != list.head);
        }
    }

    CircularLinkedList(const type* array, const size_t size) {
        if (size) {
            Node* current = head = new Node(array[0]);
            head->next = head;

            for (size_t i = 1; i < size; i++) {
                current->next = new Node(array[i], head);
                current = current->next;
            }
        }
    }

    constexpr CircularLinkedList(CircularLinkedList&& list) noexcept { std::swap(head, list.head); }

    void append(const type& value) {
        if (!head) {
            head = new Node(value);
            head->next = head;
        } else {
            Node* current = head;

            do {
                current = current->next;
            } while (current->next != head);
            current->next = new Node(value, head);
        }
    }

    constexpr double average() const noexcept { return sum() / static_cast<double>(length()); }

    void clear() noexcept {
        if (head) {
            Node *prev = nullptr, *current = head;

            do {
                prev = current;
                current = current->next;
                delete prev;
            } while (current != head);
            head = nullptr;
        }
    }

    constexpr bool contains(const type& value) const noexcept {
        Node* current = head;

        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);
        return false;
    }

    CircularLinkedList copy() const { return CircularLinkedList(*this); }

    constexpr size_t count(const type& value) const noexcept {
        Node* current = head;
        size_t cnt = 0;

        do {
            if (current->data == value) {
                cnt++;
            }
            current = current->next;
        } while (current != head);
        return cnt;
    }

    constexpr void display() const noexcept { operator<<(std::cout, *this); }

    void extend(CircularLinkedList list) {
        if (!head) {
            head = list.head;
        } else {
            Node* current = head;

            do {
                current = current->next;
            } while (current->next != head);
            current->next = list.head;

            do {
                current = current->next;
            } while (current->next != list.head);
            current->next = head;
        }
        list.head = nullptr;
    }

    constexpr size_t index(const type& value) const noexcept {
        Node* current = head;
        size_t cnt = 0;

        do {
            if (current->data == value) {
                return cnt;
            }
            current = current->next;
            cnt++;
        } while (current);
        return -1;
    }

    void insert(const size_t idx, const type& value) {
        if (!head) {
            throw std::out_of_range("Index out of range");
        }
        if (!head) {
            head = new Node(value);
            head->next = head;
            return;
        }
        if (idx == 0) {
            Node* current = head;

            do {
                current = current->next;
            } while (current->next != head);
            current->next = new Node(value);
            head = current;
            return;
        }
        Node* current = head;

        for (size_t i = 0; i < idx - 1; i++) {
            current = current->next;
        }
        if (current->next == head) {
            insert(idx, value);
        } else {
            Node* temp = current->next;
            current->next = new Node(value, temp);
        }
    }

    constexpr bool is_sorted() const noexcept {
        if (!head) {
            return true;
        }
        Node* current = head;

        if (head->data <= head->next->data) {
            do {
                if (current->data > current->next->data) {
                    return false;
                }
                current = current->next;
            } while (current->next != head);
        }
        if (head->data >= head->next->data) {
            do {
                if (current->data < current->next->data) {
                    return false;
                }
                current = current->next;
            } while (current->next != head);
        }
        return true;
    }

    constexpr size_t length() const noexcept {
        Node* current = head;
        size_t len = 0;

        do {
            len++;
            current = current->next;
        } while (current != head);
        return len;
    }

    constexpr void leftRotate() noexcept {
        if (!head || !head->next) {
            return;
        }
        head = head->next;
    }

    constexpr type max() const noexcept {
        if (!head) {
            return type();
        }
        Node* current = head->next;
        type max = head->data;

        do {
            if (current->data > max) {
                max = current->data;
            }
            current = current->next;
        } while (current != head);
        return max;
    }

    constexpr type min() const noexcept {
        if (!head) {
            return type();
        }
        Node* current = head->next;
        type min = head->data;

        do {
            if (current->data < min) {
                min = current->data;
            }
            current = current->next;
        } while (current != head);
        return min;
    }

    constexpr CircularLinkedList& operator=(CircularLinkedList list) {
        if (this != &list) {
            std::swap(head, list.head);
        }
        return *this;
    }

    CircularLinkedList operator+(const CircularLinkedList& list) const {
        CircularLinkedList list1(*this);
        list1.extend(list);
        return list1;
    }

    void operator+=(const CircularLinkedList& list) { extend(list); }

    CircularLinkedList operator*(const size_t num) const {
        if (!head || !num) {
            return CircularLinkedList();
        }
        if (num == 1) {
            return copy();
        }
        CircularLinkedList res(*this);
        Node* current = res.head;

        do {
            current = current->next;
        } while (current->next != res.head);

        for (size_t i = 1; i < num; i++) {
            CircularLinkedList list = copy();
            current->next = list.head;

            do {
                current = current->next;
            } while (current->next != list.head);
            list.head = nullptr;
        }
        current->next = res.head;
        return res;
    }

    void operator*=(const size_t num) { *this = *this * num; }

    constexpr bool operator==(const CircularLinkedList& list) const noexcept {
        Node *current1 = head, *current2 = list.head;

        do {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        } while (current1 != head && current2 != list.head);
        if (current1 != head || current2 != list.head) {
            return false;
        }
        return true;
    }

    constexpr bool operator!=(const CircularLinkedList& list) const noexcept { return !operator==(list); }

    constexpr friend std::ostream& operator<<(std::ostream& out, const CircularLinkedList& list) noexcept {
        if (list.head) {
            Node* current = list.head;
            out << '[';

            do {
                out << current->data << ", ";
                current = current->next;
            } while (current->next != list.head);
            out << current->data << ']' << std::endl;
        }
        return out;
    }

    constexpr type& operator[](const size_t idx) {
        if (!head) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;

        for (size_t i = 0; i < idx; i++) {
            current = current->next;
        }
        return current->data;
    }

    type pop(const size_t idx) {
        if (!head) {
            throw std::out_of_range("Index out of range");
        }
        Node *temp, *current;
        type value;

        if (!idx) {
            current = head;
            value = head->data;

            do {
                current = current->next;
            } while (current->next != head);
            temp = head;
            head = head->next;
            current->next = head;
            delete temp;
        } else {
            current = head;

            for (size_t i = 0; i < idx - 1; i++) {
                current = current->next;
            }
            temp = current->next;
            current->next = temp->next;
            value = temp->data;
            delete temp;
        }
        return value;
    }

    constexpr void rightRotate() noexcept {
        if (!head || !head->next) {
            return;
        }
        Node* current = head->next;

        do {
            current = current->next;
        } while (current->next != head);

        head = current;
    }

    void remove(const type& value) noexcept {
        if (!head) {
            return;
        }
        if (head->data == value) {
            Node* current = head->next;

            do {
                current = current->next;
            } while (current->next != head);
            const Node* temp = head;
            head = head->next;
            current->next = head;
            delete temp;
            return;
        }
        Node *prev = head, *current = prev->next;

        do {
            if (current->data == value) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
    }

    constexpr void reverse() noexcept {
        if (!head || !head->next) {
            return;
        }
        Node *end = head, *prev = head->next, *current = prev->next;

        do {
            prev->next = end;
            end = prev;
            prev = current;
            current = current->next;
        } while (current != head);
        prev->next = end;
        current->next = prev;
        head = prev;
    }

    constexpr void sort() noexcept {
        Node *q, *r = head;

        if (!head) {
            return;
        }
        for (Node* p = head; p->next != head; p = p->next) {
            for (q = head; q->next != r; q = q->next) {
                if (q->data > q->next->data) {
                    type temp = q->data;
                    q->data = q->next->data;
                    q->next->data = temp;
                }
            }
            r = q;
        }
    }

    constexpr type sum() const noexcept {
        if (!head) {
            return type();
        }
        type sum = head->data;
        Node* current = head->next;

        do {
            sum += current->data;
            current = current->next;
        } while (current != head);
        return sum;
    }

    ~CircularLinkedList() noexcept { clear(); }
};
