#pragma once
#include <iostream>

template <typename type>
class LinkedList {
protected:
    struct Node {
        type data;
        Node* next;
        Node(const type data = type(), Node* next = nullptr) : data(data), next(next) {}
    };
    Node* head = nullptr;

public:
    LinkedList() {}

    LinkedList(const std::initializer_list<type>& list) {
        Node* current = head = new Node(*list.begin());
        auto it = list.begin() + 1;

        while (it != list.end()) {
            current->next = new Node(*it);
            current = current->next;
            ++it;
        }
    }

    LinkedList(const LinkedList& list) {
        if (list.head) {
            Node *current1 = head = new Node(list.head->data), *current2 = list.head->next;

            while (current2) {
                current1->next = new Node(current2->data);
                current1 = current1->next;
                current2 = current2->next;
            }
        }
    }

    LinkedList(const type* array, const size_t size) {
        if (size) {
            Node* current = head = new Node(array[0]);

            for (size_t i = 1; i < size; i++) {
                current->next = new Node(array[i]);
                current = current->next;
            }
        }
    }

    constexpr LinkedList(LinkedList&& list) noexcept { std::swap(head, list.head); }

    void append(const type& value) {
        if (!head) {
            head = new Node(value);
        } else {
            Node* current = head;

            while (current->next) {
                current = current->next;
            }
            current->next = new Node(value);
        }
    }

    constexpr double average() const noexcept { return sum() / static_cast<double>(length()); }

    void clear() noexcept {
        if (head) {
            Node* current = head->next;

            while (current) {
                delete head;
                head = current;
                current = current->next;
            }
            delete head;
            head = nullptr;
        }
    }

