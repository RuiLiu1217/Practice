#include <gtest/gtest.h>
#include "../LeetCode_HashProblems.hpp"

TEST(LC, _0049_GroupAnagrams) {
    LC::_0049_GroupAnagrams obj;
    std::vector<std::string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> gold{ { "eat", "tea", "ate" }, { "tan", "nat" }, { "bat" } };
    EXPECT_EQ(obj.groupAnagrams(input), gold);
}

TEST(LC, _0710_RandomPickWithBlacklist) {
    // Just not to test it. 
    EXPECT_EQ(1,1);
}

TEST(LC, _1371_FindTheLongestSubstringContainingVowelsInEvenCounts) {
    LC::_1371_FindTheLongestSubstringContainingVowelsInEvenCounts obj;
    std::string s1 = "eleetminicoworoep";
    std::string s2 = "leetcodeisgreat";
    EXPECT_EQ(obj.findTheLongestSubstring(s1), 13);
    EXPECT_EQ(obj.findTheLongestSubstring(s2), 5);

}