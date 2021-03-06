#ifndef PROBLEM_SET10_HPP
#define PROBLEM_SET10_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"
namespace LeetCode {

/*
We are given that the string "abc" is valid.
From any valid string V, we may split V into two pieces X and Y such that X + Y 
(X concatenated with Y) is equal to V.  (X or Y may be empty.)  Then, X + "abc" + Y 
is also valid.
If for example S = "abc", then examples of valid strings are: "abc", "aabcbc", 
"abcabc", "abcabcababcc".  Examples of invalid strings are: "abccba", "ab", "cababc", 
"bac". Return true if and only if the given string S is valid.

Input: "aabcbc"
Output: true
Explanation: 
We start with the valid string "abc".
Then we can insert another "abc" between "a" and "bc", resulting in "a" + "abc" + "bc" which is "aabcbc".

Input: "abcabcababcc"
Output: true
Explanation: 
"abcabcabc" is valid after consecutive insertings of "abc".
Then we can insert "abc" before the last letter, resulting in "abcabcab" + "abc" + "c" which is "abcabcababcc".

Input: "abccba"
Output: false

Input: "cababc"
Output: false

Note:
1 <= S.length <= 20000
S[i] is 'a', 'b', or 'c'
*/
class _1003_CheckIfWordIsValidAfterSubstitutions {
public:
    bool isValid(std::string S);
};

/*
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest (contiguous) subarray that contains only 1s. 

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
 
Note:
1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1 
*/
class _1004_MaxConsecutiveOnesIII{
public:
    int longestOnes(std::vector<int>& A, int K);
};

/*
Tag: Binary Search
Google

A conveyor belt has packages that must be shipped from one port to another within D days.
The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the 
ship with packages on the conveyor belt (in the order given by weights). We may not load 
more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the 
conveyor belt being shipped within D days.

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: 
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and
splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed. 
Example 2:

Input: weights = [3,2,2,4,1,4], D = 3
Output: 6
Explanation: 
A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], D = 4
Output: 3
Explanation: 
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
*/
class _1011_CapacityToShipPackagesWithinDDays {
public:
    int shipWithinDays(std::vector<int>& weights, int D);
};

/*
Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, and two 
sightseeing spots i and j have distance j - i between them.
The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : the sum of the values of 
the sightseeing spots, minus the distance between them.
Return the maximum score of a pair of sightseeing spots.

Input: [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11


2 <= A.length <= 50000
1 <= A[i] <= 1000
*/
class _1014_BestSightseeingPair {
public:
    int maxScoreSightseeingPair(std::vector<int>& A);
};

/*
Given a number N, return a string consisting of "0"s and 
"1"s that represents its value in base -2 (negative two).
The returned string must have no leading zeroes, unless 
the string is "0".

Input: 2
Output: "110"
Explantion: (-2) ^ 2 + (-2) ^ 1 = 2

Input: 3
Output: "111"
Explantion: (-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3

Input: 4
Output: "100"
Explantion: (-2) ^ 2 = 4

Note:

0 <= N <= 10^9
*/
class _1017_ConvertToBase_Negative2 {
public:
    std::string baseNeg2(int N);
};


/*
Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to 
A[i] interpreted as a binary number (from most-significant-bit to least-significant-bit.)
Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

Input: [0,1,1]
Output: [true,false,false]
Explanation: 
The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10. 
Only the first number is divisible by 5, so answer[0] is true.

Input: [1,1,1]
Output: [false,false,false]

Input: [0,1,1,1,1,1]
Output: [true,false,false,false,true,false]

Input: [1,1,1,0,1]
Output: [false,false,false,false,false]

Note:

1 <= A.length <= 30000
A[i] is 0 or 1
*/
class _1018_BinaryPrefixDivisibleBy5 {
public:
    std::vector<bool> prefixesDivBy5(std::vector<int>& A);
};


/*
A valid parentheses string is either empty (""), "(" + A + ")", or 
A + B, where A and B are valid parentheses strings, and + 
represents string concatenation. For example, "", "()", "(())()", 
and "(()(()))" are all valid parentheses strings.
A valid parentheses string S is primitive if it is 
nonempty, and there does not exist a way to split it into 
S = A+B, with A and B nonempty valid parentheses strings.
Given a valid parentheses string S, consider its 
primitive decomposition: S = P_1 + P_2 + ... + P_k, 
where P_i are primitive valid parentheses strings.
Return S after removing the outermost parentheses of 
every primitive string in the primitive decomposition of S.

Input: "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition 
"(()())" + "(())".
After removing outer parentheses of each part, this is 
"()()" + "()" = "()()()".

Input: "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive 
decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is 
"()()" + "()" + "()(())" = "()()()()(())".

Input: "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

S.length <= 10000
S[i] is "(" or ")"
S is a valid parentheses string
*/
class _1021_RemoveOutermostParentheses {
public:
    std::string removeOuterParentheses(std::string S);
};

/*
A query word matches a given pattern if we can insert lowercase letters to 
the pattern word so that it equals the query. (We may insert each character 
at any position, and may insert 0 characters.)
Given a list of queries, and a pattern, return an answer list of booleans, 
where answer[i] is true if and only if queries[i] matches the pattern. 


Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: 
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".

Note:

1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
All strings consists only of lower and upper case English letters.
*/
class _1023_CamelcaseMatching {
public:
    std::vector<bool> camelMatch(std::vector<std::string>& queries, std::string pattern);
    bool canMatch_prefixMatchingBased(std::string query, std::string pattern);
    bool canMatch_regularExpressionBased(std::string query, std::string pattern);
private:
    std::vector<bool> prefixMatchingBased(std::vector<std::string>& queries, std::string pattern);
    std::vector<bool> regularExpressionBased(std::vector<std::string>& queries, std::string pattern);
};

/*
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number N on the chalkboard.  On each player's turn, 
that player makes a move consisting of:
Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.
Example 1:
Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

Example 2:
Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.

Note:
    1 <= N <= 1000
*/
class _1025_DivisorGame {
public:
    bool divisorGame(int N);
};

class _1027_LongestArithmeticSequence{
    public:
    // Copy from the solution.
    int longestArithSeqLength(std::vector<int>& A);
};

/*
We run a preorder depth first search on the root of a binary tree.
At each node in this traversal, we output D dashes 
(where D is the depth of this node), then we output the value of this node. 
(If the depth of a node is D, the depth of its immediate child is D+1. 
The depth of the root node is 0.)
If a node has only one child, that child is guaranteed to be the left child.
Given the output S of this traversal, recover the tree and return its root.

Input: "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]

Input: "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]

Input: "1-401--349---90--88"
Output: [1,401,null,349,88,90]

Note:

The number of nodes in the original tree is between 1 and 1000.
Each node will have a value between 1 and 10^9.
*/
class _1028_RecoverATreeFromPreorderTraversal {
public:
    TreeNode<int>* recoverFromPreorder(std::string S);
};

/*
There are 2N people a company is planning to interview. The cost of flying 
the i-th person to city A is costs[i][0], and the cost of flying the i-th 
person to city B is costs[i][1].
Return the minimum cost to fly every person to a city such that exactly N 
people arrive in each city.

Input: [[10,20],[30,200],[400,50],[30,20]]          :         Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
*/
// Inspired by the solution
class _1029_TwoCityScheduling {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs);
};

