#ifndef SET_H
#define SET_H

#include <iostream>
#include <stdexcept>
#include <functional>

namespace stl_simulation {

    template <typename T>
    class set {
    private:
        struct Node {
            T data;
            Node* next;

            Node(const T& value) : data(value), next(nullptr) {}
        };

        size_t m_size;
        size_t m_capacity;
        Node** m_buckets;
        std::hash<T> m_hash;

        size_t get_bucket_index(const T& value) const;

    public:
        set();
        ~set();

        set(const set& other);
        set& operator=(const set& other);

        set(set&& other) noexcept;
        set& operator=(set&& other) noexcept;

        void insert(const T& value);
        bool contains(const T& value) const;
        void erase(const T& value);
        bool empty() const;
        size_t size() const;
        void clear();

        class iterator {
        public:
            iterator(Node* node = nullptr) : m_node(node) {}

            T& operator*() {
                return m_node->data;
            }

            T* operator->() {
                return &(m_node->data);
            }

            iterator& operator++() {
                m_node = m_node->next;
                return *this;
            }

            bool operator!=(const iterator& other) const {
                return m_node != other.m_node;
            }

            bool operator==(const iterator& other) const {
                return m_node == other.m_node;
            }

        private:
            Node* m_node;
        };

        iterator begin();
        iterator end();
    };

} // namespace stl_simulation

#endif // SET_H
