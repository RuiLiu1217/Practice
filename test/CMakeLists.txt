cmake_minimum_required(VERSION 3.8)

set(SOURCES
)

add_executable(penguin_test ${SOURCES})
target_link_libraries( penguin_test PUBLIC
    gtest_main
    core
)


    