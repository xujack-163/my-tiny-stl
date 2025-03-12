cmake_minimum_required(VERSION 3.30)
project(my_tiny_stl)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(my_tiny_stl
        include/allocator.h
        include/iterator.h
        include/vector.h
        include/list.h
        include/set.h
        include/stack.h
        include/queue.h
        include/map.h
        include/algorithm.h
        test/test_vector.cpp
        test/test_map.cpp
        test/test_algorithm.cpp
        test/test_queue.cpp
        test/test_stack.cpp
        test/test_set.cpp
        src/vector.cpp
        src/list.cpp
        src/map.cpp
        src/set.cpp
        src/stack.cpp
        src/queue.cpp
        src/algorithm.cpp
        src/iterator.cpp
        src/allocator.cpp
        test/test_list.cpp
        test/main_test.cpp
)

#add_library(tiny_stl STATIC ${SOURCES})