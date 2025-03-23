#include "dream.h"
#include <iostream>
#include <string>
using namespace Dream;

int main() {
    string temp("Hello");
    string s(5, 'A');
    cout << s << endl;

    for (auto it = temp.rbegin(); it != temp.rend(); it++) {
        cout << *it;
    }
    // cout << s;


    // std::cout << "Enter a number: ";
    // std::cin >> x;
    // std::cout << "The number entered is " << x << std::endl;
    // std::string temp("Hello");

    // for (auto it = temp.rbegin(); it != temp.rend(); it++) {
    //     cout << *it;
    // }
    // std::string res = temp;
    // res[0] = 'L';

    // std::cout << res <<' ' << temp;
    return 0;
}