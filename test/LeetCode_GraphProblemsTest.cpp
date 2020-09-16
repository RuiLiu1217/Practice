#include <gtest/gtest.h>
#include "../LeetCode_GraphProblems.hpp"
#include <vector>

TEST(LC, GRAPHPROBLEMS) {
    LC::_0802_FindEventualSafeStates obj;
    std::vector<std::vector<int>> graph{{1,2},{2,3},{5},{0},{5},{},{}};
    std::vector<int> groundTruth {2,4,5,6};
    EXPECT_EQ(groundTruth, obj.eventualSafeNodes(graph));
}

TEST(LC, _1135_ConnectingCitiesWithMinimumCost) {
    LC::_1135_ConnectingCitiesWithMinimumCost obj;
    std::vector<std::vector<int>> connections{{1,2,5}, {1,3,6}, {2,3,1}};
    EXPECT_EQ(obj.minimumCost(3, connections), 6);
}