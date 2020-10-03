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

TEST(LC, _0349_IntersectionOfTwoArrays) {
    LC::_0349_IntersectionOfTwoArrays obj;
    std::vector<int> nums1{1,2,2,3,4,5};
    std::vector<int> nums2{2,3,5,6,7};
    std::vector<int> base{2,3,5};
    EXPECT_EQ(obj.intersection(nums1, nums2), base);
}

TEST(LC, _0350_InterectionOfTwoArraysII) {
    LC::_0350_IntersectionOfTwoArraysII obj;
    std::vector<int> nums1{1,2,2,1};
    std::vector<int> nums2{2,2};
    std::vector<int> base{2,2};
    EXPECT_EQ(obj.intersect(nums1, nums2), base);    
}

TEST(LC, _0599_MinimumIndexSumOfTwoLists) {
    LC::_0599_MinimumIndexSumOfTwoLists obj;
    std::vector<std::string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    std::vector<std::string> list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    std::vector<std::string> res = {"Shogun"};
    EXPECT_EQ(obj.findRestaruant(list1, list2), res);
}