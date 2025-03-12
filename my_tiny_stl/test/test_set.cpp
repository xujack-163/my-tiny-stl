
#include "set.h"
#include <iostream>
#include <cassert>

void test_set() {
    stl_simulation::set<int> s;

    // 测试 insert 和 contains
    s.insert(1);
    s.insert(2);
    s.insert(3);
    assert(s.size() == 3);
    assert(s.contains(1));
    assert(!s.contains(4));
    std::cout << "set insert/contains test passed." << std::endl;

    // 测试 erase
    s.erase(2);
    assert(s.size() == 2);
    assert(!s.contains(2));
    std::cout << "set erase test passed." << std::endl;

    // 测试 clear
    s.clear();
    assert(s.size() == 0);
    std::cout << "set clear test passed." << std::endl;
}

