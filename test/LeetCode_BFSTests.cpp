#include <gtest/gtest.h>
#include "../LeetCode_BFS.hpp"
#include <vector>
TEST(LC, _0403_FrogJump) {
    LC::_0403_FrogJump obj;
    std::vector<int> t1{0,1,2,3,4,8,9,11};
    EXPECT_FALSE(obj.canCross(t1));
}