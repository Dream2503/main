#include "fraction"
#include <vector>
#include <iostream>

template <class type>
class Matrix {
    public:
        Matrix(int = 0, int = 0, std::string = "pass", std::vector<std::vector<type>> = {{}});
};

template <class type>
Matrix<type>::Matrix(int row, int column, std::string method, std::vector<std::vector<type>> matrix) {
    
}

int main() {
    Matrix<int> m1;
    return 0;
}