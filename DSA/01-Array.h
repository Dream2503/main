#pragma once
#include <iostream>

template <typename type>
class Array {
protected:
    type* list = nullptr;
    int len = 0, size = 0;

    static constexpr void swap(type& first, type& second) noexcept {
        type temp = first;
        first = second;
        second = temp;
    }

    bool operators(const Array& array, const std::string& opr) const noexcept {
        for (int i = 0; i < len && i < array.len; i++) {
            if ((opr == ">") && (list[i] < array[i]) || (opr == ">=") && (list[i] < array[i]) ||
                (opr == "<") && (list[i] > array[i]) || (opr == "<=") && (list[i] > array[i]) ||
                (opr == "==") && (len != array.len || list[i] != array[i])) {
                return false;
            }
        }
        return true;
    }

    void re_size() {
        size = size ? size * 2 : 1;
        type* new_list = new type[size];

        for (int i = 0; i < len; i++) {
            new_list[i] = list[i];
        }
        delete[] list;
        list = new_list;
    }

    Array(const type* other, const int len, const int size) : list(nullptr), len(len), size(size) {
        if (size) {
            list = new type[size];

            for (int i = 0; i < len; i++) {
                list[i] = other[i];
            }
        }
    }

public:
    constexpr Array() = default;

    Array(const Array& array) : Array(array.list, array.len, array.size) {}

    Array(Array&& array) noexcept : list(array.list), len(array.len), size(array.size) {
        array.list = nullptr;
        array.len = 0;
        array.size = 0;
    }

    Array(const std::initializer_list<type> list) : Array(list.begin(), list.size()) {}

    Array(const type* list, const int size) : Array(list, size, size) {}

    void append(const type value) {
        if (len == size) {
            re_size();
        }
        list[len++] = value;
    }

    constexpr double average() const noexcept { return sum() / static_cast<double>(len); }

    constexpr type* begin() const noexcept { return list; }

    void clear() noexcept {
        delete[] list;
        list = nullptr;
        len = size = 0;
    }

    constexpr bool contains(const type value) const noexcept { return index(value) == -1 ? false : true; }

    constexpr Array copy() const { return Array(*this); }

    constexpr int count(const type value) const noexcept {
        int cnt = 0;

        for (const type element : *this) {
            if (element == value) {
                cnt++;
            }
        }
        return cnt;
    }

    void display() const noexcept { operator<<(std::cout, *this); }

    constexpr type* end() const noexcept { return list + len; }

    void extend(const Array& array) {
        for (int i = 0; i < array.len; i++) {
            append(array.list[i]);
        }
    }

    constexpr int index(const type value) const noexcept {
        for (int i = 0; i < len; i++) {
            if (list[i] == value) {
                return i;
            }
        }
        return -1;
    }

    void insert(const int idx, const type value) {
        if (idx > len || idx < 0) {
            throw std::out_of_range("Index out of range");
        }
        if (len == size) {
            re_size();
        }
        for (int i = len++; i > idx; i--) {
            list[i] = list[i - 1];
        }
        list[idx] = value;
    }

    constexpr bool is_sorted() const noexcept {
        if (list[0] < list[1]) {
            for (int i = 1; i < len; i++) {
                if (list[i] < list[i - 1]) {
                    return false;
                }
            }
        } else {
            for (int i = 1; i < len; i++) {
                if (list[i] > list[i - 1]) {
                    return false;
                }
            }
        }
        return true;
    }

    constexpr int length() const noexcept { return len; }

    void leftRotate() {
        if (len) {
            this->append(pop(0));
        }
    }

    void leftShift() {
        if (len) {
            pop(0);
            append(type());
        }
    }

    constexpr type max() const noexcept {
        if (len) {
            type res = list[0];

            for (const type element : *this) {
                if (element > res) {
                    res = element;
                }
            }
            return res;
        }
        return 0;
    }

    constexpr type min() const noexcept {
        if (len) {
            type res = list[0];

            for (const type element : *this) {
                if (element < res) {
                    res = element;
                }
            }
            return res;
        }
        return 0;
    }

    Array& operator=(const Array& array) {
        if (this != &array) {
            delete[] list;
            len = array.len;
            size = array.size;
            list = new type[size];

            for (int i = 0; i < len; i++) {
                list[i] = array.list[i];
            }
        }
        return *this;
    }


    Array operator+(const Array& array) const {
        Array res = Array(*this);
        res += array;
        return res;
    }

    void operator+=(const Array& array) { this->extend(array); }

    Array operator*(const int num) const {
        if (num < 0) {
            throw std::invalid_argument("Negative number not allowed");
        }
        Array res;

        for (int i = 0; i < num; i++) {
            res.extend(*this);
        }
        return res;
    }

    void operator*=(int num) { *this = *this * num; }

    constexpr bool operator>(const Array& array) const noexcept { return operators(array, ">"); }

    constexpr bool operator>=(const Array& array) const noexcept { return operators(array, ">="); }

    constexpr bool operator<(const Array& array) const noexcept { return operators(array, "<"); }

    constexpr bool operator<=(const Array& array) const noexcept { return operators(array, "<="); }

    constexpr bool operator==(const Array& array) const noexcept { return operators(array, "=="); }

    constexpr bool operator!=(const Array& array) const noexcept { return !operator==(array); }

    constexpr friend std::ostream& operator<<(std::ostream& out, const Array& array) noexcept {
        if (array.len) {
            out << '[';

            for (int i = 0; i < array.len; i++) {
                out << array[i];

                if (i != array.len - 1) {
                    out << ", ";
                }
            }
            out << ']' << std::endl;
        }
        return out;
    }

    type& operator[](const int index) const {
        if (index >= len || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return list[index];
    }

    type pop(const int idx) {
        if (idx >= len || idx < 0) {
            throw std::out_of_range("Index out of range");
        }
        type temp = list[idx];

        for (int i = idx; i < len - 1; i++) {
            list[i] = list[i + 1];
        }
        --len;
        return temp;
    }

    void rightRotate() { insert(0, pop(len - 1)); }

    void rightShift() {
        insert(0, type());
        --len;
    }

    void remove(const type value) {
        try {
            pop(index(value));
        } catch (const std::out_of_range& e) {
            throw std::invalid_argument("Element not found");
        }
    }

    constexpr void reverse() noexcept {
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            swap(list[i], list[j]);
        }
    }

    constexpr void sort() const noexcept {
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (list[j] > list[j + 1]) {
                    swap(list[j], list[j + 1]);
                }
            }
        }
    }

    constexpr type sum() const noexcept {
        type res = type();

        for (const type element : *this) {
            res += element;
        }
        return res;
    }

    ~Array() { delete[] list; }
};
