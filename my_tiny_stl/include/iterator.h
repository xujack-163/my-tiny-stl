#ifndef ITERATOR_H
#define ITERATOR_H

namespace stl_simulation {

    template <typename T>
    class iterator {
    public:
        iterator(T* ptr = nullptr) : m_ptr(ptr) {}

        T& operator*() {
            return *m_ptr;
        }

        T* operator->() {
            return m_ptr;
        }

        iterator& operator++() {
            ++m_ptr;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++m_ptr;
            return temp;
        }

        bool operator!=(const iterator& other) const {
            return m_ptr != other.m_ptr;
        }

        bool operator==(const iterator& other) const {
            return m_ptr == other.m_ptr;
        }

    private:
        T* m_ptr;
    };

} // namespace stl_simulation

#endif // ITERATOR_H
