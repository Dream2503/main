#include "C++/dream"
#include <iostream>
#include <string>
using namespace Dream;

int main() {
    string temp("Hello");

    for (auto it = temp.begin(); it != temp.end(); it++) {
        cout << *it;
    }
    // cout << s;


    // std::cout << "Enter a number: ";
    // std::cin >> x;
    // std::cout << "The number entered is " << x << std::endl;
    // std::string temp("Hello");

    // for (auto it = temp.crbegin(); it != temp.rend(); it++) {
    //     cout << *it;
    // }
    // std::string res = temp;
    // res[0] = 'L';

    // std::cout << res <<' ' << temp;
    return 0;
}