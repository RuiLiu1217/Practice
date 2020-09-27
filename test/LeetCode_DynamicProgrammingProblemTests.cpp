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

TEST(LC, _0312_BurstBalloons) {
    LC::_0312_BurstBalloons obj;
    std::vector<int> t{{3,1,5,8}};
    EXPECT_EQ(obj.maxCoins(t), 167);
}

TEST(LC, _0139_wordBreak) {
    LC::_0139_WordBreak obj;
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};

    EXPECT_TRUE(obj.wordBreak(s,wordDict));

    std::string s1 = "applepenapple";
    std::vector<std::string> wordDict1 = {"apple", "pen"};
    EXPECT_TRUE(obj.wordBreak(s1, wordDict1));

    std::string s2 = "catsandog";
    std::vector<std::string> wordDict2 = {"cats", "dog", "sand", "and", "cat"};
    EXPECT_FALSE(obj.wordBreak(s2, wordDict2));
}

TEST(LC, _0264_nthUglyNumber) {
    LC::_0264_UglyNumberII obj;
    EXPECT_EQ(obj.nthUglyNumber(10), 12);
}

TEST(LC, _0322_CoinChange) {
    LC::_0322_CoinChange obj;
    std::vector<int> coins1{1, 2, 5};
    std::vector<int> coins2{2};
    EXPECT_EQ(3, obj.coinChangeDP(coins1, 11));
    EXPECT_EQ(-1, obj.coinChangeDP(coins2, 3));
}

TEST(LC, _0343_IntegerBreak) {
    LC::_0343_IntegerBreak obj;
    EXPECT_EQ(obj.intergerBreak(10), 36);
}

TEST(LC, _0472_ConcatenatedWords) {
    LC::_0472_ConcatenatedWords obj;
    std::vector<std::string> words{"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    std::vector<std::string> res{obj.findAllConcatenatedWordsInADict(words)};
    std::vector<std::string> base{"catsdogcats","dogcatsdog","ratcatdogcat"};
    EXPECT_EQ(res, base);
}

TEST(LC, _1494_ParallelCoursesII) {
    LC::_1494_ParallelCoursesII obj;
    std::vector<std::vector<int>> dep1{{2,1},{3,1},{1,4}};
    EXPECT_EQ(obj.minNumberOfSemesters(4, dep1, 2), 3);
    std::vector<std::vector<int>> dep2{{2,1},{3,1},{4,1},{1,5}};
    EXPECT_EQ(obj.minNumberOfSemesters(5, dep2, 2), 4);
}

TEST(LC, _0375_GuessNumberHigherOrLowerII) {
    LC::_0375_GuessNumberHigherOrLowerII obj;
    EXPECT_EQ(obj.getMoneyAmount(2), 1);
    EXPECT_EQ(obj.getMoneyAmount(1), 0);
}
