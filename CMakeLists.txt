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
    LeetCode_ArrayProblems.hpp
    LeetCode_GraphProblems.hpp
    LeetCode_LinkListProblems.hpp
    LeetCode_SlidingWindowProblems.hpp
    LeetCode_StringProblems.hpp
    LeetCode_MathProblems.hpp
    LeetCode_DynamicProgrammingProblems.hpp
    LeetCode_GreedyAlgorithmProblems.hpp
    LeetCode_BacktracingProblems.hpp
    LeetCode_BitOperationProblems.hpp
    LeetCode_TreeProblems.hpp
    LeetCode_RecursiveProblems.hpp
    LeetCode_HashProblems.hpp
    LeetCode_BFS.hpp
    LeetCode_DFS.hpp
)

set(Sources
    LintCode.cpp
    LeetCode_ArrayProblems.cpp
    LeetCode_GraphProblems.cpp
    LeetCode_LinkListProblems.cpp
    LeetCode_SlidingWindowProblems.cpp
    LeetCode_StringProblems.cpp
    LeetCode_MathProblems.cpp
    LeetCode_DynamicProgrammingProblems.cpp
    LeetCode_GreedyAlgorithmProblems.cpp
    LeetCode_BacktracingProblems.cpp
    LeetCode_BitOperationProblems.cpp
    LeetCode_TreeProblems.cpp
    LeetCode_RecursiveProblems.cpp
    LeetCode_HashProblems.cpp
    LeetCode_BFS.cpp
    LeetCode_DFS.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(test)