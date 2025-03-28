#pragma once
#include "iostream.h"
#include "iterator.h"
#include "memory.h"


namespace Dream {
    class string {
        char *buffer_ = nullptr;
        size_t capacity_ = 0, size_ = 0;
        allocator<char> alloc_ = allocator<char>();

    public:
        class iterator final : public Dream::iterator<char, iterator> {
        public:
            using Dream::iterator<char, iterator>::iterator;
        };

        class reverse_iterator final : public Dream::reverse_iterator<char, reverse_iterator> {
        public:
            using Dream::reverse_iterator<char, reverse_iterator>::reverse_iterator;
        };

        class const_iterator final : public Dream::iterator<const char, const_iterator> {
        public:
            using iterator::iterator;
        };

        class const_reverse_iterator final : public Dream::reverse_iterator<const char, const_reverse_iterator> {
        public:
            using reverse_iterator::reverse_iterator;
        };

        constexpr string(const allocator<char> &alloc = allocator<char>()) noexcept : buffer_(nullptr), capacity_(0), size_(0), alloc_(alloc) {}
        constexpr string(const char *str, const size_t count, const allocator<char> &alloc = allocator<char>()) noexcept :
            string(str, str + count, alloc) {}
        constexpr string(const char *str, const allocator<char> &alloc = allocator<char>()) noexcept : string(str, strlen(str), alloc) {}
        constexpr string(const string &other, const allocator<char> &alloc) noexcept : string(other, 0, 0, alloc) {}
        constexpr string(const string &other, const size_t pos, const allocator<char> &alloc) noexcept : string(other, pos, 0, alloc) {}
        constexpr string(string &&other, const allocator<char> &alloc) noexcept : string((string &&) other, 0, 0, alloc) {}
        constexpr string(string &&other, const size_t pos, const allocator<char> &alloc) noexcept : string((string &&) other, pos, 0, alloc) {}
        constexpr string(const string &other, const size_t pos = 0, const size_t count = 0, const allocator<char> &alloc = allocator<char>()) noexcept
            : string(other.begin() + pos, other.begin() + (count ? pos + count : other.size_), alloc) {}


        constexpr string(const size_t count, const char ch, const allocator<char> &alloc = allocator<char>()) noexcept {
            size_ = count;
            capacity_ = size_ + 1;
            alloc_ = alloc;

            if (size_) {
                if ((buffer_ = alloc_.allocate(capacity_ * sizeof(char)))) {
                    for (size_t i = 0; i < count; i++) {
                        buffer_[i] = ch;
                    }
                    buffer_[size_] = 0;
                } else {
                    *this = string();
                }
            } else {
                *this = string();
            }
        }

        constexpr string(const iterator &first, const iterator &last, const allocator<char> &alloc = allocator<char>()) noexcept {
            size_ = last - first;
            capacity_ = size_ + 1;
            alloc_ = alloc;

            if (size_) {
                if ((buffer_ = alloc_.allocate(capacity_ * sizeof(char)))) {
                    memcpy(buffer_, first, size_);
                    buffer_[size_] = 0;
                } else {
                    *this = string();
                }
            } else {
                *this = string();
            }
        }

        constexpr string(string &&other, const size_t pos = 0, const size_t count = 0, const allocator<char> &alloc = allocator<char>()) noexcept {
            size_ = count ? count : other.size_ - pos;
            capacity_ = size_ + 1;

            if (size_) {
                if ((buffer_ = alloc.allocate(capacity_ * sizeof(char)))) {
                    for (size_t i = pos; i <= pos + size_; i++) {
                        buffer_[i - pos] = other.buffer_[i];
                    }
                    buffer_[size_] = 0;
                    other = string();
                } else {
                    *this = string();
                }
            } else {
                *this = string();
            }
        }

        constexpr string &operator=(const char *str) noexcept { return *this = string(str); }
        constexpr string &operator=(const char ch) noexcept { return *this = string(&ch, 1); }

        constexpr string &operator=(const string &other) noexcept {
            if (this != &other) {
                return *this;
            }
            alloc_.deallocate(buffer_);
            *this = string(other.begin(), other.end());
            return *this;
        }

        constexpr string &operator=(string &&other) noexcept {
            if (this != &other) {
                capacity_ = other.capacity_;
                size_ = other.size_;
                alloc_.deallocate(buffer_);
                buffer_ = other.buffer_;
                other.buffer_ = nullptr;
                other.capacity_ = other.size_ = 0;
            }
            return *this;
        }

        constexpr string &assign(const string &other) noexcept { return *this = other; }
        constexpr string &assign(const string &&other) noexcept { return *this = (string &&) other; }
        constexpr string &assign(const size_t num, const char ch) { return *this = string(num, ch); }
        constexpr string &assign(const char *str, const size_t count) { return *this = string(str, count); }
        constexpr string &assign(const char *str) { return *this = str; }
        constexpr string &assign(const string &other, const size_t sub_pos, const size_t sub_len = 0) {
            return *this = string(other, sub_pos, sub_len ? sub_len : other.size_ - sub_pos);
        }
        string &assign(const iterator &first, const iterator &last) { return *this = first; }

        constexpr const allocator<char> &get_allocator() const noexcept { return alloc_; }

        constexpr const char &at(const size_t pos) noexcept {
            if (pos >= size_) {
                return *end();
            }
            return buffer_[pos];
        }

        constexpr char &at(const size_t pos) const noexcept {
            if (pos >= size_) {
                return *end();
            }
            return buffer_[pos];
        }


