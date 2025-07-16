#pragma once
#include "01-Array.h"

template <typename type>
class SortedArray : public Array<type> {
    using Array<type>::list;
    using Array<type>::len;
    using Array<type>::size;
    using Array<type>::re_size;
    std::string mode = "asc";

    using Array<type>::append;
    using Array<type>::extend;
    using Array<type>::is_sorted;
    using Array<type>::leftRotate;
    using Array<type>::leftShift;
    using Array<type>::rightRotate;
    using Array<type>::rightShift;
    using Array<type>::sort;

public:
    constexpr SortedArray() = default;

    SortedArray(const std::initializer_list<type>& list, const std::string& mode = "asc") {
        this->mode = mode;

        for (const type& element : list) {
            insert(element);
        }
    }

    SortedArray(const SortedArray& array) {
        list = new type[array.size];
        len = array.len;
        size = array.size;

        for (size_t i = 0; i < array.len; i++) {
            list[i] = array.list[i];
        }
        if (mode != array.mode) {
            reverse();
        }
    }

    constexpr SortedArray(SortedArray&& array) noexcept {
        Array<type>::swap(array);
        std::swap(mode, array.mode);
    }

    SortedArray(const type* list, const size_t size, const std::string& mode = "asc") {
        this->mode = mode;

        for (size_t i = 0; i < size; i++) {
            insert(list[i]);
        }
    }

    SortedArray copy() const { return SortedArray(*this); }

    constexpr size_t count(const type& value) const noexcept {
        size_t cnt = 0;
        const size_t pos = index(value);

        if (pos != -1) {
            cnt++;
        }
        if (cnt) {
            for (size_t i = pos; i < len && list[i] == value; i++) {
                cnt++;
            }
        }
        return cnt;
    }

    constexpr size_t index(const type& value) const noexcept {
        size_t low = 0, high = len - 1, i;

        while (low <= high) {
            size_t mid = (low + high) / 2;

            if (list[mid] == value) {
                for (mid--; list[mid] == value && mid >= low; mid--) {
                }
                return mid + 1;
            }
            if ((list[mid] < value && mode == "asc") || (list[mid] > value && mode == "dsc")) {
                low = mid + 1;
            } else if ((list[mid] > value && mode == "asc") || (list[mid] < value && mode == "dsc"))
                high = mid - 1;
        }
        return -1;
    }

    void insert(const type& value) {
        size_t idx;

        if (len == size) {
            re_size();
        }
        for (size_t i = 0; i <= len; i++) {
            if ((list[i] >= value && mode == "asc") || (list[i] <= value && mode == "dsc")) {
                idx = i;
                break;
            }
            idx = i;
        }
        Array<type>::insert(idx, value);
    }

    constexpr type max() const noexcept { return mode == "asc" ? list[len - 1] : list[0]; }

    constexpr type min() const noexcept { return mode == "asc" ? list[0] : list[len - 1]; }

    void merge(SortedArray& array) { *this += array; }

    constexpr SortedArray& operator=(SortedArray array) {
        if (this != &array) {
            Array<type>::swap(array);
            std::swap(mode, array.mode);
        }
        return *this;
    }

    SortedArray operator+(const SortedArray& array) const {
        SortedArray res(len + array.len, mode);
        size_t i = 0, j = 0, k = 0;
        bool flag = false;

        if (res.mode != array.mode) {
            res.reverse();
            flag = true;
        }
        while (i != len and j != array.len) {
            if ((list[i] < array.list[j] && mode == "asc") || (list[i] > array.list[j] && mode == "dsc")) {
                res.list[k++] = list[i++];
            } else if ((list[i] > array.list[j] && mode == "asc") || (list[i] < array.list[j] && mode == "dsc")) {
                res.list[k++] = array.list[j++];
            } else {
                res.list[k++] = list[i++];
                res.list[k++] = array.list[j++];
            }
        }
        while (i < len) {
            res.list[k++] = list[i++];
        }
        while (j < array.len) {
            res.list[k++] = array.list[j++];
        }
        if (flag) {
            res.reverse();
        }
        return res;
    }

    void operator+=(SortedArray& array) { *this = *this + array; }

    SortedArray operator*(const size_t num) const {
        SortedArray res;
        res.list = new type[len * num];
        res.len = res.size = len * num;
        res.mode = mode;

        for (size_t i = 0, k = 0; i < len; i++) {
            for (size_t j = 0; j < num; j++) {
                res.list[k++] = list[i];
            }
        }
        return res;
    }

    void operator*=(const size_t num) { *this = *this * num; }

    constexpr bool operator==(const SortedArray& array) const noexcept {
        if (mode != array.mode) {
            throw std::invalid_argument("Different type of sorted arrays can't be compared");
        }
        return Array<type>::operator==(array);
    }
    constexpr bool operator!=(const SortedArray& array) const noexcept { return !operator==(array); }

    constexpr void reverse() noexcept {
        for (size_t i = 0, j = len - 1; i < j; i++, j--) {
            Array<type>::swap(list[i], list[j]);
        }
        mode = mode == "asc" ? "dsc" : "asc";
    }
};
