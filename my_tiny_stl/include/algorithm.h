#ifndef ALGORITHM_H
#define ALGORITHM_H

namespace stl_simulation {

    // 常用的算法函数
    template <typename Iterator, typename Compare>
    void sort(Iterator first, Iterator last, Compare comp);

    template <typename Iterator>
    void sort(Iterator first, Iterator last);

    template <typename Iterator, typename T>
    Iterator find(Iterator first, Iterator last, const T& value);

    template <typename Iterator, typename T>
    bool binary_search(Iterator first, Iterator last, const T& value);

} // namespace stl_simulation

#endif // ALGORITHM_H
