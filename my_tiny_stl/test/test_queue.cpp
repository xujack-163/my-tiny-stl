
#include "queue.h"
#include <iostream>
#include <cassert>

void test_queue() {
    stl_simulation::queue<int> q;

    // 测试 push 和 front/back
    q.push(1);
    q.push(2);
    q.push(3);
    assert(q.size() == 3);
    assert(q.front() == 1);
    assert(q.back() == 3);
    std::cout << "queue push/front/back test passed." << std::endl;

    // 测试 pop
    q.pop();
    assert(q.size() == 2);
    assert(q.front() == 2);
    std::cout << "queue pop test passed." << std::endl;

    // 测试 clear
    q.pop();
    q.pop();
    assert(q.empty());
    std::cout << "queue clear test passed." << std::endl;
}

