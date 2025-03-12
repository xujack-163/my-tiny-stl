#include "algorithm.h"
#include "vector.h"
#include <iostream>
#include <cassert>

void test_algorithm() {
    stl_simulation::vector<int> vec = {3, 1, 2, 4, 5};

    // 测试 sort
    stl_simulation::sort(vec.begin(), vec.end());
    assert(vec[0] == 1);
    assert(vec[1] == 2);
    assert(vec[2] == 3);
    assert(vec[3] == 4);
    assert(vec[4] == 5);
    std::cout << "algorithm sort test passed." << std::endl;

    // 测试 find
    auto it = stl_simulation::find(vec.begin(), vec.end(), 3);
    assert(it != vec.end());
    std::cout << "algorithm find test passed." << std::endl;

    // 测试 binary_search
    bool found = stl_simulation::binary_search(vec.begin(), vec.end(), 4);
    assert(found);
    std::cout << "algorithm binary_search test passed." << std::endl;
}

