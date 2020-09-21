#include <gtest/gtest.h>
#include "../LeetCode_BitOperationProblems.hpp"

TEST(LC, _0260_SingleNumberII) {
    LC::_0260_SingleNumberII obj;
    std::vector<int> a{1,1,2,2,3,4,5,5};
    std::vector<int> b{3,4};
    EXPECT_EQ(obj.singleNumber(a), b);
}

TEST(LC, _0201_BitwiseANDofNumbersRange) {
    LC::_0201_BitwiseANDofNumbersRange obj;
    EXPECT_EQ(obj.rangeBitwiseAnd(5345, 7734), 4096);
}