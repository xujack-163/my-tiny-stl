
#include "stack.h"
#include <iostream>
#include <cassert>

void test_stack() {
    stl_simulation::stack<int> stk;

    // 测试 push 和 top
    stk.push(1);
    stk.push(2);
    stk.push(3);
    assert(stk.size() == 3);
    assert(stk.top() == 3);
    std::cout << "stack push/top test passed." << std::endl;

    // 测试 pop
    stk.pop();
    assert(stk.size() == 2);
    assert(stk.top() == 2);
    std::cout << "stack pop test passed." << std::endl;

    // 测试 clear
    stk.pop();
    stk.pop();
    assert(stk.empty());
    std::cout << "stack clear test passed." << std::endl;
}
