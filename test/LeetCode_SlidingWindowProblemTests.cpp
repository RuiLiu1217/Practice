#include <gtest/gtest.h>
#include "../LeetCode_SlidingWindowProblems.hpp"

TEST(LC, _0003_LongestSubstringWithoutRepeatingCharacters) {
    LC::_0003_LongestSubstringWithoutRepeatingCharacters obj;
    EXPECT_EQ(obj.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(obj.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(obj.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(LC, _0239_SlidingWindowMaximum_2) {
    LC::_0239_SlidingWindowMaximum obj;
    std::vector<int> v{1,3,-1,-3,5,3,6,7};
    std::vector<int> m{3,3,5,5,6,7};
    EXPECT_EQ(obj.maxSlidingWindow(v, 3), m);
}

TEST(LC, _0480_SlidingWindowMedian) {
    LC::_0480_SlidingWindowMedian obj;
    std::vector<int> v{1,3,-1,-3,5,3,6,7};
    int k = 3;
    std::vector<double> base{1.0,-1.0,-1.0,3.0,5,6};
    EXPECT_EQ(obj.medianSlidingWindow(v,k), base);
}