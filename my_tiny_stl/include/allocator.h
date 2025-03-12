#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <memory>

namespace stl_simulation {

    // 自定义的 allocator 类
    template <typename T>
    class allocator {
    public:
        using value_type = T;

        allocator() = default;

        T* allocate(size_t n) {
            if (n == 0) {
                return nullptr;
            }
            return static_cast<T*>(::operator new(n * sizeof(T)));
        }

        void deallocate(T* ptr, size_t n) {
            if (ptr != nullptr) {
                ::operator delete(ptr, n * sizeof(T));
            }
        }

        template <typename U>
        void construct(U* ptr, const U& value) {
            new(ptr) U(value);
        }

        template <typename U>
        void destroy(U* ptr) {
            ptr->~U();
        }
    };

} // namespace stl_simulation

#endif // ALLOCATOR_H