    constexpr bool contains(const type& value) const noexcept {
        Node* current = head;

        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    LinkedList copy() const { return LinkedList(*this); }

    constexpr size_t count(const type& value) const noexcept {
        Node* current = head;
        size_t cnt = 0;

        while (current) {
            if (current->data == value) {
                cnt++;
            }
            current = current->next;
        }
        return cnt;
    }

    constexpr void display() const noexcept { operator<<(std::cout, *this); }

    void extend(const LinkedList list) {
        if (!head) {
            head = list.head;
        } else {
            Node* current = head;

            while (current->next) {
                current = current->next;
            }
            current->next = list.head;
        }
        list.head = nullptr;
    }

    constexpr size_t index(const type& value) const noexcept {
        Node* current = head;
        size_t cnt = 0;

        while (current) {
            if (current->data == value) {
                return cnt;
            }
            current = current->next;
            cnt++;
        }
        return -1;
    }

    void insert(const size_t idx, const type& value) {
        if (!head) {
            throw std::out_of_range("Index out of range");
        }
        if (!head) {
            head = new Node(value);
            return;
        }
        if (idx == 0) {
            Node* current = head;
            head = new Node(value, current);
            return;
        }
        Node* current = head;

        for (size_t i = 0; i < idx - 1; i++) {
            if (current->next) {
                current = current->next;
            } else {
                throw std::out_of_range("Index out of range");
            }
        }
        Node* temp = current->next;
        current->next = new Node(value, temp);
    }

    constexpr bool is_sorted() const noexcept {
        if (!head) {
            return true;
        }
        Node* current = head;

        if (head->data <= head->next->data) {
            while (current->next) {
                if (current->data > current->next->data) {
                    return false;
                }
                current = current->next;
            }
        }
        if (head->data >= head->next->data) {
            while (current->next) {
                if (current->data < current->next->data) {
                    return false;
                }
                current = current->next;
            }
        }
        return true;
    }

    constexpr size_t length() const noexcept {
        Node* current = head;
        size_t len = 0;

        while (current) {
            len++;
            current = current->next;
        }
        return len;
    }

    constexpr void leftRotate() noexcept {
        if (!head || !head->next) {
            return;
        }
        Node *element = head, *current = head->next;
        head = head->next;

        while (current->next) {
            current = current->next;
        }
        current->next = element;
        element->next = nullptr;
    }

    void leftShift() {
        if (!head) {
            return;
        }
        if (!head->next) {
            head->data = type();
            return;
        }
        pop(0);
        Node* current = head;

        while (current->next) {
            current = current->next;
        }
        current->next = new Node;
    }

    constexpr type max() const noexcept {
        if (!head) {
            return type();
        }
        Node* current = head->next;
        type max = head->data;

        while (current) {
            if (current->data > max) {
                max = current->data;
            }
            current = current->next;
        }
        return max;
    }

    constexpr type min() const noexcept {
        if (!head) {
            return type();
        }
        Node* current = head->next;
        type min = head->data;

        while (current) {
            if (current->data < min) {
                min = current->data;
            }
            current = current->next;
        }
        return min;
    }

    constexpr LinkedList& operator=(LinkedList list) {
        if (this != &list) {
            std::swap(head, list.head);
        }
        return *this;
    }

    LinkedList operator+(const LinkedList& list) const {
        LinkedList list1(*this);
        list1.extend(list);
        return list1;
    }

    void operator+=(const LinkedList& list) { extend(list); }

    LinkedList operator*(const size_t num) const {
        if (!head || !num) {
            return LinkedList();
        }
        if (num == 1) {
            return copy();
        }
        LinkedList res(*this);
        Node* current = res.head;

        for (size_t i = 1; i < num; i++) {
            LinkedList list = copy();

            while (current->next) {
                current = current->next;
            }
            current->next = list.head;
            list.head = nullptr;
        }
        return res;
    }

    void operator*=(const size_t num) { *this = *this * num; }

    constexpr bool operator==(const LinkedList& list) const noexcept {
        Node *current1 = head, *current2 = list.head;

        while (current1 && current2) {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        if (current1 || current2) {
            return false;
        }
        return true;
    }

    constexpr bool operator!=(const LinkedList& list) const noexcept { return !operator==(list); }

    constexpr friend std::ostream& operator<<(std::ostream& out, const LinkedList& list) noexcept {
        if (list.head) {
            Node* current = list.head;
            out << '[';

            while (current->next) {
                out << current->data << ", ";
                current = current->next;
            }
            out << current->data << ']' << std::endl;
        }
        return out;
    }

    constexpr type& operator[](const size_t idx) {
        if (!head) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;

        for (size_t i = 0; i < idx && current; i++) {
            current = current->next;
        }
        if (current) {
            return current->data;
        }
        throw std::out_of_range("Index out of range");
    }

    type pop(const size_t idx) {
        if (!head) {
            throw std::out_of_range("Index out of range");
        }
        Node* temp;
        type value;

        if (!idx) {
            temp = head;
            value = head->data;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;

            for (size_t i = 0; i < idx; i++) {
                if (current->next) {
                    temp = current;
                    current = current->next;
                } else {
                    throw std::out_of_range("Index out of range");
                }
            }
            temp->next = current->next;
            value = current->data;
            delete current;
        }
        return value;
    }

    constexpr void rightRotate() noexcept {
        if (!head || !head->next) {
            return;
        }
        Node *prev = head, *current = prev->next;

        while (current->next) {
            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
        current->next = head;
        head = current;
    }

    void rightShift() {
        if (!head) {
            return;
        }
        if (!head->next) {
            head->data = type();
            return;
        }
        insert(0, type());
        Node *prev = head, *current = prev->next;

        while (current->next) {
            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
        delete current;
    }

    void remove(const type& value) noexcept {
        if (!head) {
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = temp->next;
            delete temp;
            return;
        }
        Node *prev = head, *current = prev->next;

        while (current) {
            if (current->data == value) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    constexpr void reverse() noexcept {
        if (!head || !head->next) {
            return;
        }
        Node *end = nullptr, *prev = head, *current = prev->next;

        while (current) {
            prev->next = end;
            end = prev;
            prev = current;
            current = current->next;
        }
        prev->next = end;
        head = prev;
    }

    constexpr void sort() noexcept {
        Node *q, *r = nullptr;

        if (!head) {
            return;
        }
        for (Node* p = head; p->next; p = p->next) {
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

        while (current) {
            sum += current->data;
            current = current->next;
        }
        return sum;
    }

    ~LinkedList() noexcept { clear(); }
};
