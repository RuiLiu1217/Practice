#include <gtest/gtest.h>
#include "../LeetCode_DynamicProgrammingProblems.hpp"

TEST(LC, _0010_RegularExpressionMatching) {
    // EXPECT_EQ(1,2);
}

TEST(LC, _0062_UniquePaths) {
    LC::_0062_UniquePaths obj;
    EXPECT_EQ(obj.uniquePaths(3, 2), 3);
    EXPECT_EQ(obj.uniquePaths(7, 3), 28);
}

TEST(LC, _0063_UniquePathsII) {
    std::vector<std::vector<int>> input{{0,0,0},{0,1,0},{0,0,0}};

    LC::_0063_UniquePathsII obj;
    EXPECT_EQ(obj.uniquePathsWithObstacles(input), 2);
}

TEST(LC, _0064_MinimumPathSum) {
    LC::_0064_MinimumPathSum obj;
    std::vector<std::vector<int>> res {{1,3,1}, {1,5,1}, {4,2,1}};
    EXPECT_EQ(obj.minPathSum(res), 7);
}

TEST(LC, _0070_ClimbingStairs) {
    LC::_0070_ClimbingStairs obj;
    EXPECT_EQ(obj.climbStairs(2), 2);
    EXPECT_EQ(obj.climbStairs(3), 3);
}

TEST(LC, _0097_InterleavingString) {
    LC::_0097_InterleavingString obj;
    EXPECT_TRUE(obj.isInterleav("aabcc", "dbbca", "aadbbcbcac"));
    EXPECT_FALSE(obj.isInterleav("aabcc", "dbbca", "aadbbbaccc"));
}
