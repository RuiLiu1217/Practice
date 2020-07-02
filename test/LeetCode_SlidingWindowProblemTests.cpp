#include <gtest/gtest.h>
#include "../LeetCode_SlidingWindowProblems.hpp"

TEST(LC, _0003_LongestSubstringWithoutRepeatingCharacters) {
    LC::_0003_LongestSubstringWithoutRepeatingCharacters obj;
    EXPECT_EQ(obj.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(obj.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(obj.lengthOfLongestSubstring("pwwkew"), 3);
}