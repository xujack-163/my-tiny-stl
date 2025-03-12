#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

namespace stl_simulation {

    template <typename T>
    class list {
    private:
        struct Node {
            T data;
            Node* prev;
            Node* next;

            Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
        };

    public:
        list();
        ~list();

        list(const list& other);
        list& operator=(const list& other);

        list(list&& other) noexcept;
        list& operator=(list&& other) noexcept;

        void push_back(const T& value);
        void push_front(const T& value);
        void pop_back();
        void pop_front();
        T& front();
        const T& front() const;  // 添加 const 版本
        T& back();
        const T& back() const;  // 添加 const 版本
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

            iterator operator++(int) {
                iterator temp = *this;
                m_node = m_node->next;
                return temp;
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

    private:
        Node* m_head;
        Node* m_tail;
        size_t m_size;
        void copy_from(const list& other);
        void move_from(list&& other) noexcept;
    };

} // namespace stl_simulation

#endif // LIST_H
