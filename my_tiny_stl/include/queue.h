#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

namespace stl_simulation {

    template <typename T>
    class queue {
    public:
        queue();
        ~queue();

        bool empty() const;
        size_t size() const;
        void push(const T& value);
        void pop();
        T& front();
        const T& front() const;
        T& back();
        const T& back() const;

    private:
        list<T> m_data;
    };

} // namespace stl_simulation

#endif // QUEUE_H
