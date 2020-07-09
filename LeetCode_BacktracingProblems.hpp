#ifndef LEETCODE_BACKTRACINGPROBLEMS_HPP
#define LEETCODE_BACKTRACINGPROBLEMS_HPP
#include <vector>
#include <string>

namespace LC {
    /*
        Tag: backtracing
    Given a string containing digits from 2-9 inclusive, return all possible 
    letter combinations that the number could represent.
    A mapping of digit to letters (just like on the telephone buttons) is 
    given below. Note that 1 does not map to any letters.

    Example:
    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    Note:
    Although the above answer is in lexicographical order, your answer could 
    be in any order you want.
    */
class _0017_LetterCombinationsOfAPhoneNumber {
public:
    std::vector<std::string> letterCombinations(std::string &digits);
private:
    void letterCombination(const std::string &digits, int i, int N, std::string tmp, std::vector<std::string> &res);
};


/*
Tag: recursive, parenthesis, permutation, combination
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class _0022_GenerateParentheses {
public:
    std::vector<std::string> generateParenthesis(int n);
};


/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.
*/
class _0037_SudokuSolver {
public:
    // Backtracing problem, but the issue is how to make the backtracing fast !!!!
    void solveSudoku(std::vector<std::vector<char>>& board);
};


/*  
Tag: backtracking
Given a set of candidate numbers (candidates without duplicates) 
and a target number (target), find all unique combinations in 
candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.
Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
Example 1:
    Input: candidates = [2,3,6,7], target = 7,
A solution set is:
    [  [7],  [2,2,3] ]
Example 2:
    Input: candidates = [2,3,5], target = 8, 
A solution set is:
    [  [2,2,2,2],  [2,3,3],  [3,5] ]
*/
class _0039_CombinationSum {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target);
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<int> &tmp, std::vector<std::vector<int>> &res);
};

/*
Given a collection of [distinct] integers, return all 
possible permutations
Example:
Input: [1,2,3]
Output:[[1,2,3], [1,3,2], [2,1,3], 
        [2,3,1], [3,1,2], [3,2,1]]
*/
class _0046_Permutations {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums);
private:
    void permuteRecursive(std::vector<int> &nums, int begin, std::vector<std::vector<int>> &result);
};


/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no 
two queens attack each other. Given an integer n, return all distinct solutions to the 
n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' 
placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/
class _0051_NQueens {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n);
    void solve(std::vector<std::string>& tmp, int curN, int n, std::vector<std::vector<std::string>>& res);
    std::vector<int> availableQ(std::vector<std::string> tmp, int curN, int n);
};


/*
Tag: backtracking
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no 
two queens attack each other. Given an integer n, return all distinct solutions to the 
n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' 
placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/
class _0052_NQueensII {
public:
    int totalNQueens(int n);
private:
    void totalNQueens(std::vector<std::vector<int>>& board, int nIdx, const int totalRows, int& totalSolution);
    void updateBoard(std::vector<std::vector<int>>& board, int i, int j);
    void dedateBoard(std::vector<std::vector<int>>& board, int i, int j);
};



}


#endif