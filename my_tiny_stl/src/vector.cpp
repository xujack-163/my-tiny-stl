#include "vector.h"

namespace stl_simulation {

template <typename T>
vector<T>::vector() : m_size(0), m_capacity(10), m_data(new T[10]) {}

template <typename T>
vector<T>::vector(size_t n, const T& value) : m_size(n), m_capacity(n), m_data(new T[n]) {
    std::fill(m_data, m_data + n, value);
}

template <typename T>
vector<T>::vector(std::initializer_list<T> init) : m_size(init.size()), m_capacity(init.size()), m_data(new T[init.size()]) {
    std::copy(init.begin(), init.end(), m_data);
}

template <typename T>
vector<T>::~vector() {
    delete[] m_data;
}

template <typename T>
vector<T>::vector(const vector& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[other.m_capacity]) {
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
}

template <typename T>
vector<T>& vector<T>::operator=(const vector& other) {
    if (this != &other) {
        delete[] m_data;
        copy_from(other);
    }
    return *this;
}

template <typename T>
vector<T>::vector(vector&& other) noexcept : m_size(other.m_size), m_capacity(other.m_capacity), m_data(other.m_data) {
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_data = nullptr;
}

template <typename T>
vector<T>& vector<T>::operator=(vector&& other) noexcept {
    if (this != &other) {
        delete[] m_data;
        move_from(std::move(other));
    }
    return *this;
}

template <typename T>
void vector<T>::push_back(const T& value) {
    if (m_size == m_capacity) {
        reallocate(m_capacity * 2);
    }
    m_data[m_size++] = value;
}

template <typename T>
void vector<T>::pop_back() {
    if (m_size > 0) {
        --m_size;
    } else {
        throw std::out_of_range("vector is empty");
    }
}

template <typename T>
T& vector<T>::operator[](size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("index out of bounds");
    }
    return m_data[index];
}

template <typename T>
const T& vector<T>::operator[](size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("index out of bounds");
    }
    return m_data[index];
}

template <typename T>
size_t vector<T>::size() const {
    return m_size;
}

template <typename T>
bool vector<T>::empty() const {
    return m_size == 0;
}

template <typename T>
void vector<T>::clear() {
    m_size = 0;
}

template <typename T>
void vector<T>::resize(size_t new_size, const T& value) {
    if (new_size > m_capacity) {
        reallocate(new_size);
    }
    if (new_size > m_size) {
        std::fill(m_data + m_size, m_data + new_size, value);
    }
    m_size = new_size;
}

template <typename T>
T* vector<T>::begin() {
    return m_data;
}

template <typename T>
T* vector<T>::end() {
    return m_data + m_size;
}

template <typename T>
void vector<T>::reallocate(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    std::copy(m_data, m_data + m_size, new_data);
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;
}

template <typename T>
void vector<T>::copy_from(const vector& other) {
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new T[m_capacity];
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

template <typename T>
void vector<T>::move_from(vector&& other) noexcept {
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = other.m_data;
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_data = nullptr;
}

// 显式实例化模板
template class vector<int>;
template class vector<double>;
template class vector<std::string>;

} // namespace stl_simulation
