cmake_minimum_required(VERSION 3.8)

set(This PracticeTest)


set(Sources
    LintCodeTest.cpp
    LeetCode_GraphProblemsTest.cpp
    LeetCode_ArrayProblemTests.cpp
    LeetCode_BinarySearchProblemTests.cpp
    LeetCode_LinkListProblemTests.cpp
    LeetCode_SlidingWindowProblemTests.cpp
    LeetCode_StringProblemTests.cpp
    LeetCode_MathProblemTests.cpp
    LeetCode_DynamicProgrammingProblemTests.cpp
    LeetCode_DesignDrivenProblemsTests.cpp
    LeetCode_GreedyAlgorithmProblemTests.cpp
    LeetCode_BacktracingProblemTests.cpp
    LeetCode_BitOperationProblemTests.cpp
    LeetCode_TreeProblemTests.cpp
    LeetCode_RecursiveProblemTests.cpp
    LeetCode_HashProblemTests.cpp
    LeetCode_BFSTests.cpp
    LeetCode_DFSTests.cpp
    LeetCode_UnionFindProblemTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    Practice
)

add_test(
    NAME ${This}
    COMMAND ${This}
)


    