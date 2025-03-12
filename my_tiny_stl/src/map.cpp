#include "map.h"

namespace stl_simulation {

template <typename Key, typename Value>
map<Key, Value>::map() : m_size(0), m_capacity(16) {
    m_buckets = new Node*[m_capacity]();
}

template <typename Key, typename Value>
map<Key, Value>::~map() {
    clear();
    delete[] m_buckets;
}

template <typename Key, typename Value>
map<Key, Value>::map(const map& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
    m_buckets = new Node*[m_capacity]();
    for (size_t i = 0; i < m_capacity; ++i) {
        Node* current = other.m_buckets[i];
        while (current) {
            insert(current->key, current->value);
            current = current->next;
        }
    }
}

template <typename Key, typename Value>
map<Key, Value>& map<Key, Value>::operator=(const map& other) {
    if (this != &other) {
        clear();
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_buckets = new Node*[m_capacity]();
        for (size_t i = 0; i < m_capacity; ++i) {
            Node* current = other.m_buckets[i];
            while (current) {
                insert(current->key, current->value);
                current = current->next;
            }
        }
    }
    return *this;
}

template <typename Key, typename Value>
map<Key, Value>::map(map&& other) noexcept : m_size(other.m_size), m_capacity(other.m_capacity), m_buckets(other.m_buckets) {
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_buckets = nullptr;
}

template <typename Key, typename Value>
map<Key, Value>& map<Key, Value>::operator=(map&& other) noexcept {
    if (this != &other) {
        clear();
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_buckets = other.m_buckets;
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_buckets = nullptr;
    }
    return *this;
}

template <typename Key, typename Value>
size_t map<Key, Value>::get_bucket_index(const Key& key) const {
    return m_hash(key) % m_capacity;
}

template <typename Key, typename Value>
void map<Key, Value>::insert(const Key& key, const Value& value) {
    size_t index = get_bucket_index(key);
    Node* new_node = new Node(key, value);
    if (!m_buckets[index]) {
        m_buckets[index] = new_node;
    } else {
        Node* current = m_buckets[index];
        while (current) {
            if (current->key == key) {
                current->value = value;
                delete new_node;
                return;
            }
            current = current->next;
        }
        new_node->next = m_buckets[index];
        m_buckets[index] = new_node;
    }
    ++m_size;
}

template <typename Key, typename Value>
bool map<Key, Value>::contains(const Key& key) const {
    size_t index = get_bucket_index(key);
    Node* current = m_buckets[index];
    while (current) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename Key, typename Value>
Value& map<Key, Value>::at(const Key& key) {
    size_t index = get_bucket_index(key);
    Node* current = m_buckets[index];
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    throw std::out_of_range("key not found");
}

template <typename Key, typename Value>
const Value& map<Key, Value>::at(const Key& key) const {
    size_t index = get_bucket_index(key);
    Node* current = m_buckets[index];
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    throw std::out_of_range("key not found");
}

template <typename Key, typename Value>
void map<Key, Value>::erase(const Key& key) {
    size_t index = get_bucket_index(key);
    Node* current = m_buckets[index];
    Node* prev = nullptr;
    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            } else {
                m_buckets[index] = current->next;
            }
            delete current;
            --m_size;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <typename Key, typename Value>
bool map<Key, Value>::empty() const {
    return m_size == 0;
}

template <typename Key, typename Value>
size_t map<Key, Value>::size() const {
    return m_size;
}

template <typename Key, typename Value>
void map<Key, Value>::clear() {
    for (size_t i = 0; i < m_capacity; ++i) {
        Node* current = m_buckets[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        m_buckets[i] = nullptr;
    }
    m_size = 0;
}

template <typename Key, typename Value>
typename map<Key, Value>::iterator map<Key, Value>::begin() {
    for (size_t i = 0; i < m_capacity; ++i) {
        if (m_buckets[i]) {
            return iterator(m_buckets[i]);
        }
    }
    return end();
}

template <typename Key, typename Value>
typename map<Key, Value>::iterator map<Key, Value>::end() {
    return iterator(nullptr);
}

// 显式实例化 map<int, std::string> 的所有成员函数
template class stl_simulation::map<int, std::string>;
template class stl_simulation::map<int, double>;
template class stl_simulation::map<std::string, int>;
template class stl_simulation::map<double, double>;

} // namespace stl_simulation
