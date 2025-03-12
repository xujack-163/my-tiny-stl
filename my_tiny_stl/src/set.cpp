#include "set.h"

namespace stl_simulation {

template <typename T>
set<T>::set() : m_size(0), m_capacity(16) {
    m_buckets = new Node*[m_capacity]();
}

template <typename T>
set<T>::~set() {
    clear();
    delete[] m_buckets;
}

template <typename T>
set<T>::set(const set& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
    m_buckets = new Node*[m_capacity]();
    for (size_t i = 0; i < m_capacity; ++i) {
        Node* current = other.m_buckets[i];
        while (current) {
            insert(current->data);
            current = current->next;
        }
    }
}

template <typename T>
set<T>& set<T>::operator=(const set& other) {
    if (this != &other) {
        clear();
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_buckets = new Node*[m_capacity]();
        for (size_t i = 0; i < m_capacity; ++i) {
            Node* current = other.m_buckets[i];
            while (current) {
                insert(current->data);
                current = current->next;
            }
        }
    }
    return *this;
}

template <typename T>
set<T>::set(set&& other) noexcept : m_size(other.m_size), m_capacity(other.m_capacity), m_buckets(other.m_buckets) {
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_buckets = nullptr;
}

template <typename T>
set<T>& set<T>::operator=(set&& other) noexcept {
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

template <typename T>
size_t set<T>::get_bucket_index(const T& value) const {
    return m_hash(value) % m_capacity;
}

template <typename T>
void set<T>::insert(const T& value) {
    size_t index = get_bucket_index(value);
    Node* new_node = new Node(value);
    if (!m_buckets[index]) {
        m_buckets[index] = new_node;
    } else {
        Node* current = m_buckets[index];
        while (current) {
            if (current->data == value) {
                delete new_node;
                return; // No duplicates allowed in set
            }
            current = current->next;
        }
        new_node->next = m_buckets[index];
        m_buckets[index] = new_node;
    }
    ++m_size;
}

template <typename T>
bool set<T>::contains(const T& value) const {
    size_t index = get_bucket_index(value);
    Node* current = m_buckets[index];
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void set<T>::erase(const T& value) {
    size_t index = get_bucket_index(value);
    Node* current = m_buckets[index];
    Node* prev = nullptr;
    while (current) {
        if (current->data == value) {
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

template <typename T>
bool set<T>::empty() const {
    return m_size == 0;
}

template <typename T>
size_t set<T>::size() const {
    return m_size;
}

template <typename T>
void set<T>::clear() {
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

template <typename T>
typename set<T>::iterator set<T>::begin() {
    for (size_t i = 0; i < m_capacity; ++i) {
        if (m_buckets[i]) {
            return iterator(m_buckets[i]);
        }
    }
    return end();
}

template <typename T>
typename set<T>::iterator set<T>::end() {
    return iterator(nullptr);
}

} // namespace stl_simulation

// Explicit template instantiations
template class stl_simulation::set<int>;
template class stl_simulation::set<double>;
template class stl_simulation::set<std::string>;

