#include "list.h"
#include <iostream>
#include <cassert>

void test_list() {
    stl_simulation::list<int> lst;

    // 测试 push_front 和 push_back
    lst.push_back(1);
    lst.push_front(2);
    lst.push_back(3);
    assert(lst.size() == 3);
    assert(lst.front() == 2);
    assert(lst.back() == 3);
    std::cout << "list push_back/push_front test passed." << std::endl;

    // 测试 pop_front 和 pop_back
    lst.pop_front();
    lst.pop_back();
    assert(lst.size() == 1);
    assert(lst.front() == 1);
    std::cout << "list pop_back/pop_front test passed." << std::endl;

    // 测试 clear
    lst.clear();
    assert(lst.size() == 0);
    std::cout << "list clear test passed." << std::endl;
}