/*
We are given a matrix with R rows and C columns has cells with integer coordinates
(r, c), where 0 <= r < R and 0 <= c < C.
Additionally, we are given a cell in that matrix with coordinates (r0, c0).

Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) 
from smallest distance to largest distance. Here, the distance between two cells (r1, c1) 
and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1 - c2|.  (You may return the answer 
in any order that satisfies this condition.) 

Input: R = 1, C = 2, r0 = 0, c0 = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (r0, c0) to other cells are: [0,1]

Input: R = 2, C = 2, r0 = 0, c0 = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.

Input: R = 2, C = 3, r0 = 1, c0 = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as 
[[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
*/
class _1030_MatrixCellsInDistanceOrder {
public:
    std::vector<std::vector<int>> allCellsDistOrder(int R, int C, int r0, int c0);
private:
    int ManhattonDis(int i, int j, int r0, int c0);
};

/*
Given an array A of non-negative integers, return the maximum sum of elements in 
two non-overlapping (contiguous) subarrays, which have lengths L and M.  (For clarification, 
the L-length subarray could occur before or after the M-length subarray.)

Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + 
... + A[j+M-1]) and either:

0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
0 <= j < j + M - 1 < i < i + L - 1 < A.length.

Example 1:

Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
Example 2:

Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
Example 3:

Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] with length 3.

Note:
L >= 1
M >= 1
L + M <= A.length <= 1000
0 <= A[i] <= 1000
*/
class _1031_MaximumSumOfTwoNonOverlappingSubarrays {
public:
    int maxSumTwoNoOverlap(std::vector<int>& A, int L, int M);
};

