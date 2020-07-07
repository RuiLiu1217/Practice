#include <gtest/gtest.h>
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

TEST(LC, _0052_NQueensII) {
    LC::_0052_NQueensII obj;
    EXPECT_EQ(obj.totalNQueens(4), 2);
    EXPECT_EQ(obj.totalNQueens(8), 92);
}