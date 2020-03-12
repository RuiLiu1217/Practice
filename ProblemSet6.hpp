#ifndef PROBLEM_SET6_HPP
#define PROBLEM_SET6_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

namespace LeetCode {
/*
Given scores of N athletes, find their relative 
ranks and the people with the top three highest scores, 
who will be awarded medals: "Gold Medal", "Silver Medal" 
and "Bronze Medal".

Example 1:
    Input: [5, 4, 3, 2, 1]
    Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
    Explanation: The first three athletes got the top three 
    highest scores, so they got "Gold Medal", "Silver Medal" and 
    "Bronze Medal".
    For the left two athletes, you just need to output their relative 
    ranks according to their scores.
Note:
    N is a positive integer and won't exceed 10,000.
    All the scores of athletes are guaranteed to be unique.
*/
class _0506_RelativeRanks
{
public:
    std::vector<std::string> findRelativeRanks(std::vector<int> &nums);
};

/*
509. Fibonacci Number
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci 
sequence, such that each number is the sum of the two preceding ones, starting from 
0 and 1. That is,
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*/
class _0509_FibonacciNumber {
public:
    int fib(int N);
};


/*
You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that 
amount. You may assume that you have infinite number of each kind of coin.

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Input: amount = 10, coins = [10] 
Output: 1

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
*/
class _0518_CoinChange2 {
public:
    int change(int amount, std::vector<int>& coins);
};

class _0519_RandomFlipMatrix {
private:
    int M;
    int N;
    int len;
    std::vector<int> index;    
public:
    _0519_RandomFlipMatrix(int n_rows, int n_cols);
    std::vector<int> flip();
    void reset();

};

/*
Given an array w of positive integers, where w[i] describes the weight of 
index i, write a function pickIndex which randomly picks an index in 
proportion to its weight.

Note:
1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. 
Solution's constructor has one argument, the array w. pickIndex has no 
arguments. Arguments are always wrapped with a list, even if there aren't any.
*/
class _0528_RandomPickWithWeight {
private:
    std::vector<int> accumulated;
    std::vector<int> W;
    int maxV;
public:
    _0528_RandomPickWithWeight(std::vector<int>& w);
    int pickIndex();
};

/*
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as 
https://leetcode.com/problems/design-tinyurl and it returns a short URL 
such as http://tinyurl.com/4e9iAk.
Design the encode and decode methods for the TinyURL service. There is no 
restriction on how your encode/decode algorithm should work. You just need 
to ensure that a URL can be encoded to a tiny URL and the tiny URL can be 
decoded to the original URL.
*/
class _0535_EncodeAndDecodeTinyURL {
public:
    // Encodes a URL to a shortened URL
    std::string encode(std::string longUrl);

