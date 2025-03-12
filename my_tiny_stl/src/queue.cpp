#include "queue.h"

namespace stl_simulation {

    template <typename T>
    queue<T>::queue() {}

    template <typename T>
    queue<T>::~queue() {}

    template <typename T>
    bool queue<T>::empty() const {
        return m_data.empty();
    }

    template <typename T>
    size_t queue<T>::size() const {
        return m_data.size();
    }

    template <typename T>
    void queue<T>::push(const T& value) {
        m_data.push_back(value);
    }

    template <typename T>
    void queue<T>::pop() {
        if (empty()) {
            throw std::out_of_range("queue is empty");
        }
        m_data.pop_front();
    }

    template <typename T>
    T& queue<T>::front() {
        if (empty()) {
            throw std::out_of_range("queue is empty");
        }
        return m_data.front();
    }

    template <typename T>
    const T& queue<T>::front() const {
        if (empty()) {
            throw std::out_of_range("queue is empty");
        }
        return m_data.front();
    }

    template <typename T>
    T& queue<T>::back() {
        if (empty()) {
            throw std::out_of_range("queue is empty");
        }
        return m_data.back();
    }

    template <typename T>
    const T& queue<T>::back() const {
        if (empty()) {
            throw std::out_of_range("queue is empty");
        }
        return m_data.back();
    }

} // namespace stl_simulation

// Explicit template instantiations
template class stl_simulation::queue<int>;
template class stl_simulation::queue<double>;
template class stl_simulation::queue<std::string>;

