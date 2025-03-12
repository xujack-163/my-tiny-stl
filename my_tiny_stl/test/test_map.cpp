#include "map.h"
#include <iostream>
#include <cassert>

void test_map() {
    stl_simulation::map<int, std::string> mp;

    // 测试 insert 和 at
    mp.insert(1, "one");
    mp.insert(2, "two");
    assert(mp.size() == 2);
    assert(mp.at(1) == "one");
    assert(mp.at(2) == "two");
    std::cout << "map insert/at test passed." << std::endl;

    // 测试 contains
    assert(mp.contains(1));
    assert(!mp.contains(3));
    std::cout << "map contains test passed." << std::endl;

    // 测试 erase
    mp.erase(1);
    assert(mp.size() == 1);
    assert(!mp.contains(1));
    std::cout << "map erase test passed." << std::endl;

    // 测试 clear
    mp.clear();
    assert(mp.size() == 0);
    std::cout << "map clear test passed." << std::endl;
}

