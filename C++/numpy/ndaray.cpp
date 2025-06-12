#include "ndaray.h"

int main() {
    // Basic array
    NdArray<float> a({2, 3}, {1, 2, 3, 4, 5, 6}, true, 'C', false, 2);
    a.print();

    // Array with ndmin = 4
    NdArray<float> b({3, 4}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, true, 'F', false, 4);
    b.print();

    // Array created like `a`, with shape override
    NdArray<float> c = a.createLike({6});
    c.print();
}

