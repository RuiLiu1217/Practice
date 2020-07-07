#include <gtest/gtest.h>
#include "../LeetCode_RecursiveProblems.hpp"

TEST(LC, _0050_PowXN) {
    LC::_0050_PowXN obj;
    EXPECT_EQ(obj.myPow(2.0, 2), 4.0);
    EXPECT_EQ(obj.myPow(2.0, -2), 1.0/4.0);
    EXPECT_EQ(obj.myPow(2.0, 0), 1.0);
}