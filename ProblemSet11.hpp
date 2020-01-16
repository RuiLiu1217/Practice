#ifndef PROBLEM_SET11_HPP
#define PROBLEM_SET11_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"
namespace LeetCode {
    /*
Given an array A of strings made only from lowercase letters, return a list 
of all characters that show up in all strings within the list (including 
duplicates). For example, if a character occurs 3 times in all strings but 
not 4 times, you need to include that character three times in the final 
answer.
You may return the answer in any order.

Input: ["bella","label","roller"]
Output: ["e","l","l"]

Input: ["cool","lock","cook"]
Output: ["c","o"]
Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/
class _1002_FindCommonCharacters {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& A);
};

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
Return the root node of a binary search tree that matches 
the given preorder traversal.
(Recall that a binary search tree is a binary tree where 
for every node, any descendant of node.left has a value < 
node.val, and any descendant of node.right has a value > 
node.val.  Also recall that a preorder traversal displays 
the value of the node first, then traverses node.left, then 
traverses node.right.)

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Note: 
1 <= preorder.length <= 100
The values of preorder are distinct.
*/
class _1008_ConstructBinarySearchTreeFromPreorderTraversal {
private:
    int i = 0;
public:
    TreeNode<int>* bstFromPreorder(std::vector<int>& preorder);
    TreeNode<int>* bstFromPreorderImpl(std::vector<int>& preorder, int bound);
};

/*
Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N, 
return true if and only if for every integer X from 1 to N, the binary representation of X 
is a substring of S.

Input: S = "0110", N = 3
Output: true

Input: S = "0110", N = 4
Output: false

Note:

1 <= S.length <= 1000
1 <= N <= 10^9
*/
class _1016_BinaryStringWithSubstringsRepresenting1ToN {
public:
    bool queryString(std::string S, int N);
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
Given a 2D array A, each cell is 0 (representing sea) or 1 (representing 
land) A move consists of walking from one land square 4-directionally to 
another land square, or off the boundary of the grid. Return the number of 
land squares in the grid for which we cannot walk off the boundary of the 
grid in any number of moves. 

Example 1:

Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: 
There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed 
because its on the boundary.
Example 2:

Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: 
All 1s are either on the boundary or can reach the boundary.

Note:

1 <= A.length <= 500
1 <= A[i].length <= 500
0 <= A[i][j] <= 1
All rows have the same size.
*/
class _1020_NumberOfEnclaves {
public:
    int numEnclaves(std::vector<std::vector<int>>& A);

private:
    void DFS(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& visited, int i, int j);
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
class _1025_DivisorGame
{
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