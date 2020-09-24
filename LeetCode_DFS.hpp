#ifndef LEETCODE_DFS_HPP
#define LEETCODE_DFS_HPP
#include "LeetCode_TreeProblems.hpp"
#include <unordered_map>
#include <unordered_set>
namespace LC {
/*
    Tag: DFS
    Todo
    Given a binary tree containing digits from 0-9 only, each root-to-leaf path 
    could represent a number. An example is the root-to-leaf path 1->2->3 which 
    represents the number 123. Find the total sum of all root-to-leaf numbers.
    Note: A leaf is a node with no children.

    Example:

    Input: [1,2,3]
        1
       / \
      2   3
    Output: 25
    Explanation:
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Therefore, sum = 12 + 13 = 25.
    Example 2:

    Input: [4,9,0,5,1]
        4
       / \
      9   0
     / \
    5   1
    Output: 1026
    Explanation:
    The root-to-leaf path 4->9->5 represents the number 495.
    The root-to-leaf path 4->9->1 represents the number 491.
    The root-to-leaf path 4->0 represents the number 40.
    Therefore, sum = 495 + 491 + 40 = 1026. */
class _0129_SumRootToLeafNumbers {
private:
    void DFS(TreeNode* root, int carryValue);
    int sum;
public:
    _0129_SumRootToLeafNumbers() : sum(0) {}
    int sumNumbers(TreeNode* root);
};


/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:

You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Example 1:

Input: 1
Output: []
Example 2:

Input: 37
Output:[]
Example 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Example 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/
class _0254_FactorCombinations {
public:
    // Copy from the solution
    std::vector<std::vector<int>> getFactors(int n);
private:
    void DFS(std::vector<std::vector<int>>& res, std::vector<int>& tmp, int n);
};


/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a 
pair of nodes), write a function to check whether these edges make up a valid tree.

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges 
are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
*/
class _0261_GraphValidTree {
public:
    bool validTree(int n, std::vector<std::vector<int>>& edges);
    bool DFS(std::vector<std::unordered_set<int>>& graph, std::vector<int>& visited, int source, int target);
    //! Try to rewrite it using Union-Find
};


/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to 
add binary operators (not unary) +, -, or * between the digits so they evaluate to the target 
value.

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"] 

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]

Input: num = "3456237490", target = 9191
Output: []
*/
class _0282_ExpressionAddOperators {
public:
    std::vector<std::string> addOperators(std::string num, int target);
private:
    void DFS(const std::string& num, const int target, int pos, std::string exp, long prev, long curr, std::vector<std::string>& ans);
};



}
#endif