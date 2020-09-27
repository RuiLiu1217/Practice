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
    std::vector<std::vector<int>> t1 {
        {1, 3, 5, 7}, 
        {10, 11, 16, 20}, 
        {23, 30, 34, 50}
    };
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

TEST(LC, _0088_MergeSortedArray) {
    LC::_0088_MergeSortedArray obj;
    std::vector<int> nums1{1,2,3,0,0,0};
    int m = 3;
    std::vector<int> nums2{2,5,6};
    int n = 3;
    obj.merge(nums1, 3, nums2, 3);
    std::vector<int> res{1,2,2,3,5,6};
    EXPECT_EQ(res, nums1);
}

TEST(LC, _0118_PascalTriangle) {
    LC::_0118_PascalTriangle obj;
    std::vector<std::vector<int>> res = obj.generate(3);
    std::vector<std::vector<int>> grd{{1}, {1,1}, {1,2,1}};
    EXPECT_EQ(res, grd);
}

TEST(LC, _0119_) {
    LC::_0119_Pascal_meta<6> obj;
    std::vector<int> res = obj.get();
    std::vector<int> grd{1,5,10,10,5,1};
    EXPECT_EQ(res, grd);
}

TEST(LC, _0120_Triangle_meta) {
    LC::_0120_Triangle_meta<3> obj;
    std::vector<std::vector<int>> input{{2}, {3, 4}, {6,5,7}, {4,1,8,3}};
    auto tmp = obj.get(input);
    EXPECT_EQ(*std::min_element(begin(tmp), end(tmp)), 11);
}

TEST(LC, _0238_ProductOfArrayExceptSelf) {
    LC::_0238_ProductOfArrayExceptSelf obj;
    std::vector<int> t{1,2,3,4};
    std::vector<int> base{24,12,8,6};
    EXPECT_EQ(obj.productExceptSelf(t), base);
}

TEST(LC, _0243_ShortestWordDistance) {
    LC::_0243_ShortestWordDistance obj;
    std::vector<std::string> input{"practice", "makes", "perfect", "coding", "makes"};
    EXPECT_EQ(obj.shortestDistance(input, "coding", "practice"), 3);
}

TEST(LC, _0406_QueueReconstructionByHeight) {
    LC::_0406_QueueReconstructionByHeight obj;
    std::vector<std::pair<int,int>> input{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    std::vector<std::pair<int,int>> res = obj.reconstructQueue(input);
    std::vector<std::pair<int,int>> base{{5,0}, {7,0}, {5,2}, {6,1}, {4,4}, {7,1}};
    EXPECT_EQ(res, base);
}

TEST(LC, _0533_LonelyPixelII) {
    LC::_0533_LonelyPixelII obj;
    std::vector<std::vector<char>> input1 {
        {'W','B','W','B','B','B'},
        {'W','B','W','B','B','B'},
        {'W','B','W','B','B','B'},
        {'W','W','B','W','B','W'},
        {'W','B','W','B','B','B'}};

    EXPECT_EQ(obj.findBlackPixel(input1, 4), 12);
}

TEST(LC, _1582_SpecialPositionsInABinaryMatrix) {
    LC::_1582_SpecialPositionsInABinaryMatrix obj;
    std::vector<std::vector<int>> input1{
        {0,0,0,0,0}, {1,0,0,0,0}, {0,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,1}};
    std::vector<std::vector<int>> input2{
        {1,0,0},{0,0,1},{1,0,0}};
    EXPECT_EQ(obj.numSpecial(input1), 3);
    EXPECT_EQ(obj.numSpecial(input2), 1);
}


TEST(LC, _1144_DecreaseElementsToMakeArrayZigzag) {
    LC::_1144_DecreaseElementsToMakeArrayZigzag obj;
    std::vector<int> v1{1,2,3};
    std::vector<int> v2{9,6,1,6,2};
    EXPECT_EQ(obj.movesToMakeZigzag(v1), 2);
    EXPECT_EQ(obj.movesToMakeZigzag(v2), 4);
}

TEST(LC, _1283_FindTheSmallestDivisorGivenAThreshold) {
    LC::_1283_FindTheSmallestDivisorGivenAThreshold obj;
    std::vector<int> nums1{1,2,5,9};
    EXPECT_EQ(obj.smallestDivisor(nums1, 6), 5);

    std::vector<int> nums2{2,3,5,7,11};
    EXPECT_EQ(obj.smallestDivisor(nums2, 11), 3);

    std::vector<int> nums3{19};
    EXPECT_EQ(obj.smallestDivisor(nums3, 5), 4);
    
}

TEST(LC, _0283_MoveZeros) {
    LC::_0283_MoveZeros obj;
    std::vector<int> t{1,3,0,2,4,6,0,7,8,5,0};
    std::vector<int> b{1,3,2,4,6,7,8,5,0,0,0};
    obj.moveZeroes(t);
    EXPECT_EQ(t, b);
}

TEST(LC, _0289_GameOfLife) {
    LC::_0289_GameOfLife obj;
    std::vector<std::vector<int>> board{{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
    std::vector<std::vector<int>> base{{0,0,0}, {1,0,1}, {0,1,1}, {0,1,0}};
    obj.gameOfLife(board);
    EXPECT_EQ(board, base);
}

TEST(LC, _303_RangeSumQueryImmutable) {
    std::vector<int> num{-2, 0, 3, -5, 2, -1};
    LC::_0303_RangeSumQuery_Immutable obj(num);
    
    EXPECT_EQ(obj.sumRange(0,2), 1);
    EXPECT_EQ(obj.sumRange(2,5), -1);
    EXPECT_EQ(obj.sumRange(0,5), -3);
}

TEST(LC, _0304_RangeSumQuery2DImmutable) {
    std::vector<std::vector<int>> matrix{{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    LC::_0304_RangeSumQuery2D_Immutable obj(matrix);
    EXPECT_EQ(obj.sumRegion(2,1,4,3), 8);
    EXPECT_EQ(obj.sumRegion(1,1,2,2), 11);
    EXPECT_EQ(obj.sumRegion(1,2,2,4), 12);
}

TEST(LC, _0360_) {
    LC::_0360_SortTransformedArray obj;
    std::vector<int> in{-4, -2, 2, 4};
    std::vector<int> base{3,9,15,33};
    EXPECT_EQ(obj.sortTransformedArray(in, 1, 3, 5), base);
}

TEST(LC, _0361_) {
    LC::_0361_BombEnemy obj;
    std::vector<std::vector<char>> ch{{'0','E','0','0'},{'E','0','W','E'},{'0','E','0','0'}};
    EXPECT_EQ(3, obj.maxkilledEnemies(ch));
}
