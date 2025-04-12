#include <iostream>
// #include <memory>
#include <string>

using namespace Dream;
int main() {
    // const allocator<char> alloc;
    std::iterator;
    string test("Hello World!");
    string s1(alloc);
    string s2;
    string s3(5, 'A');
    string s4(test.begin(), test.begin() + 20);
    string s5("Hello World!", 7);
    string s6("Hello World!");
    string s7(test);
    // string s8((string &&)test);
    string s9(test, alloc);
    // string s10((string &&)test, alloc);
    string s11(test, 7);
    // string s12((string &&)test, 7);
    string s13(test, 7, 2);
    string s14((string &&)test, 7, 2);


    cout << s14  << " " << test << endl;


    // string temp("Hello");

    // for (auto it = temp.rbegin(); it != temp.rend(); it++) {
    //     cout << *it;
    // }
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
