#include <gtest/gtest.h>
#include "../LeetCode_GraphProblems.hpp"
#include <vector>
TEST(Lc, GRAPHPROBLEMS) {
    LC::_0802_FindEventualSafeStates obj;
    std::vector<std::vector<int>> graph{{1,2},{2,3},{5},{0},{5},{},{}};
    std::vector<int> groundTruth {2,4,5,6};
    EXPECT_EQ(groundTruth, obj.eventualSafeNodes(graph));
}