cmake_minimum_required(VERSION 3.5)

project(statistics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(statistics
    main.cpp
    istatistics.h
    min.h min.cpp
    max.h max.cpp
    mean.h mean.cpp
    std.h std.cpp
    )
