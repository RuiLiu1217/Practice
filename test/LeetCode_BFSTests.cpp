#include <gtest/gtest.h>
#include "../LeetCode_BFS.hpp"
#include <vector>
TEST(LC, _0403_FrogJump) {
    LC::_0403_FrogJump obj;
    std::vector<int> t1{0,1,2,3,4,8,9,11};
    EXPECT_FALSE(obj.canCross(t1));
}

TEST(LC, _0286_WallsAndGates) {
    LC::_0286_WallsAndGates obj;
    std::vector<std::vector<int>> rooms {{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
    std::vector<std::vector<int>> base {{3,-1,0,1},{2,2,1,-1},{1,-1,2,-1},{0,-1,3,4}};
    obj.wallsAndGates(rooms);
    EXPECT_EQ(rooms, base);
}