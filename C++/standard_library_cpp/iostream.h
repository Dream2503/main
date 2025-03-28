#pragma once
#include <cstdio>

namespace Dream {
    class ostream final {
        template<class T>
        constexpr const ostream &overload(const char *format, T value) const noexcept {
            printf(format, value);
            return *this;
        }

    public:
        constexpr const ostream &operator<<(const int value) const noexcept { return overload("%d", value); }
        constexpr const ostream &operator<<(const unsigned int value) const noexcept { return overload("%u", value); }
        constexpr const ostream &operator<<(const long int value) const noexcept { return overload("%ld", value); }
        constexpr const ostream &operator<<(const unsigned long int value) const noexcept { return overload("%lu", value); }
        constexpr const ostream &operator<<(const long long int value) const noexcept { return overload("%lld", value); }
        constexpr const ostream &operator<<(const unsigned long long int value) const noexcept { return overload("%llu", value); }
        constexpr const ostream &operator<<(const float value) const noexcept { return overload("%f", value); }
        constexpr const ostream &operator<<(const double value) const noexcept { return overload("%f", value); }
        constexpr const ostream &operator<<(const long double value) const noexcept { return overload("%Lf", value); }
        constexpr const ostream &operator<<(const char value) const noexcept { return overload("%c", value); }
        constexpr const ostream &operator<<(const char *value) const noexcept { return overload("%s", value); }
        constexpr const ostream &operator<<(const void *value) const noexcept { return overload("%p", value); }
        constexpr const ostream &operator<<(const std::nullptr_t) const noexcept { return *this << "nullptr"; }
    };


    class istream final {
        template<class T>
        constexpr const istream &overload(const char *format, T value) const noexcept {
            scanf(format, value);
            return *this;
        }

    public:
        constexpr const istream &operator>>(int &value) const noexcept { return overload("%d", &value); }
        constexpr const istream &operator>>(unsigned int &value) const noexcept { return overload("%u", &value); }
        constexpr const istream &operator>>(long int &value) const noexcept { return overload("%ld", &value); }
        constexpr const istream &operator>>(unsigned long int &value) const noexcept { return overload("%lu", &value); }
        constexpr const istream &operator>>(long long int &value) const noexcept { return overload("%lld", &value); }
        constexpr const istream &operator>>(unsigned long long int &value) const noexcept { return overload("%llu", &value); }
        constexpr const istream &operator>>(float &value) const noexcept { return overload("%f", &value); }
        constexpr const istream &operator>>(double &value) const noexcept { return overload("%lf", &value); }
        constexpr const istream &operator>>(long double &value) const noexcept { return overload("%Lf", &value); }
        constexpr const istream &operator>>(char &value) const noexcept { return overload("%c", &value); }
        constexpr const istream &operator>>(char *value) const noexcept { return overload("%s", value); }
        constexpr const istream &operator>>(void *value) const noexcept { return overload("%p", value); }
    };
    constexpr ostream cout;
    constexpr istream cin;
    constexpr char endl = '\n';
}