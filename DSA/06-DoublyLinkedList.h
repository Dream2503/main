#pragma once
#include <iostream>

template <class type>
class DoublyLinkedList {
protected:
    struct Node {
        type data;
        Node *prev, *next;
        Node(const type data = type(), Node* prev = nullptr, Node* next = nullptr) :
            data(data), prev(prev), next(next) {}
    };
    Node* head = nullptr;

    constexpr bool operators(const DoublyLinkedList& list, const std::string& opr) const noexcept {
        Node *current1 = head, *current2 = list.head;

        while (current1 && current2) {
            if ((opr == ">") && (current1->data <= current2->data) ||
                (opr == ">=") && (current1->data < current2->data) ||
                (opr == "<") && (current1->data >= current2->data) ||
                (opr == "<=") && (current1->data > current2->data) ||
                (opr == "==") && (current1->data != current2->data)) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        if ((current1 || current2) && (opr == "==")) {
            return false;
        }
        return true;
    }

public:
    DoublyLinkedList() {}

    DoublyLinkedList(const std::initializer_list<type>& list) {
        Node* current = head = new Node(*list.begin());
        auto it = list.begin() + 1;

        while (it != list.end()) {
            current->next = new Node(*it, current);
            current = current->next;
            ++it;
        }
    }

    DoublyLinkedList(const DoublyLinkedList& list) {
        if (list.head) {
            Node *current1 = head = new Node(list.head->data), *current2 = list.head->next;

            while (current2) {
                current1->next = new Node(current2->data, current1);
                current1 = current1->next;
                current2 = current2->next;
            }
        }
    }

    DoublyLinkedList(const type* array, const size_t size) {
        if (size) {
            Node* current = head = new Node(array[0]);

            for (size_t i = 1; i < size; i++) {
                current->next = new Node(array[i], current);
                current = current->next;
            }
        }
    }

    DoublyLinkedList(DoublyLinkedList&& other) noexcept {
        head = other.head;
        other.head = nullptr;
    }

    void append(const type& value) {
        if (!head) {
            head = new Node(value);
        } else {
            Node* current = head;

            while (current->next) {
                current = current->next;
            }
            current->next = new Node(value, current);
        }
    }

    constexpr double average() const noexcept { return sum() / static_cast<double>(length()); }

    void clear() noexcept {
        while (head) {
            delete head->prev;
            head = head->next;
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

    DoublyLinkedList copy() const { return DoublyLinkedList(*this); }

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

    void extend(DoublyLinkedList list) {
        if (!head) {
            head = list.head;
        } else {
            Node* current = head;

            while (current->next) {
                current = current->next;
            }
            current->next = list.head;
            list.head->prev = current;
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

    void insert(const size_t index, const type& value) {
        if (!head) {
            throw std::out_of_range("Index out of range");
        }
        if (!head) {
            head = new Node(value);
            return;
        }
        if (index == 0) {
            Node* current = head;
            head = new Node(value, nullptr, current);
            current->prev = head;
            return;
        }
        Node* current = head;

        for (size_t i = 0; i < index - 1; i++) {
            if (current->next) {
                current = current->next;
            } else {
                throw std::out_of_range("Index out of range");
            }
        }
        current->next = new Node(value, current, current->next);
        current = current->next;
        current->next->prev = current;
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

    void leftRotate() {
        if (!head || !head->next) {
            return;
        }
        Node *element = head, *current = head->next;
        head = head->next;
        head->prev = nullptr;

        while (current->next) {
            current = current->next;
        }
        current->next = element;
        element->prev = current;
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
        current->next = new Node(type(), current);
    }

    constexpr type max() const noexcept {
        if (!head) {
            return type();
        }
        Node* current = head->next;
        type res = head->data;

        while (current) {
            if (current->data > res) {
                res = current->data;
            }
            current = current->next;
        }
        return res;
    }

    constexpr type min() const noexcept {
        if (!head) {
            return type();
        }
        Node* current = head->next;
        type res = head->data;

        while (current) {
            if (current->data < res) {
                res = current->data;
            }
            current = current->next;
        }
        return res;
    }

    DoublyLinkedList& operator=(DoublyLinkedList list) {
        if (this != &list) {
            std::swap(head, list.head);
        }
        return *this;
    }

    DoublyLinkedList operator+(const DoublyLinkedList& list) const {
        DoublyLinkedList list1(*this);
        list1.extend(list);
        return list1;
    }

    void operator+=(const DoublyLinkedList& list) { extend(list); }

    DoublyLinkedList operator*(const size_t num) const {
        if (!head || !num) {
            return DoublyLinkedList();
        }
        if (num == 1) {
            return copy();
        }
        DoublyLinkedList result(*this);
        Node* current = result.head;

        for (size_t i = 1; i < num; i++) {
            DoublyLinkedList list = copy();

            while (current->next) {
                current = current->next;
            }
            current->next = list.head;
            list.head->prev = current;
            list.head = nullptr;
        }
        return result;
    }

    void operator*=(const size_t num) { *this = *this * num; }

    constexpr bool operator>(const DoublyLinkedList& list) const noexcept { return operators(list, ">"); }

    constexpr bool operator>=(const DoublyLinkedList& list) const noexcept { return operators(list, ">="); }

    constexpr bool operator<(const DoublyLinkedList& list) const noexcept { return operators(list, "<"); }

    constexpr bool operator<=(const DoublyLinkedList& list) const noexcept { return operators(list, "<="); }

    constexpr bool operator==(const DoublyLinkedList& list) const noexcept { return operators(list, "=="); }

    constexpr bool operator!=(const DoublyLinkedList& list) const noexcept { return !operator==(list); }

    constexpr friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& list) noexcept {
        if (list.head) {
            Node* current = list.head;
            out << "Forwards -> [";

            while (current->next) {
                out << current->data << ", ";
                current = current->next;
            }
            out << current->data << ']' << std::endl << "Backwards -> [";

            while (current != list.head) {
                out << current->data << ", ";
                current = current->prev;
            }
            out << list.head->data << ']' << std::endl;
        }
        return out;
    }

    constexpr type& operator[](const size_t index) {
        if (!head) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;

        for (size_t i = 0; i < index && current; i++) {
            current = current->next;
        }
        if (current) {
            return current->data;
        }
        throw std::out_of_range("Index out of range");
    }

    type pop(const size_t index) {
        if (!head) {
            throw std::out_of_range("Index out of range");
        }
        Node* temp;
        type value;

        if (!index) {
            value = head->data;
            head = head->next;
            delete head->prev;
        } else {
            Node* current = head;

            for (size_t i = 0; i < index; i++) {
                if (current->next) {
                    temp = current;
                    current = current->next;
                } else {
                    throw std::out_of_range("Index out of range");
                }
            }
            temp->next = current->next;
            value = current->data;
            current->next->prev = temp;
            delete current;
        }
        return value;
    }

    void rightRotate() {
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
        current->prev = nullptr;
        head->prev = current;
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
        Node *prev = head, *current = head->next;

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

                if (current->next) {
                    current->next->prev = prev;
                }
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
            prev->prev = current;
            end = prev;
            prev = current;
            current = current->next;
        }
        prev->next = end;
        prev->prev = nullptr;
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

    ~DoublyLinkedList() noexcept { clear(); }
};
