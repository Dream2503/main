#pragma once
#include "01-Array.h"

template <typename type>
class Set : public Array<type> {
    using Array<type>::list;
    using Array<type>::len;
    using Array<type>::size;

public:
    Set() {}

    Set(const std::initializer_list<type>& list) {
        for (const type& element : list) {
            append(element);
        }
    }

    Set(const Set& set) {
        for (const type& element : set) {
            append(element);
        }
    }

    Set(const type* list, const size_t size) {
        for (size_t i = 0; i < size; i++) {
            append(list[i]);
        }
    }

    void append(const type& value) {
        if (len == size) {
            Array<type>::re_size();
        }
        if (!Array<type>::contains(value)) {
            list[len++] = value;
        }
    }

    Set copy() const { return Set(*this); }

    Set difference(const Set& set) const {
        Set res;
        res.list = new type[len];
        res.size = len;
        bool found = false;
        size_t k = 0;

        for (size_t i = 0; i < len; i++) {
            for (size_t j = 0; j < set.len; j++) {
                if (list[i] == set.list[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                res[k++] = list[i];
            } else {
                found = false;
            }
        }
        res.len = k;
        return res;
    }

    void insert(const size_t idx, const type& value) {
        if (!Array<type>::contains(value)) {
            Array<type>::insert(idx, value);
        }
    }

    Set intersection(const Set& set) const {
        Set res;
        res.size = len + set.len;
        res.list = new type[res.size];
        size_t k = 0;

        for (size_t i = 0; i < len; i++) {
            for (size_t j = 0; j < set.len; j++) {
                if (list[i] == set.list[j]) {
                    res[k++] = list[i];
                }
            }
        }
        res.len = k;
        return res;
    }

    Set operator+(const Set& set) const { return Union(set); }

    void operator+=(const Set& set) { *this = Union(set); }

    Set Union(const Set& set) const {
        Set res(*this);
        int i = 0;

        for (const type& element : set) {
            res.append(element);
        }
        return res;
    }
};
