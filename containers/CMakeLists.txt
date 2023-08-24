cmake_minimum_required(VERSION 3.5)

project(containers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(containers
    main.cpp
    myarray.h
    mylist.h
    )
add_executable(containers_test
    main_test.cpp
    myarray_test.h
    mylist_test.h
    )
target_link_libraries(containers_test gtest)
