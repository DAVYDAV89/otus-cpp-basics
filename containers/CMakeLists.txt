cmake_minimum_required(VERSION 3.5)

project(containers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(containers
    main.cpp
    myvec.h
    mylist.h
    )
