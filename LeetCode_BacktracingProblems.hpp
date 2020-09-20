#ifndef LEETCODE_BACKTRACINGPROBLEMS_HPP
#define LEETCODE_BACKTRACINGPROBLEMS_HPP
#include <vector>
#include <string>
#include <unordered_set>
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



/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
Example:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class _0077_Combinations {
private:
    int N;
    int K;
public:
    std::vector<std::vector<int>> combine(int n, int k);
};


/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class _0078_Subsets{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums);
    std::vector<std::vector<int>> subsets(std::vector<int>& nums, int beg, int end);
};



/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent 
cell, where "adjacent" cells are those horizontally or vertically 
neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
class _0079_WordSearch {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word);
    void exist(std::vector<std::vector<char>>& board, int i, int j, std::string& word, int start, int end, bool& res);
};



/*
Tag: combination
Given a collection of integers that might contain duplicates, nums, return all possible subsets 
(the power set).
Note: The solution set must not contain duplicate subsets.
Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class _0090_SubsetII {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums);
    void subset(std::vector<std::vector<int>>& res, std::vector<int>& tmp,
            std::vector<int>& nums, int pos);
    
};


/*
Surrounded Regions
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board 
are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the 
border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected 
horizontally or vertically.
*/
class _0130_SurroundedRegions {
public:
    void solve(std::vector<std::vector<char>>& board);
    
    void DFS(std::vector<std::vector<char>>& board, int i, int j, 
             const int M, const int N, 
             const char orig, const char newc);
};




/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of 
islands. An island is surrounded by water and is formed by connecting 
adjacent lands horizontally or vertically. You may assume all four edges 
of the grid are all surrounded by water.

Input:
11110
11010
11000
00000

Output: 1

Input:
11000
11000
00100
00011

Output: 3
*/
class _0200_NumberOfIslands {
public:
    int numIslands(std::vector<std::vector<char>>& grid);
    void eraseIsland(std::vector<std::vector<char>>& grid, int i, int j);
};


/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" 
cells are those horizontally or vertically neighboring. The same letter cell may not 
be used more than once in a word.

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Note:
All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/
class _0212_WordSearchII {
private:
    std::unordered_set<std::string> res;
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words);
    void findWords(std::vector<std::vector<char>>& board, int i, int j, const std::string& word, int idx);
};



/*
Find all possible combinations of k numbers that add up to a number n, given that 
only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.

Input: k = 3, n = 7
Output: [[1,2,4]]

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
class _0216_CombinationSumIII{
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n);
private:
    void DFS(int k, int n, int curV, std::vector<int>& tmp, std::vector<std::vector<int>>& res);
};


/*
Given a string s, return all the palindromic permutations (without duplicates) of it. 
Return an empty list if no palindromic permutation could be form.

Input: "aabb"
Output: ["abba", "baab"]

Input: "abc"
Output: []
*/
class _0267_PalindromePermutationII {
public:
    std::vector<std::string> generatePalindromes(std::string s);
private:
    void backtracking(std::string hs, int level, std::vector<int>& visited, std::string& tmp, std::vector<std::string>& res);
    void backtracking2(std::string hs, int start, int end, std::vector<std::string>& res );
};

}


#endif