#pragma once
#include <cstdlib>

namespace Dream {
    template<class T>
    class allocator {
    public:
        constexpr allocator() noexcept = default;
        [[nodiscard]] constexpr T *allocate(const size_t size) const noexcept { return (T *) malloc(size * sizeof(T)); }

        [[nodiscard]] constexpr bool reallocate(T *&ptr, const size_t size) const noexcept {
            if (T *res = (T *) realloc(ptr, size * sizeof(T))) {
                ptr = res;
                return true;
            }
            return false;
        }
        constexpr void deallocate(T *ptr) const noexcept { free(ptr); }
        constexpr void construct(T *ptr, const T value) const noexcept { *ptr = value; }
        constexpr void destroy(T *ptr) const noexcept { ptr->~T(); }
    };
}