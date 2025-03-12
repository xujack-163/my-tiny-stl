#include "vector.h"
#include <iostream>
#include <cassert>

void test_vector() {
    std::cout << "Testing vector..." << std::endl;

    // 测试默认构造
    stl_simulation::vector<int> vec;
    assert(vec.size() == 0);
    assert(vec.empty());
    std::cout << "Default constructor test passed." << std::endl;

    // 测试指定大小构造，带默认值
    stl_simulation::vector<int> vec2(3, 5);  // 初始为 3 个 5
    assert(vec2.size() == 3);
    assert(vec2[0] == 5 && vec2[1] == 5 && vec2[2] == 5);
    std::cout << "Constructor with size and default value test passed." << std::endl;

    // 测试初始化列表构造
    stl_simulation::vector<int> vec3 = {1, 2, 3, 4, 5};
    assert(vec3.size() == 5);
    assert(vec3[0] == 1 && vec3[4] == 5);
    std::cout << "Initializer list constructor test passed." << std::endl;

    // 测试拷贝构造
    stl_simulation::vector<int> vec4 = vec3;  // 拷贝构造
    assert(vec4.size() == 5);
    assert(vec4[0] == 1 && vec4[4] == 5);
    std::cout << "Copy constructor test passed." << std::endl;

    // 测试移动构造
    stl_simulation::vector<int> vec5 = std::move(vec4);  // 移动构造
    assert(vec4.size() == 0);  // vec4 现在应该为空
    assert(vec5.size() == 5);
    assert(vec5[0] == 1 && vec5[4] == 5);
    std::cout << "Move constructor test passed." << std::endl;

    // 测试 push_back 和 pop_back
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    assert(vec.size() == 3);
    assert(vec[0] == 10 && vec[2] == 30);
    vec.pop_back();
    assert(vec.size() == 2);
    assert(vec[1] == 20);
    std::cout << "push_back/pop_back test passed." << std::endl;

    // 测试 operator[]
    vec.push_back(40);
    std::cout << "Testing indexing: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "vec[" << i << "] = " << vec[i] << " ";
    }
    std::cout << std::endl;
    assert(vec[0] == 10 && vec[1] == 20 && vec[2] == 40);
    std::cout << "Indexing test passed." << std::endl;

    // 测试 resize 扩大和缩小
    vec.resize(5, 50);  // 扩展为 5 个元素，并填充 50
    std::cout << "After resize to 5 with fill value 50: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "vec[" << i << "] = " << vec[i] << " ";
    }
    std::cout << std::endl;
    assert(vec.size() == 5 && vec[3] == 50 && vec[4] == 50);

    vec.resize(3);  // 缩小为 3
    std::cout << "After resize to 3: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "vec[" << i << "] = " << vec[i] << " ";
    }
    std::cout << std::endl;
    assert(vec.size() == 3);
    std::cout << "Resize test passed." << std::endl;

    // 测试 clear 和 empty
    vec.clear();
    assert(vec.size() == 0);
    assert(vec.empty());
    std::cout << "clear and empty test passed." << std::endl;

    // 测试初始化列表构造后的 size 和元素
    stl_simulation::vector<int> vec6 = {5, 10, 15};
    assert(vec6.size() == 3);
    assert(vec6[0] == 5 && vec6[1] == 10 && vec6[2] == 15);
    std::cout << "Initializer list test passed." << std::endl;
}
