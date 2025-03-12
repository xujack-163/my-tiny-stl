#ifndef STACK_H
#define STACK_H

#include "vector.h"

namespace stl_simulation {

    template <typename T>
    class stack {
    public:
        stack();
        ~stack();

        bool empty() const;
        size_t size() const;
        void push(const T& value);
        void pop();
        T& top();
        const T& top() const;

    private:
        vector<T> m_data;
    };

} // namespace stl_simulation

#endif // STACK_H
