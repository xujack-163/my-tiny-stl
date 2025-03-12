cmake_minimum_required(VERSION 3.10)
project(my_tiny_stl)

set(CMAKE_CXX_STANDARD 11)

# 设置包含头文件的路径
include_directories(../include)

# 设置源文件路径
set(SOURCES
        test_vector.cpp
        test_list.cpp
        test_map.cpp
        test_set.cpp
        test_stack.cpp
        test_queue.cpp
        test_unordered_map.cpp
        test_algorithm.cpp
)

# 添加可执行文件
add_executable(my_tiny_stl_test ${SOURCES})

# 添加源文件目录
target_link_libraries(my_tiny_stl_test ${CMAKE_SOURCE_DIR}/src)
