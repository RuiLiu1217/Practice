cmake_minimum_required(VERSION 3.8)

set(This PracticeTest)


set(Sources
    LintCodeTest.cpp
    LeetCode_GraphProblemsTest.cpp
    LeetCode_ArrayProblemTests.cpp
    LeetCode_LinkListProblemTests.cpp
    LeetCode_SlidingWindowProblemTests.cpp
    LeetCode_StringProblemTests.cpp
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


    