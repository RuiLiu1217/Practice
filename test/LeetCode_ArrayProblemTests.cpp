#include <gtest/gtest.h>
#include "../LeetCode_ArrayProblems.hpp"
#include <vector>
TEST(LC, _0001_TwoSum) {
    LC::_0001_TwoSum obj;
    std::vector<int> src {2, 7, 11, 15};
    std::vector<int> groundTruth{0, 1};
    EXPECT_EQ(obj.twoSum(src, 9), groundTruth);
}

TEST(LC, LC__0004__Test) {
    LC::_0004_MedianOfTwoSortedArrays obj;
    std::vector<int> nums1{1, 3};
    std::vector<int> nums2{2};
    EXPECT_EQ(obj.findMedianOfSortedArrays(nums1, nums2), 2.0);

    nums1 = {1, 2};
    nums2 = {3, 4};
    EXPECT_EQ(obj.findMedianOfSortedArrays(nums1, nums2), 3.5);
}

TEST(LC, _0015_3sum) {
    LC::_0015_3Sum obj;
    std::vector<int> input{-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> res = obj.threeSum(input);
    std::vector<int> groundTruth1{-1, 0, 1};
    std::vector<int> groundTruth2{-1, -1, 2};
    EXPECT_EQ(res[0], groundTruth2);
    EXPECT_EQ(res[1], groundTruth1);   
}

TEST(LC, _0020_ValidParentheses) {
    LC::_0020_ValidParentheses obj;
    std::string a = "[](){}";
    EXPECT_TRUE(obj.isValid(a));
    a = "[){{}";
    EXPECT_FALSE(obj.isValid(a));
    a = "[(){}[]{()()(((())))}]";
    EXPECT_TRUE(obj.isValid(a));
    a = "";
    EXPECT_TRUE(obj.isValid(a));
    
}

TEST(LC, _0026_RemoveDuplicatesFromSortedArray) {
    LC::_0026_RemoveDuplicatesFromSortedArray obj;
    std::vector<int> org{0,0,1,1,1,2,2,3,3,4};
    EXPECT_EQ(obj.removeDuplicates(org), 5);
}

TEST(LC, _0027_RemoveElement) {
    LC::_0027_RemoveElement obj;
    std::vector<int> t1{3,2,2,3};
    EXPECT_EQ(obj.removeElement(t1, 2), 2);
    std::vector<int> t2{0,1,2,2,3,0,4,2};
    EXPECT_EQ(obj.removeElement(t2, 2), 5);
}

TEST(LC, _0031_NextPermutation) {
    LC::_0031_NextPermutation obj;
    std::vector<int> a{1,2,3,4};
    obj.nextPermutation(a);
    std::vector<int> ta{1,2,4,3};
    EXPECT_EQ(a, ta);

}

TEST(LC, _0056_MergeIntervals) {
    LC::_0056_MergeIntervals obj;
    std::vector<std::vector<int>> input{{1,3},{2,6}, {8,10},{15,18}};
    std::vector<std::vector<int>> output = obj.merge(input);
    std::vector<std::vector<int>> res{{1,6},{8,10},{15,18}};
    EXPECT_EQ(output, res);
    std::vector<std::vector<int>> input2{{1,4},{4,5}};
    std::vector<std::vector<int>> output2 = obj.merge(input2);
    std::vector<std::vector<int>> res2{{1,5}};
    EXPECT_EQ(output2, res2);
}

TEST(LC, _0059_SpiralMatrixII) {
    LC::_0059_SpiralMatrixII obj;
    std::vector<std::vector<int>> res = obj.generateMatrix(4);
    std::vector<std::vector<int>> groundTruth{
    {1,2,3,4}, {12 ,13 ,14 ,5}, { 11, 16, 15,6}, {10,9,8,7}};
    EXPECT_EQ(res, groundTruth);
}

TEST(LC, _0033_SearchInRotatedSortedArray) {
    LC::_0033_SearchInRotatedSortedArray obj;

    std::vector<int> nums{4,5,6,7,0,1,2};
    int target = 0;
    EXPECT_EQ(obj.search(nums, target), 4);

    std::vector<int> nums2{4,5,6,7,0,1,2};
    int target2 = 3;
    EXPECT_EQ(obj.search(nums2, target2), -1);
}

TEST(LC, _0035_SearchInsertPosition) {
    LC::_0035_SearchInsertPosition obj;
    std::vector<int> test1{1,3,5,6};
    EXPECT_EQ(obj.searchInsert(test1, 5), 2);
    std::vector<int> test2{1,3,5,6};
    EXPECT_EQ(obj.searchInsert(test1, 2), 1);
    std::vector<int> test3{1,3,5,6};
    EXPECT_EQ(obj.searchInsert(test3, 7), 4);
    std::vector<int> test4{1,3,5,6};
    EXPECT_EQ(obj.searchInsert(test4, 0), 0);
}

TEST(LC, _0036_ValidSudoku) { // WILL NOT TEST THIS
    EXPECT_EQ(1,1);
}

TEST(LC, _0048_RotateImage) {
    LC::_0048_RotateImage obj;
    std::vector<std::vector<int>> t1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    obj.rotate(t1);
    std::vector<std::vector<int>> t3 = {
        {7, 4, 1}, 
        {8, 5, 2},
        {9, 6, 3}};
    EXPECT_EQ(t1, t3);
}

TEST(LC, _0067_AddBinary) {
    LC::_0067_AddBinary obj;
    std::string a = "1101";
    std::string b = "11001";
    std::string res = obj.addBinary(a, b);
    std::string groundTruth = "100110";
    EXPECT_EQ(res, groundTruth);
}

TEST(LC, _0074_SearchA2DMatrix) {
    LC::_0074_SearchA2DMatrix obj;
    std::vector<std::vector<int>> t1{{1,   3,  5,  7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    EXPECT_TRUE(obj.searchMatrix(t1, 3));
    EXPECT_FALSE(obj.searchMatrix(t1, 13));
}

TEST(LC, _0075_SortColors) {
    LC::_0075_SortColors obj;
    std::vector<int> input{2,0,2,1,1,0};
    std::vector<int> ground{0,0,1,1,2,2};
    obj.sortColors(input);
    EXPECT_EQ(input, ground);
}