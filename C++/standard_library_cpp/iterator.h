namespace Dream {
    template<class T, class Child>
    class iterator {
    protected:
        T *ptr_ = nullptr;

    public:
        constexpr iterator() noexcept = default;
        constexpr iterator(const T *value) noexcept : ptr_((T *) value) {}
        constexpr iterator(const iterator &itr) noexcept : ptr_(itr.ptr_) {}

        constexpr Child operator+(const size_t offset) const noexcept { return ptr_ + offset; }
        constexpr Child operator-(const size_t offset) const noexcept { return ptr_ - offset; }
        constexpr size_t operator-(const iterator &other) const noexcept { return ptr_ - other.ptr_; }
        constexpr bool operator==(const iterator &itr) const noexcept { return ptr_ == itr.ptr_; }
        constexpr bool operator!=(const iterator &itr) const noexcept { return ptr_ != itr.ptr_; }
        constexpr T &operator*() const noexcept { return *ptr_; }
        constexpr operator const void *() const noexcept { return (const void *) ptr_; }
        constexpr operator const T *() const noexcept { return (const T *) ptr_; }

        constexpr Child &operator=(const T value) noexcept {
            *ptr_ = value;
            return *((Child *) this);
        }

        constexpr Child &operator=(const iterator &other) noexcept {
            if (this != &other) {
                ptr_ = other.ptr_;
                return *((Child *) this);
            }
            return *((Child *) this);
        }

        constexpr Child &operator++() noexcept {
            ++ptr_;
            return *((Child *) this);
        }

        constexpr Child operator++(int) noexcept {
            Child temp = *((Child *) this);
            ++ptr_;
            return temp;
        }

        constexpr Child &operator--() noexcept {
            --ptr_;
            return *((Child *) this);
        }

        constexpr Child operator--(int) noexcept {
            Child temp = *((Child *) this);
            --ptr_;
            return temp;
        }

        constexpr Child &operator+=(const size_t offset) noexcept {
            ptr_ += offset;
            return *((Child *) this);
        }

        constexpr Child &operator-=(const size_t offset) noexcept {
            ptr_ -= offset;
            return *((Child *) this);
        }
    };


    template<class T, class Child>
    class reverse_iterator : public iterator<T, reverse_iterator<T, Child>> {
    protected:
        using iterator<T, reverse_iterator>::ptr_;

    public:
        using iterator<T, reverse_iterator>::iterator;

        constexpr Child &operator++() noexcept {
            --ptr_;
            return *this;
        }

        constexpr Child operator++(int) noexcept {
            Child temp = *this;
            --ptr_;
            return temp;
        }

        constexpr Child &operator--() noexcept {
            ++ptr_;
            return *this;
        }

        Child operator--(int) noexcept {
            Child temp = *this;
            ++ptr_;
            return temp;
        }

        constexpr Child &operator+=(const size_t offset) noexcept {
            ptr_ -= offset;
            return *this;
        }

        constexpr Child &operator-=(const size_t offset) noexcept {
            ptr_ += offset;
            return *this;
        }
    };
}