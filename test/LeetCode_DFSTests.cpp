#include "gtest/gtest.h"
#include "../LeetCode_DFS.hpp"

TEST(LC, _0282_ExpressionAddOperators) {
    LC::_0282_ExpressionAddOperators obj;
    std::vector<std::string> base{"1+2+3", "1*2*3"};
    EXPECT_EQ(base, obj.addOperators("123", 6));

    std::vector<std::string> base2{"2+3*2", "2*3+2"};
    EXPECT_EQ(base2, obj.addOperators("232", 8));

    std::vector<std::string> base3{"1*0+5","10-5"};
    EXPECT_EQ(base3, obj.addOperators("105", 5));   
}