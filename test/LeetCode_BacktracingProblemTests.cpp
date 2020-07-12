#include <gtest/gtest.h>
#include <iostream>
#include "../LeetCode_BacktracingProblems.hpp"

TEST(LC, LC__0017__Test) {
    LC::_0017_LetterCombinationsOfAPhoneNumber obj;
    std::string digits = "2";
    std::vector<std::string> res = obj.letterCombinations(digits);
    std::vector<std::string> grd{"a", "b", "c"};
    EXPECT_EQ(res, grd);
}

TEST(LC, _0022_GenerateParentheses) {
    LC::_0022_GenerateParentheses obj;
    std::vector<std::string> res = obj.generateParenthesis(3);
    EXPECT_EQ(res.size(), 5);
}

TEST(LC, _0037_SudokuSolver) {
    LC::_0037_SudokuSolver obj;
    std::vector<std::vector<char>> board {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    obj.solveSudoku(board);
}

TEST(LC, _0039_CombinationSum) {
    LC::_0039_CombinationSum obj;
    std::vector<int> test{2,3,6,7};
    std::vector<std::vector<int>> res = obj.combinationSum(test, 7);
    std::vector<std::vector<int>> groundTruth {{2,2,3}, {7}};
    EXPECT_EQ(groundTruth, res);
}

TEST(LC, _0046_Permutations) {
    LC::_0046_Permutations obj;

    std::vector<int> input{1,2};
    std::vector<std::vector<int>> res = obj.permute(input);
    std::vector<std::vector<int>> groundTruth = {{1,2}, {2,1}};
    EXPECT_EQ(res, groundTruth);
}

TEST(LC, _0052_NQueensII) {
    LC::_0052_NQueensII obj;
    EXPECT_EQ(obj.totalNQueens(4), 2);
    EXPECT_EQ(obj.totalNQueens(8), 92);
}

TEST(LC, _0077_Combinations) {
    LC::_0077_Combinations obj;
    std::vector<std::vector<int>> res = obj.combine(4, 2);
    std::vector<std::vector<int>> groundTruth{{1, 2},{1, 3},{1, 4},{2, 3},{2, 4},{3, 4}};
    EXPECT_EQ(res, groundTruth);
}

TEST(LC, _0078_Subsets) {
    LC::_0078_Subsets obj;
    std::vector<int> input {1,2,3};
    std::vector<std::vector<int>> groundTruth{{},{1},{2},{2,1},{3},{3,1},{3,2},{3,2,1}};
    EXPECT_EQ(obj.subsets(input), groundTruth);
}

TEST(LC, _0079_WordSearch) {
    LC::_0079_WordSearch obj;
    std::vector<std::vector<char>> input{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    EXPECT_TRUE(obj.exist(input, "ABCCED"));
}

TEST(LC, _0090_SubsetII) {
    LC::_0090_SubsetII obj;
    std::vector<int> nums{1,2,2};    
    std::vector<std::vector<int>> res = obj.subsetsWithDup(nums);
    std::vector<std::vector<int>> ground{{},{1},{1,2},{1,2,2},{2},{2,2}};
    
    EXPECT_EQ(ground, res);
}