/*
We write the integers of A and B (in the order they are given) on two separate horizontal lines.
Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

Example 1:
1   4   2
|     \  
1   2   4
Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2
 

Note:

1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000
*/
class _1035_UncrossedLines {
public:
    int maxUncrossedLines(std::vector<int>& A, std::vector<int>& B);
};

/*
Given the root of a binary search tree with distinct values, 
modify it so that every node has a new value equal to the 
sum of the values of the original tree that are greater 
than or equal to node.val.
As a reminder, a binary search tree is a tree that satisfies 
these constraints:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Note:

The number of nodes in the tree is between 1 and 100.
Each node will have value between 0 and 100.
The given tree is a binary search tree.
*/
class _1038_BinarySearchTreeToGreaterSumTree {
private:
    std::stack<TreeNode<int>*> vis;
public:
    TreeNode<int>* bstToGst(TreeNode<int>* root);
    void traverse(TreeNode<int>* root);
};

/*
We have a collection of rocks, each rock has a positive integer weight.
Each turn, we choose the two heaviest rocks and smash them together.  Suppose 
the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight 
y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 
0 if there are no stones left.)
*/
class _1046_LastStoneWeight {
public:
    int lastStoneWeight(std::vector<int>& stones);
};

/*
Given a string S of lowercase letters, a duplicate removal consists of 
choosing two adjacent and equal letters, and removing them.
We repeatedly make duplicate removals on S until we no longer can.
Return the final string after all such duplicate removals have been 
made.  It is guaranteed the answer is unique.

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are 
adjacent and equal, and this is the only possible move. The result 
of this move is that the string is "aaca", of which only "aa" is possible,
so the final string is "ca".

1 <= S.length <= 20000
S consists only of English lowercase letters.
*/
class _1047_RemoveAllAdjacentDuplicatesInString {
public:
    std::string removeDuplicates(std::string S);
};

/*
Given a list of words, each word consists of English lowercase letters.
Let's say word1 is a predecessor of word2 if and only if we can add 
exactly one letter anywhere in word1 to make it equal to word2. 
For example, "abc" is a predecessor of "abac".
A word chain is a sequence of words [word_1, word_2, ..., word_k] with 
k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor 
of word_3, and so on.
Return the longest possible length of a word chain with words chosen 
from the given list of words.

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
 

Note:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.
*/
class _1048_LongestStringChain {
public:
    int longestStrChain(std::vector<std::string>& words);
};

/*
Students are asked to stand in non-decreasing order of heights for an annual photo.
Return the minimum number of students not standing in the right positions. 
(This is the number of students that must move in order for all students to be 
standing in non-decreasing order of height.)

Input: [1,1,4,2,1,3]
Output: 3
Explanation: 
Students with heights 4, 3 and the last 1 are not standing in the right positions.

Note:

1 <= heights.length <= 100
1 <= heights[i] <= 100
*/
class _1051_HeightChecker {
public:
    int heightChecker(std::vector<int>& heights);
};

/*
Given a number N, return true if and only if it is a confusing number, 
which satisfies the following condition:
We can rotate digits by 180 degrees to form new digits. 
When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. 
When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid. 
A confusing number is a number that when rotated 180 degrees becomes a different 
number with each digit valid.

Input: 6
Output: true
Explanation: 
We get 9 after rotating 6, 9 is a valid number and 9!=6.

Input: 89
Output: true
Explanation: 
We get 68 after rotating 89, 86 is a valid number and 86!=89.

Input: 11
Output: false
Explanation: 
We get 11 after rotating 11, 11 is a valid number but the value remains the same, 
thus 11 is not a confusing number.

Input: 25
Output: false
Explanation: 
We get an invalid number after rotating 25.
 

Note:

0 <= N <= 10^9
After the rotation we can ignore leading zeros, for example if after rotation we 
have 0008 then this number is considered as just 8.
*/
class _1056_ConfusingNumber {
public:
    bool confusingNumber(int N);
};

