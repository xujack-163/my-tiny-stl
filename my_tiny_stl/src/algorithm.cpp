#include "algorithm.h"
#include <algorithm>  // 添加标准库的算法头文件
#include <functional> // 添加函数对象相关的头文件

namespace stl_simulation {

// 快速排序算法
template <typename Iterator, typename Compare>
void quick_sort(Iterator first, Iterator last, Compare comp) {
    if (first == last) return;

    auto pivot = *first;
    Iterator low = first + 1;
    Iterator high = last - 1;  // 修正 high 为 last - 1

    while (low <= high) {
        // 移动 low 向右，直到找到一个比 pivot 大的元素
        while (low <= last && comp(*low, pivot)) ++low;

        // 移动 high 向左，直到找到一个比 pivot 小的元素
        while (high > first && comp(pivot, *high)) --high;

        if (low <= high) {
            // 交换 low 和 high 处的元素
            std::swap(*low, *high);
            ++low;
            --high;
        }
    }

    // 将 pivot 与 high 处的元素交换
    std::swap(*first, *high);

    // 递归地对两个区间进行排序
    quick_sort(first, high, comp);
    quick_sort(low, last, comp);
}

template <typename Iterator>
void sort(Iterator first, Iterator last) {
    quick_sort(first, last, std::less<typename std::iterator_traits<Iterator>::value_type>());
}

template <typename Iterator, typename Compare>
void sort(Iterator first, Iterator last, Compare comp) {
    quick_sort(first, last, comp);
}

template <typename Iterator, typename T>
Iterator find(Iterator first, Iterator last, const T& value) {
    for (Iterator it = first; it != last; ++it) {
        if (*it == value) {
            return it;
        }
    }
    return last;
}

template <typename Iterator, typename T>
bool binary_search(Iterator first, Iterator last, const T& value) {
    while (first < last) {
        Iterator middle = first + (last - first) / 2;
        if (*middle == value) {
            return true;
        } else if (*middle < value) {
            first = middle + 1;
        } else {
            last = middle;
        }
    }
    return false;
}

} // namespace stl_simulation

// 显式模板实例化
template void stl_simulation::sort<int*>(int*, int*);
template void stl_simulation::sort<int*, std::greater<int>>(int*, int*, std::greater<int>);

template int* stl_simulation::find<int*, int>(int*, int*, const int&);
template bool stl_simulation::binary_search<int*, int>(int*, int*, const int&);
