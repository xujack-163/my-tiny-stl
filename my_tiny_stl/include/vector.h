#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <initializer_list> // 支持初始化列表

namespace stl_simulation {

    template <typename T>
    class vector {
    public:
        vector();
        explicit vector(size_t n, const T& value = T());
        vector(std::initializer_list<T> init);  // 添加初始化列表构造函数
        ~vector();

        vector(const vector& other);
        vector& operator=(const vector& other);

        vector(vector&& other) noexcept;
        vector& operator=(vector&& other) noexcept;

        void push_back(const T& value);
        void pop_back();
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        size_t size() const;
        bool empty() const;
        void clear();
        void resize(size_t new_size, const T& value = T());
        T* begin();
        T* end();

    private:
        size_t m_size;
        size_t m_capacity;
        T* m_data;

        void reallocate(size_t new_capacity);
        void copy_from(const vector& other);
        void move_from(vector&& other) noexcept;
    };

} // namespace stl_simulation

#endif // VECTOR_H
