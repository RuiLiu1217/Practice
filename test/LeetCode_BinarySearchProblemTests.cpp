#include "gtest/gtest.h"
#include "../LeetCode_BinarySearchProblem.hpp"

TEST(LC, _0278_FirstBadVersion) {
    LC::_0278_FirstBadVersion obj;
    EXPECT_EQ(obj.firstBadVersion(1), 1);
}