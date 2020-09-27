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

TEST(LC, _371) {
    LC::_0371_SumOfTwoIntegers obj;
    EXPECT_EQ(obj.getSum(1,2), 3);
}

TEST(LC, _0401) {
    LC::_0401_BinaryWatch obj;
    std::vector<std::string> base{"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"};
    EXPECT_EQ(obj.readBinaryWatch(1), base);
}

TEST(LC, _0405) {
    LC::_0405_ConvertANumberToHexadecimal obj;
    EXPECT_EQ(obj.toHex(16), "10");
}