        constexpr friend const ostream &operator<<(const ostream &stream, const string &str) noexcept {
            if (str.buffer_) {
                stream << str.buffer_;
            }
            return stream;
        }

        constexpr friend const istream &operator>>(const istream &stream, string &str) noexcept {
            char buffer[BUFFER_SIZE];

            if (fgets(buffer, sizeof(buffer), stdin)) {
                const size_t len = strlen(buffer);

                if (buffer[len - 1] == '\n') {
                    buffer[len - 1] = 0;
                }
                str = string(buffer, buffer + len);
            }
            return stream;
        }

        constexpr operator bool() const noexcept { return buffer_ != nullptr; }

        constexpr iterator begin() const noexcept { return buffer_; }
        constexpr iterator end() const noexcept { return buffer_ + size_; }
        constexpr reverse_iterator rbegin() const noexcept { return buffer_ + size_ - 1; }
        constexpr reverse_iterator rend() const noexcept { return buffer_ - 1; }
        constexpr const_iterator cbegin() const noexcept { return buffer_; }
        constexpr const_iterator cend() const noexcept { return buffer_ + size_; }
        constexpr const_reverse_iterator crbegin() const noexcept { return buffer_ + size_ - 1; }
        constexpr const_reverse_iterator crend() const noexcept { return buffer_ - 1; }

        string &append(const size_t num, const char ch) noexcept { return append(string(num, ch)); }
        string &append(const char *str, const size_t len) noexcept { return append(str, str + len); }
        string &append(const char *str) noexcept { return append(str, str + strlen(str)); }
        string &append(const string &other) noexcept { return append(other.begin(), other.end()); }
        string &append(const string &other, const size_t sub_pos, const size_t sub_len = 0) noexcept {
            return this->append(other.begin() + sub_pos, other.begin() + sub_pos + (sub_len ? sub_len : other.size_ - sub_pos));
        }

        string &append(const iterator &first, const iterator &last) noexcept {
            const size_t len = last - first;

            if (len && alloc_.reallocate(buffer_, (size_ + len + 1) * sizeof(char))) {
                size_t i = size_;
                iterator itr = first;

                while (itr != last) {
                    buffer_[i] = *itr;
                    ++itr;
                    ++i;
                }
                size_ += len;
                capacity_ = size_ + 1;
                buffer_[size_] = 0;
            }
            return *this;
        }

        char &back();

        const char *c_str();

        // size_t capacity();

        void clear();

        int compare(const string &other);

        int compare(size_t pos, size_t len, const string &other);

        int compare(size_t pos, size_t len, const string &str, size_t subpos, size_t sublen);

        int compare(const char *s);

        int compare(size_t pos, size_t len, const char *s);

        int compare(size_t pos, size_t len, const char *s, size_t n);

        size_t copy(const char *other, size_t len, size_t pos);

        char *data();

        bool empty();

        bool ends_with(const string &suffix);

        bool ends_with(const char *suffix);

        bool ends_with(char ch);

        iterator &erase(const_iterator &pos);

        iterator &erase(const_iterator &first, const_iterator &last);

        string &erase(size_t pos, size_t count);

        size_t find(const string &other, size_t pos);

        size_t find(const char *other, size_t pos);

        size_t find(const char *other, size_t pos, size_t count);

        size_t find(char ch, size_t pos);

        size_t find_first_not_of(const string &other, size_t pos);

        size_t find_first_not_of(const char *other, size_t pos);

        size_t find_first_not_of(const char *other, size_t pos, size_t count);

        size_t find_first_not_of(char ch, size_t pos);

        size_t find_first_of(const string &other, size_t pos);

        size_t find_first_of(const char *other, size_t pos);

        size_t find_first_of(const char *other, size_t pos, size_t count);

        size_t find_first_of(char ch, size_t pos);

        size_t find_last_not_of(const string &other, size_t pos);

        size_t find_last_not_of(const char *other, size_t pos);

        size_t find_last_not_of(const char *other, size_t pos, size_t count);

        size_t find_last_not_of(char ch, size_t pos);

        size_t find_last_of(const string &other, size_t pos);

        size_t find_last_of(const char *other, size_t pos);

        size_t find_last_of(const char *other, size_t pos, size_t count);

        size_t find_last_of(char ch, size_t pos);

        char &front();

        allocator<char> get_allocator();

        string &insert(size_t pos, const string &other);

        string &insert(size_t pos, const string &str, size_t sub_pos, size_t sub_len);

        string &insert(size_t pos, const char *other);

        string &insert(size_t pos, const char *other, size_t num);

        string &insert(size_t pos, size_t num, char ch);

        iterator insert(const_iterator first, char ch);

        iterator insert(const_iterator first, size_t num, char ch);

        iterator insert(const_iterator p, iterator first, iterator last);

        size_t length();

        void pop_back();

        void push_back(const char ch);

        string &replace(const_iterator start, const_iterator end, const char *other);

        string &replace(const_iterator start, const_iterator end, const string &other);

        constexpr void reserve(const size_t new_capacity) noexcept {
            if (new_capacity > capacity_) {
                if (char *new_buffer = alloc_.allocate(new_capacity * sizeof(char))) {
                    memcpy(new_buffer, buffer_, size_ + 1);
                    alloc_.deallocate(buffer_);
                    buffer_ = new_buffer;
                    capacity_ = new_capacity;
                }
            }
        }

        ~string() noexcept {
            if (buffer_) {
                alloc_.deallocate(buffer_);
            }
            buffer_ = nullptr;
        }
    };
} // namespace Dream
