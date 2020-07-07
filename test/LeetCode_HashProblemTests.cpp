#include <gtest/gtest.h>
#include "../LeetCode_HashProblems.hpp"

TEST(LC, _0049_GroupAnagrams) {
    LC::_0049_GroupAnagrams obj;
    std::vector<std::string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> gold{ { "eat", "tea", "ate" }, { "tan", "nat" }, { "bat" } };
    EXPECT_EQ(obj.groupAnagrams(input), gold);
}