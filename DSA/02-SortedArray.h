#pragma once
#include "01-Array"

template <class type>
class SortedArray : public Array<type> {
    using Array<type>::list;
    using Array<type>::len;
    using Array<type>::size;
    using Array<type>::re_size;
    std::string mode = "asc";

    constexpr bool operators(const SortedArray& array, const std::string& opr) const noexcept {
        if (mode != array.mode) {
            throw std::invalid_argument("Different type of sorted arrays cant be compared");
        }
        return Array<type>::operators(array, opr);
    }

    SortedArray(const int size, const std::string& mode) {
        this->mode = mode;

        while (size > this->size) {
            re_size();
        }
        len = size;
    }

    using Array<type>::extend;
    using Array<type>::is_sorted;
    using Array<type>::leftRotate;
    using Array<type>::leftShift;
    using Array<type>::rightRotate;
    using Array<type>::rightShift;
    using Array<type>::sort;

public:
    constexpr SortedArray() = default;

    SortedArray(const std::initializer_list<type> list, const char* mode = "asc") {
        this->mode = mode;

        for (const type element : list) {
            insert(element);
        }
    }

    SortedArray(const SortedArray& array) {
        list = new type[array.size];
        len = array.len;
        size = array.size;

        for (int i = 0; i < array.len; i++) {
            list[i] = array[i];
        }
        if (mode != array.mode) {
            reverse();
        }
    }

    SortedArray(const type* list, const int size, const char* mode = "asc") {
        this->mode = mode;

        for (int i = 0; i < size; i++) {
            insert(list[i]);
        }
    }

    SortedArray copy() { return SortedArray(*this); }

    constexpr int count(const type value) const noexcept {
        int cnt = 0;
        const int pos = index(value);

        if (pos != -1) {
            cnt++;
        }
        if (cnt) {
            for (int i = pos - 1; i >= 0 && list[i] == value; i--) {
                cnt++;
            }
            for (int i = pos + 1; i < len && list[i] == value; i++) {
                cnt++;
            }
        }
        return cnt;
    }

    constexpr int index(const type value) const noexcept {
        int low = 0, high = len - 1, i;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (list[mid] == value) {
                for (i = mid - 1; list[i] == value && i >= low; i--) {
                }
                return i + 1;
            }
            if ((list[mid] < value && this->mode == "asc") || (list[mid] > value && mode == "dsc")) {
                low = mid + 1;
            } else if ((list[mid] > value && mode == "asc") || (list[mid] < value && mode == "dsc"))
                high = mid - 1;
        }
        return -1;
    }

    void insert(const type value) {
        int idx;

        if (len == size) {
            re_size();
        }
        for (int i = 0; i <= len; i++) {
            if ((list[i] >= value && mode == "asc") || (list[i] <= value and mode == "dsc")) {
                idx = i;
                break;
            }
            idx = i;
        }
        Array<type>::insert(idx, value);
    }

    constexpr type max() const noexcept { return mode == "asc" ? list[len - 1] : list[0]; }

    constexpr type min() const noexcept { return mode == "asc" ? list[0] : list[len - 1]; }

    void merge(const SortedArray& array) { *this += array; }

    SortedArray operator+(SortedArray& array) const {
        SortedArray res(len + array.len, mode);
        int i = 0, j = 0, k = 0;
        bool flag = false;

        if (res.mode != array.mode) {
            array.reverse();
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
            array.reverse();
        }
        return res;
    }

    void operator+=(SortedArray& array) { *this = *this + array; }

    SortedArray operator*(const int num) const {
        SortedArray result(len * num, mode);

        for (int i = 0, k = 0; i < len; i++) {
            for (int j = 0; j < num; j++) {
                result.list[k++] = list[i];
            }
        }
        return result;
    }

    void operator*=(const int num) { *this = *this * num; }

    void reverse() {
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            Array<type>::swap(list[i], list[j]);
        }
        mode = mode == "asc" ? "dsc" : "asc";
    }
};
