#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <stdexcept>
#include <functional>

namespace stl_simulation {

    template <typename Key, typename Value>
    class map {
    private:
        struct Node {
            Key key;
            Value value;
            Node* next;

            Node(const Key& key, const Value& value) : key(key), value(value), next(nullptr) {}
        };

        size_t m_size;
        size_t m_capacity;
        Node** m_buckets;
        std::hash<Key> m_hash;

        size_t get_bucket_index(const Key& key) const;

    public:
        map();
        ~map();

        map(const map& other);
        map& operator=(const map& other);

        map(map&& other) noexcept;
        map& operator=(map&& other) noexcept;

        void insert(const Key& key, const Value& value);
        bool contains(const Key& key) const;
        Value& at(const Key& key);
        const Value& at(const Key& key) const;
        void erase(const Key& key);
        bool empty() const;
        size_t size() const;
        void clear();

        class iterator {
        public:
            iterator(Node* node = nullptr) : m_node(node) {}

            // 返回 Node 中存储的 std::pair<Key, Value> 类型数据的引用
            std::pair<Key, Value>& operator*() {
                return *reinterpret_cast<std::pair<Key, Value>*>(&m_node->key);
            }

            // 返回指向 std::pair<Key, Value> 的指针
            std::pair<Key, Value>* operator->() {
                return reinterpret_cast<std::pair<Key, Value>*>(&m_node->key);
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

#endif // MAP_H