/*
Given a sorted array A of unique numbers, find the K-th missing number starting from 
the leftmost number of the array.

Input: A = [4,7,9,10], K = 1
Output: 5
Explanation: 
The first missing number is 5.

Input: A = [4,7,9,10], K = 3
Output: 8
Explanation: 
The missing numbers are [5,6,8,...], hence the third missing number is 8.

Input: A = [1,2,4], K = 3
Output: 6
Explanation: 
The missing numbers are [3,5,6,7,...], hence the third missing number is 6.

Note:

1 <= A.length <= 50000
1 <= A[i] <= 1e7
1 <= K <= 1e8
*/
class _1060_MissingElementInSortedArray {
public:
    int missingElement(std::vector<int>& nums, int k);
};

/*
Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring text[i]...text[j] is in the list of words.

Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]

Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation: 
Notice that matches can overlap, see "aba" is found in [0,2] and [2,4]. 

Note:

All strings contains only lowercase English letters.
It's guaranteed that all strings in words are different.
1 <= text.length <= 100
1 <= words.length <= 20
1 <= words[i].length <= 50
Return the pairs [i,j] in sorted order (i.e. sort them by their first coordinate in case of ties sort them by their second coordinate).
*/
class _1065_IndexPairOfAString {
public:
    std::vector<std::vector<int>> indexPairs(std::string text, std::vector<std::string>& words);
};


/*
1074. Number of Submatrices That Sum to Target

Given a matrix, and a target, return the number of non-empty submatrices 
that sum to target. A submatrix x1, y1, x2, y2 is the set of all cells 
matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different 
if they have some coordinate that is different: for example, if x1 != x1'.

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

Note:

    1 <= matrix.length <= 300
    1 <= matrix[0].length <= 300
    -1000 <= matrix[i] <= 1000
    -10^8 <= target <= 10^8
 */
class _1074_NumberOfSubmatricesThatSumToTarget {
  public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>>&A, int target);
};

/*
You have a set of tiles, where each tile has one letter tiles[i] 
printed on it. Return the number of possible non-empty sequences 
of letters you can make.

Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Input: "AAABBC"
Output: 188

Note:
1 <= tiles.length <= 7
tiles consists of uppercase English letters.
*/
class _1079_LetterTilePossibilities {
public:
    int numTilePossibilities(std::string tiles);
};

/*
Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.

Input: "cdadabcc"         :         Output: "adbc"
Input: "abcd"             :         Output: "abcd"
Input: "ecbacba"          :         Output: "eacb"
Input: "leetcode"         :         Output: "letcod"

1 <= text.length <= 1000
text consists of lowercase English letters.
*/
class _1081_SmallestSubsequenceOfDistinctCharacters {
public:
    std::string smallestSubsequenc(std::string text);
};


/*
We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:

|S| <= num_wanted
For every label L, the number of items in S with label L is <= use_limit.
Return the largest possible sum of the subset S.

 

Example 1:

Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
Output: 9
Explanation: The subset chosen is the first, third, and fifth item.
Example 2:

Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
Output: 12
Explanation: The subset chosen is the first, second, and third item.
Example 3:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
Output: 16
Explanation: The subset chosen is the first and fourth item.
Example 4:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 2
Output: 24
Explanation: The subset chosen is the first, second, and fourth item.
 

Note:

1 <= values.length == labels.length <= 20000
0 <= values[i], labels[i] <= 20000
1 <= num_wanted, use_limit <= values.length
*/
class _1090_LargestValuesFromLabels {
public:
    int largestValsFromLabels(std::vector<int>& values, std::vector<int>& labels, int num_wanted, int use_limit);
};


/*
You are driving a vehicle that has capacity empty seats initially available 
for passengers. The vehicle only drives east (ie. it cannot turn around and 
drive west.)
Given a list of trips, trip[i] = [num_passengers, start_location, end_location] 
contains information about the i-th trip: the number of passengers that must 
be picked up, and the locations to pick them up and drop them off. The locations 
are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true

Input: trips = [[2,1,5],[3,5,7]], capacity = 3
Output: true

Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
Output: true
*/
class _1094_CarPooling {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity);
};

}

#endif