#include <gtest/gtest.h>
#include "../LeetCode_RecursiveProblems.hpp"

TEST(LC, _0050_PowXN) {
    LC::_0050_PowXN obj;
    EXPECT_EQ(obj.myPow(2.0, 2), 4.0);
    EXPECT_EQ(obj.myPow(2.0, -2), 1.0/4.0);
    EXPECT_EQ(obj.myPow(2.0, 0), 1.0);
}

TEST(LC, _0095_UniqueBinarySearchTreeII) { // Not to test this
    EXPECT_TRUE(true);
}

TEST(LC, _0096_UniqueBinarySearchTree) {
    LC::_0096_UniqueBinarySearchTree obj;
    EXPECT_EQ(obj.numTrees(3), 5);
}

TEST(LC, _0089_GrayCode) {
    LC::_0089_GrayCode obj;
    std::vector<int> res = obj.grayCode(2);
    std::vector<int> groundTruth{0, 1, 3, 2};
    EXPECT_EQ(res, groundTruth);
}