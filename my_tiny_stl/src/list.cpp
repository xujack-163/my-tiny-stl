#include "list.h"

namespace stl_simulation {

template <typename T>
list<T>::list() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

template <typename T>
list<T>::~list() {
    clear();
}

template <typename T>
list<T>::list(const list& other) : m_head(nullptr), m_tail(nullptr), m_size(0) {
    copy_from(other);
}

template <typename T>
list<T>& list<T>::operator=(const list& other) {
    if (this != &other) {
        clear();
        copy_from(other);
    }
    return *this;
}

template <typename T>
list<T>::list(list&& other) noexcept : m_head(other.m_head), m_tail(other.m_tail), m_size(other.m_size) {
    other.m_head = other.m_tail = nullptr;
    other.m_size = 0;
}

template <typename T>
list<T>& list<T>::operator=(list&& other) noexcept {
    if (this != &other) {
        clear();
        m_head = other.m_head;
        m_tail = other.m_tail;
        m_size = other.m_size;
        other.m_head = other.m_tail = nullptr;
        other.m_size = 0;
    }
    return *this;
}

template <typename T>
void list<T>::push_back(const T& value) {
    Node* new_node = new Node(value);
    if (empty()) {
        m_head = m_tail = new_node;
    } else {
        m_tail->next = new_node;
        new_node->prev = m_tail;
        m_tail = new_node;
    }
    ++m_size;
}

template <typename T>
void list<T>::push_front(const T& value) {
    Node* new_node = new Node(value);
    if (empty()) {
        m_head = m_tail = new_node;
    } else {
        new_node->next = m_head;
        m_head->prev = new_node;
        m_head = new_node;
    }
    ++m_size;
}

template <typename T>
void list<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("list is empty");
    }
    Node* temp = m_tail;
    m_tail = m_tail->prev;
    if (m_tail) {
        m_tail->next = nullptr;
    } else {
        m_head = nullptr;
    }
    delete temp;
    --m_size;
}

template <typename T>
void list<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("list is empty");
    }
    Node* temp = m_head;
    m_head = m_head->next;
    if (m_head) {
        m_head->prev = nullptr;
    } else {
        m_tail = nullptr;
    }
    delete temp;
    --m_size;
}

template <typename T>
T& list<T>::front() {
    if (empty()) {
        throw std::out_of_range("list is empty");
    }
    return m_head->data;
}

template <typename T>
const T& list<T>::front() const {  // const 版本
    if (empty()) {
        throw std::out_of_range("list is empty");
    }
    return m_head->data;
}

template <typename T>
T& list<T>::back() {
    if (empty()) {
        throw std::out_of_range("list is empty");
    }
    return m_tail->data;
}

template <typename T>
const T& list<T>::back() const {  // const 版本
    if (empty()) {
        throw std::out_of_range("list is empty");
    }
    return m_tail->data;
}

template <typename T>
bool list<T>::empty() const {
    return m_size == 0;
}

template <typename T>
size_t list<T>::size() const {
    return m_size;
}

template <typename T>
void list<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
    return iterator(m_head);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
    return iterator(nullptr);
}

template <typename T>
void list<T>::copy_from(const list& other) {
    for (Node* current = other.m_head; current != nullptr; current = current->next) {
        push_back(current->data);
    }
}

template <typename T>
void list<T>::move_from(list&& other) noexcept {
    m_head = other.m_head;
    m_tail = other.m_tail;
    m_size = other.m_size;
    other.m_head = other.m_tail = nullptr;
    other.m_size = 0;
}

} // namespace stl_simulation

// Explicit template instantiations
template class stl_simulation::list<int>;
template class stl_simulation::list<double>;
template class stl_simulation::list<std::string>;
