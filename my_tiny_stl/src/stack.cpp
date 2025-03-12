#include "stack.h"

namespace stl_simulation {

    template <typename T>
    stack<T>::stack() {}

    template <typename T>
    stack<T>::~stack() {}

    template <typename T>
    bool stack<T>::empty() const {
        return m_data.empty();
    }

    template <typename T>
    size_t stack<T>::size() const {
        return m_data.size();
    }

    template <typename T>
    void stack<T>::push(const T& value) {
        m_data.push_back(value);
    }

    template <typename T>
    void stack<T>::pop() {
        if (empty()) {
            throw std::out_of_range("stack is empty");
        }
        m_data.pop_back();
    }

    template <typename T>
    T& stack<T>::top() {
        if (empty()) {
            throw std::out_of_range("stack is empty");
        }
        return m_data[m_data.size() - 1];
    }

    template <typename T>
    const T& stack<T>::top() const {
        if (empty()) {
            throw std::out_of_range("stack is empty");
        }
        return m_data[m_data.size() - 1];
    }

} // namespace stl_simulation

// Explicit template instantiations
template class stl_simulation::stack<int>;
template class stl_simulation::stack<double>;
template class stl_simulation::stack<std::string>;

