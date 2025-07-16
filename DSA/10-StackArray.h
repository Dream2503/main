#pragma once
#include <cmath>
#include "01-Array.h"

template <class type>
class StackArray {
    Array<type> stack = Array<type>();

public:
    StackArray() {}

    void clear() noexcept { stack.clear(); }

    StackArray copy() const { return StackArray(*this); }

    static type postfix_evaluation(const std::string& str) {
        type x1, x2, res;
        StackArray<int> s;

        for (const char& ch : str) {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
                x2 = s.pop();
                x1 = s.pop();

                switch (ch) {
                case '+':
                    res = x1 + x2;
                    break;

                case '-':
                    res = x1 - x2;
                    break;

                case '*':
                    res = x1 * x2;
                    break;

                case '/':
                    res = x1 / x2;
                    break;

                case '^':
                    res = pow(x1, x2);

                default:
                    break;
                }
                s.push(res);
            } else {
                s.push(ch - '0');
            }
        }
        return s.pop();
    }

    constexpr void display() const noexcept { operator<<(std::cout, *this); }

    static std::string infix_to_postfix(const std::string& infix) {
        auto precedence = [](const char ch) -> int {
            if (ch == '+' || ch == '-') {
                return 1;
            }
            if (ch == '*' || ch == '/') {
                return 2;
            }
            if (ch == '^') {
                return 3;
            }
            return 0;
        };
        std::string postfix;
        StackArray<int> s;

        for (const char ch : infix) {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
                while (!s.is_empty() && precedence(ch) <= precedence(s.peek())) {
                    postfix += s.pop();
                }
                s.push(ch);
            } else {
                postfix += ch;
            }
        }
        while (!s.is_empty()) {
            postfix += s.pop();
        }
        return postfix;
    }

    constexpr bool is_empty() const noexcept { return stack.length() == 0; }

    constexpr bool operator==(const StackArray& stk) const noexcept { return this->stack == stk.stack; }

    constexpr bool operator!=(const StackArray& stack) const noexcept { return this->stack != stack.stack; }

    friend std::ostream& operator<<(std::ostream& out, const StackArray& stack) {
        if (stack.is_empty()) {
            out << "Stack is empty" << std::endl;
        } else {
            out << stack.peek() << "   <- top" << std::endl;

            for (size_t i = stack.stack.length() - 2; i != -1; i--) {
                out << stack.stack[i] << std::endl;
            }
        }
        return out;
    }

    constexpr type peek() const noexcept {
        if (is_empty()) {
            std::cerr << "Stack Underflow" << std::endl;
            return type();
        }
        return stack[stack.length() - 1];
    }

    static std::string postfix_to_infix(const std::string& postfix) {
        StackArray<std::string> s;

        for (const char ch : postfix) {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
                std::string str2 = s.pop(), str1 = s.pop();
                s.push('(' + str1 + ch + str2 + ')');
            } else {
                s.push(std::string(1, ch));
            }
        }
        if (!s.is_empty()) {
            const std::string res = s.pop();
            return res.substr(1, res.length() - 2);
        }
        std::cerr << "Invalid postfix expression" << std::endl;
        return "";
    }

    constexpr type pop() noexcept {
        if (is_empty()) {
            std::cerr << "Stack Underflow" << std::endl;
            return type();
        }
        return stack.pop(stack.length() - 1);
    }

    void push(const type element) { stack.append(element); }
};