    // Decodes a shortened URL to its original URL
    std::string decode(std::string shortUrl);
};


/*
Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/
class _0537_ComplexNumberMultiplication {
public:
    std::string complexNumberMultiply(std::string a, std::string b);
};

/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that 
every key of the original BST is changed to the original key plus sum of 
all keys greater than the original key in BST.

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*/
class _0538_ConvertBSTToGreaterTree {
public:
    TreeNode<int>* convertBST(TreeNode<int>* root);
    void inOrder(TreeNode<int>* root);
};

/*
You are given a sorted array consisting of only integers where every 
element appears exactly twice, except for one element which appears 
exactly once. Find this single element that appears only once.

Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Input: [3,3,7,7,10,11,11]
Output: 10
*/
class _0540_SingleElementInASortedArray {
public:
    int singleNonDuplicate(std::vector<int>& nums);
private:
    int singleNoDuplicate(std::vector<int>& nums, int bet, int end);
};

/*
Given a string and an integer k, you need to reverse the first k 
characters for every 2k characters counting from the start of the string. 
If there are less than k characters left, reverse all of them. If there 
are less than 2k but greater than or equal to k characters, then reverse 
the first k characters and left the other as original.

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/
class _0541_ReverseStringII {
public:
    std::string reverseStr(std::string s, int k);
};

/*
Tag: Tree
!!! Edge case and initial condtion is very easy to have errors !!!
Facebook 

Given a binary tree, you need to compute the length of the diameter 
of the tree. The diameter of a binary tree is the length of the 
longest path between any two nodes in a tree. This path may or may 
not pass through the root.

Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
Note: The length of path between two nodes is represented by the number 
of edges between them.
*/
class _0543_DiameterofBinaryTree {
private:
    int res;
    int depth(TreeNode<int>* root);
public:
    int diameterOfBinaryTree(TreeNode<int>* root);

};

/*
553. Optimal Division
Given a list of positive integers, the adjacent integers will 
perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position 
to change the priority of operations. You should find out how 
to add parenthesis to get the maximum result, and return the 
corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
since they don't influence the operation priority. So you should return "1000/(100/10/2)". 

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
Note:

The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.
*/
class _0553_OptimalDivision {
public:
    std::string optimalDivision(std::vector<int>& nums);
};

/*
There is a brick wall in front of you. The wall is rectangular and has 
several rows of bricks. The bricks have the same height but different 
width. You want to draw a vertical line from the top to the bottom and 
cross the least bricks.
The brick wall is represented by a list of rows. Each row is a list of 
integers representing the width of each brick in this row from left to right.
If your line go through the edge of a brick, then the brick is not 
considered as crossed. You need to find out how to draw the line to cross 
the least bricks and return the number of crossed bricks.
You cannot draw a line just along one of the two vertical edges of the 
wall, in which case the line will obviously cross no bricks.

Input: [[1,2,2,1],
        [3,1,2],
        [1,3,2],
        [2,4],
        [3,1,2],
        [1,3,1,1]]
Output: 2

Note:
The width sum of bricks in different rows are the same and won't exceed 
INT_MAX. The number of bricks in each row is in range [1,10,000]. The height 
of wall is in range [1,10,000]. Total number of bricks of the wall won't 
exceed 20,000.
*/
class _0554_BrickWall {
public:
    int leastBricks(std::vector<std::vector<int>>& wall);
};


/*
Given a string, you need to reverse the order of characters in each word 
within a sentence while still preserving whitespace and initial word order.

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will 
not be any extra space in the string.
*/
class _0557_ReverseWordsInAStringIII {
public:
    std::string reverseWords(std::string s);
};

/*
Given a n-ary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root 
node down to the farthest leaf node.
Nary-Tree input serialization is represented in their level order traversal, 
each group of children is separated by the null value (See examples).

Input: root = [1,null,3,2,4,null,5,6]
Output: 3

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5

Constraints:

The depth of the n-ary tree is less than or equal to 1000.
The total number of nodes is between [0, 10^4].
*/
class _0559_MaximumDepthOfNaryTree {
public:
    int maxDepth(NaryTreeNode<int>* root);
};

/*
Tag:

Facebook

560. Subarray Sum Equals K
Given an array of integers and an integer k, you need to find 
the total number of continuous subarrays whose sum equals to k.
Input:nums = [1,1,1], k = 2
Output: 2
Note:
    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the 
    range of the integer k is [-1e7, 1e7].
 */
class _0560_SubarraySumEqualsK {
    public:
    int subarraySum(std::vector<int>& nums, int k);
};


/*
Given an array of 2n integers, your task is to group these integers 
into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which 
makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Input: [1,4,3,2]
Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
*/
class _0561_ArrayPartitionI {
public:
    int arrayPairSum(std::vector<int>& nums);
};

/*
Given two strings s1 and s2, write a function to return true if s2 
contains the permutation of s1. In other words, one of the first 
string's permutations is the substring of the second string.

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Input:s1= "ab" s2 = "eidboaoo"
Output: False

Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/
class _0567_PermutationInString {
public:
    bool checkInclusion(std::string s1, std::string s2);
};

/*
Given two non-empty binary trees s and t, check whether tree t has exactly 
the same structure and node values with a subtree of s. A subtree of s is 
a tree consists of a node in s and all of this node's descendants. The tree 
s could also be considered as a subtree of itself.
Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree 
of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
*/
class _0572_SubtreeOfAnotherTree {
public:
    bool isSubtree(TreeNode<int>* s, TreeNode<int>* t);
private:
    bool isSame(TreeNode<int>* s, TreeNode<int>* t);
};

/*
Given two words word1 and word2, find the minimum number of steps 
required to make word1 and word2 the same, where in each step you 
can delete one character in either string.

Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/
class _0583_DeleteOperationForTwoStrings {
private:
    std::vector<std::vector<int>> DP;
    int minDistance_DP_nonLCS_based(std::string word1, std::string word2);
    int minDistance_LCS_DP_based(std::string word1, std::string word2);
    int minDistance_LCS_based(std::string word1, std::string word2);
    int lcs(std::string& s1, std::string& s2, int m, int n);
public:
    int minDistance(std::string word1, std::string word2);
};

/*
Given an n-ary tree, return the preorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order 
traversal, each group of children is separated by the null value 
(See examples). 

Follow up:
Recursive solution is trivial, could you do it iteratively?

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 10^4]
*/
class _0589_NaryTreePreorderTraversal {
public:
    std::vector<int> preorder(NaryTreeNode<int>* root);
};

/*
Given an n-ary tree, return the postorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, 
each group of children is separated by the null value (See examples).

Recursive solution is trivial, could you do it iteratively?
Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
*/
class _0590_Node;
class _0590_NaryTreePostOrderTraversal {
public:
    std::vector<int> postorder(_0590_Node* root);
};

/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.
The coordinate (x,y) of a point is represented by an integer array with two integers.

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True

Note:
All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/
class _0593_ValidSquare {
public:
    bool validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3,
    std::vector<int>& p4);
};

/*
Given an m * n matrix M initialized with all 0's and several update operations.
Operations are represented by a 2D array, and each operation is represented by 
an array with two positive integers a and b, which means M[i][j] should be added 
by one for all 0 <= i < a and 0 <= j < b.

You need to count and return the number of maximum integers in the matrix after performing all the operations.

Example 1:
Input: 
m = 3, n = 3
operations = [[2,2],[3,3]]
Output: 4
Explanation: 
Initially, M = 
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]

After performing [2,2], M = 
[[1, 1, 0],
 [1, 1, 0],
 [0, 0, 0]]

After performing [3,3], M = 
[[2, 2, 1],
 [2, 2, 1],
 [1, 1, 1]]

So the maximum integer in M is 2, and there are four of it in M. So return 4.
Note:
The range of m and n is [1,40000].
The range of a is [1,m], and the range of b is [1,n].
The range of operations size won't exceed 10,000.
*/
class _0598_RangeAdditionII {
public:
    int maxCount(int m, int n, std::vector<std::vector<int>>& ops);
};

/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a 
list of favorite restaurants represented by strings.
You need to help them find out their common interest with the least list index sum. 
If there is a choice tie between answers, output all of them with no order requirement. 
You could assume there always exists an answer.

Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".

Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/
class _0599_MinimumIndexSumOfTwoLists {
public:
    std::vector<std::string> findRestaruant(std::vector<std::string>& list1, std::vector<std::string>& list2);
};

}

#endif