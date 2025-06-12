#pragma once
#include "numpy.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <algorithm>

template<typename T>
class NdArray {
private:
    std::vector<size_t> _shape;
    std::vector<T> _data;
    char order; // 'C', 'F', 'K'

public:
    // Constructor
    explicit NdArray(std::vector<size_t> shape, std::vector<T> object = {}, const bool copy = true,
                     const char order = 'K', const bool subok = false, size_t ndmin = 0,
                     const NdArray<T> *like = nullptr) {
        while (shape.size() < ndmin)
            shape.insert(shape.begin(), 1);

        _shape = shape;

        size_t totalSize = 1;
        for (size_t dim: shape)
            totalSize *= dim;

        if (like) {
            this->order = like->order;
        } else {
            this->order = order;
        }

        if (object.empty()) {
            _data = std::vector<T>(totalSize);
        } else if (copy) {
            if (object.size() != totalSize) {
                throw std::invalid_argument("Data size does not match shape");
            }
            _data = object;
        } else {
            if (object.size() != totalSize) {
                throw std::invalid_argument("Data size does not match shape");
            }
            _data.swap(object);
        }
    }

    // Print the shape and data
    void print() const {
        std::cout << "Shape: (";
        for (size_t i = 0; i < _shape.size(); ++i) {
            std::cout << _shape[i];
            if (i < _shape.size() - 1) std::cout << ", ";
        }
        std::cout << ")\n";

        std::cout << "Data: [";
        for (const auto &val: _data) std::cout << val << ", ";
        std::cout << "]\n";

        std::cout << "Order: " << order << "\n";
    }

    // Getter for shape
    const std::vector<size_t> &shape() const {
        return _shape;
    }

    // Getter for data
    const std::vector<T> &data() const {
        return _data;
    }

    // Like constructor
    NdArray<T> createLike(std::vector<size_t> newShape) const {
        return NdArray<T>(newShape, {}, true, this->order, false, 0, this);
    }
};
