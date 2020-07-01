cmake_minimum_required(VERSION 3.8)

set(This Practice)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()
add_subdirectory(googletest)

set(Headers
    LintCode.hpp
    LeetCode_GraphProblems.hpp
)

set(Sources
    LintCode.cpp
    LeetCode_GraphProblems.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(test)