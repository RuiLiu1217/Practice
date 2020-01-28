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
In a row of trees, the i-th tree produces fruit with type tree[i].
You start at any tree of your choice, then repeatedly perform the following steps:

1. Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
2. Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.

Note that you do not have any choice after the initial choice of starting tree: you must 
perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.
You have two baskets, and each basket can carry any quantity of fruit, but you want each 
basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].

Input: [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2].
If we started at the first tree, we would only collect [0, 1].

Input: [1,2,3,2,2]
Output: 4
Explanation: We can collect [2,3,2,2].
If we started at the first tree, we would only collect [1, 2].

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.

1 <= tree.length <= 40000
0 <= tree[i] < tree.length
*/
class _0904_FruitInoBackets {
public:
    int totalFruit(std::vector<int>& tree);
};

/*
Given an array A of non-negative integers, return an array 
consisting of all the even elements of A, followed by all 
the odd elements of A.
You may return any answer array that satisfies this condition.

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/
class _0905_SortArrayByParity {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& A);
};

/*
In an election, the i-th vote was cast for persons[i] at time times[i].
Now, we would like to implement the following query function: 
TopVotedCandidate.q(int t) will return the number of the person that was 
leading the election at time t.  
Votes cast at time t will count towards our query.  In the case of a 
tie, the most recent vote (among tied candidates) wins.

Input: ["TopVotedCandidate","q","q","q","q","q","q"], 
[[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation: 
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.
 
1 <= persons.length = times.length <= 5000
0 <= persons[i] <= persons.length
times is a strictly increasing array with all elements in [0, 10^9].
TopVotedCandidate.q is called at most 10000 times per test case.
TopVotedCandidate.q(int t) is always called with t >= times[0].
*/
class _0911_OnlineElection {
public:
    _0911_OnlineElection(std::vector<int>& persons, std::vector<int>& times);
    int q(int t);
private:
    std::map<int, int> Map;
};

/*
Given an array of integers nums, sort the array in ascending order.
*/
class _0912_SortAnArray {
public:
    std::vector<int> sortArray(std::vector<int>& nums);
private:
    void sortArray(std::vector<int>& nums, int start, int end);
    void merge(std::vector<int>& nums, int start, int end, int mid);
};

/*
Given a string S of '(' and ')' parentheses, we add the minimum number of 
parentheses ( '(' or ')', and in any positions ) so that the resulting 
parentheses string is valid.

Formally, a parentheses string is valid if and only if:
It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we 
must add to make the resulting string valid.

Input: "())"
Output: 1

Input: "((("
Output: 3

Input: "()"
Output: 0

Input: "()))(("
Output: 4

Note:

S.length <= 1000
S only consists of '(' and ')' characters.
*/
class _0921_MinimumAddToMakeParenthesesValid {
public:
    int minAddToMakeValid(std::string s);
};

/*
Given an array A of non-negative integers, half of the integers in A are odd, 
and half of the integers are even. Sort the array so that whenever A[i] is odd, 
i is odd; and whenever A[i] is even, i is even. You may return any answer array 
that satisfies this condition.

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
*/
class _0922_SortArrayByParityII {
public:
    std::vector<int> sortArrayByParityII(std::vector<int>& A);
};

/*
Given an integer array A, and an integer target, return the 
number of tuples i, j, k  such that i < j < k and A[i] + 
A[j] + A[k] == target.
As the answer can be very large, return it modulo 10^9 + 7.

Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (A[i], A[j], A[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.

Input: A = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
 
Note:
3 <= A.length <= 3000
0 <= A[i] <= 100
0 <= target <= 300
*/
class _0923_3SumWithMultiplicity {
public:
    int threeSumMulti(std::vector<int>& A, int target);
};

/*
Every email consists of a local name and a domain name, separated by the @ sign.
For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.
Besides lowercase letters, these emails may contain '.'s or '+'s.
If you add periods ('.') between some characters in the local name part of an email address, mail 
sent there will be forwarded to the same address without dots in the local name. 
For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address. 
(Note that this rule does not apply for domain names.)
If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. 
This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to
my@email.com.  (Again, this rule does not apply for domain names.)
It is possible to use both of these rules at the same time.
Given a list of emails, we send one email to each address in the list. 
How many different addresses actually receive mails? 

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
 
Note:

1 <= emails[i].length <= 100
1 <= emails.length <= 100
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.
*/
class _0929_UniqueEmailAddress {
public:
    int numUniqueEmails(std::vector<std::string>& emails);
};

/*
Given a square array of integers A, we want the minimum sum of a 
falling path through A. A falling path starts at any element in 
the first row, and chooses one element from each row. The next 
row's choice must be in a column that is different from the 
previous row's column by at most one.

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12

Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

Note:

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100
*/
class _0931_MinimumFallingPathSum {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& A);
};


/*
Write a class RecentCounter to count recent requests.
It has only one method: ping(int t), where t represents some 
time in milliseconds.
Return the number of pings that have been made from 3000 
milliseconds ago until now.
Any ping with time in [t - 3000, t] will count, including 
the current ping.
It is guaranteed that every call to ping uses a strictly larger 
value of t than before.

Input: inputs = ["RecentCounter","ping","ping","ping","ping"], 
inputs = [[],[1],[100],[3001],[3002]]
Output: [null,1,2,3,3]

Each test case will have at most 10000 calls to ping.
Each test case will call ping with strictly increasing values of t.
Each call to ping will have 1 <= t <= 10^9.
*/
class _0933_NumberOfRecentCalls {
private:
    std::queue<int> q;
public:
    _0933_NumberOfRecentCalls();
    int ping(int t);
};

/*
In a given 2D binary array A, there are two islands.  
(An island is a 4-directionally connected group of 1s not connected to any other 1s.)
Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
Return the smallest number of 0s that must be flipped. 
(It is guaranteed that the answer is at least 1.)

Input: [[0,1],[1,0]]
Output: 1

Input: [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

Note:

1 <= A.length = A[0].length <= 100
A[i][j] == 0 or A[i][j] == 1 
*/
class _0934_ShortestBridge {
public:
    int shortestBridge(std::vector<std::vector<int>>& A);
private:
    int paint(std::vector<std::vector<int>>& A, int i, int j);
    bool expand(std::vector<std::vector<int>>& A, int i, int j, int color);
};

/*
Given the root node of a binary search tree, return the sum of 
values of all nodes with value between L and R (inclusive).
The binary search tree is guaranteed to have unique values.

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23

Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.
*/
class _0938_RangeSumOfBST {
public:
    int rangeSumBST(TreeNode<int>* root, int L, int R);
};


/*
Given a string S that only contains "I" (increase) or "D" (decrease), 
let N = S.length.
Return any permutation A of [0, 1, ..., N] such that for all 
i = 0, ..., N-1:
If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]

Input: "IDID"
Output: [0,4,1,3,2]

Input: "III"
Output: [0,1,2,3]

Input: "DDI"
Output: [3,2,0,1]

Note:
1 <= S.length <= 10000
S only contains characters "I" or "D".
*/
class _0942_DIStringMatch {
public:
    std::vector<int> disStringMatch(std::string S);
};

/*
We are given an array A of N lowercase letter strings, all of the same 
length. Now, we may choose any set of deletion indices, and for each string, 
we delete all the characters in those indices. For example, if we have an
array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the 
final array after deletions is ["bef", "vyz"], and the remaining columns 
of A are ["b","v"], ["e","y"], and ["f","z"]. 
(Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]].)
Suppose we chose a set of deletion indices D such that after deletions, 
each remaining column in A is in non-decreasing sorted order.
Return the minimum possible value of D.length.

Input: ["cba","daf","ghi"]
Output: 1
Explanation: 
After choosing D = {1}, each column ["c","d","g"] and ["a","f","i"] are in 
non-decreasing sorted order. If we chose D = {}, then a column 
["b","a","h"] would not be in non-decreasing sorted order.

Input: ["a","b"]
Output: 0
Explanation: D = {}

Input: ["zyx","wvu","tsr"]
Output: 3
Explanation: D = {0, 1, 2}

Note:
1 <= A.length <= 100
1 <= A[i].length <= 1000
*/
class _0944_DeleteColumnsToMakeSorted {
public:
    int minDeletionSize(std::vector<std::string>& A);
};

/*
Given two sequences pushed and popped with distinct values, return true 
if and only if this could have been the result of a sequence of push and 
pop operations on an initially empty stack.

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
*/
class _0946_ValidateStackSequences {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped);
};


/*
You are installing a billboard and want it to have the largest 
height. The billboard will have two steel supports, one on each 
side. Each steel support must be an equal height. You have a 
collection of rods which can be welded together. For example, if 
you have rods of lengths 1, 2, and 3, you can weld them together
to make a support of length 6.

Return the largest possible height of your billboard installation.
If you cannot support the billboard, return 0.

Input: [1,2,3,6]             :            Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.

Input: [1,2,3,4,5,6]         :            Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.

Input: [1,2]                 :            Output: 0
Explanation: The billboard cannot be supported, so we return 0.

这道题如果用Backtracing 比较直观但是会超时，数据的大小是 0 <= rods.length <= 20
每个rod 有三个情况， 0， 不选， 1， 放左边， 2 放右边。

这道题的解法仍然是动态规划，不过状态转移还是很难想出来的。
DP[n][i] --> 表示当用到n个柱子的时候，两边的差为 i 可以达到的最大公共高度
因此状态转移方程就是：

DP[n][i + h] = max(DP[n][i], DP[n-1][i]);           当用到n个柱子时把柱子放在高的那一边，公共高度跟用n-1个柱子一样，可是高度差变成了 i + h
DP[n][|i-h|] = max(DP[n][|i-h|], DP[n-1][i] + min(h, i)); // 如果把第n个柱子放在矮的那边，公共高度一定是增长了 min(i, h), 高度差就变成了 |i-h| 
因为不知道h大还是原先的i大。
因此，解为 DP[N][0]
*/
class _0956_TallestBillboard {
public:
    int tallestBillboard(std::vector<int>& rods);
};


/*
Given a binary tree, determine if it is a complete binary tree.
Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely 
filled, and all nodes in the last level are as far left as possible. It can have 
between 1 and 2h nodes inclusive at the last level h.
*/
class _0958_CheckCompletenessOfABinaryTree {
public:
    bool siCompleteTree(TreeNode<int>* root);
};

/*
Given a set of points in the xy-plane, determine the minimum area of any rectangle 
formed from these points, with sides not necessarily parallel to the x and y axes.
If there isn't any rectangle, return 0.

Input: [[1,2],[2,1],[1,0],[0,1]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.

Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
Output: 1.00000
Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.

Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
Output: 0
Explanation: There is no possible rectangle to form from these points.

Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
Output: 2.00000
Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.
 
Note:
1 <= points.length <= 50
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
Answers within 10^-5 of the actual value will be accepted as correct.
*/
class _0963_MinimumAreaRectangleII {
public:
    double minAreaFreeRect(std::vector<std::vector<int>>& points);
};

/*
Given two positive integers x and y, an integer is powerful if it is equal to 
x^i + y^j for some integers i >= 0 and j >= 0.
Return a list of all powerful integers that have value less than or equal to bound.
You may return the answer in any order.  In your answer, each value should occur at 
most once.

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation: 
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]

1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6
*/
class _0970_PowerfulIntegers {
public:
    std::vector<int> powerfulIntegers(int x, int y, int bound);
};


/*
Flip Binary Tree To Match Preorder Traversal
Given a binary tree with N nodes, each node has a different value from 
{1, ..., N}. A node in this binary tree can be flipped by swapping the 
left child and the right child of that node. Consider the sequence of 
N values reported by a preorder traversal starting from the root. Call 
such a sequence of N values the voyage of the tree. (Recall that a preorder 
traversal of a node means we report the current node's value, then preorder
-traverse the left child, then preorder-traverse the right child.)
Our goal is to flip the least number of nodes in the tree so that the 
voyage of the tree matches the voyage we are given. If we can do so, then 
return a list of the values of all nodes flipped.  You may return the answer 
in any order.

If we cannot do so, then return the list [-1].
*/
class _0971_FlipBinaryTreeToMatchPreorderTraversal {
public:
	std::vector<int> flipMatchVoyage(TreeNode<int>* root, std::vector<int>& voyage);
};

/*
Given the root of a binary tree with N nodes, each node in the tree has node.val coins, 
and there are N coins total.
In one move, we may choose two adjacent nodes and move one coin from one node to another.
(The move may be from parent to child, or from child to parent.)
Return the number of moves required to make every node have exactly one coin.

Input: [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

Input: [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves].  Then, we move one coin from the root of the tree to the right child.

Input: [1,0,2]
Output: 2

Input: [1,0,0,null,3]
Output: 4

Note:

1<= N <= 100
0 <= node.val <= N
*/
class _0979_DistributeCoinsInBinaryTree {
private:
    int ans = 0;
public:
    int distriuteCoins(TreeNode<int>* root);
    int DFS(TreeNode<int>* root);
};

/*
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, 
that walk over every non-obstacle square exactly once.

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

Note:

1 <= grid.length * grid[0].length <= 20
*/
class _0980_UniquePathsIII {
public:
    int uniquePathsIII(std::vector<std::vector<int>>& grid);
};


/*
Given an array of integers A, find the number of triples of indices (i, j, k) such that:

0 <= i < A.length
0 <= j < A.length
0 <= k < A.length
A[i] & A[j] & A[k] == 0, where & represents the bitwise-AND operator.
 
Input: [2,1,3]
Output: 12
Explanation: We could choose the following i, j, k triples:
(i=0, j=0, k=1) : 2 & 2 & 1
(i=0, j=1, k=0) : 2 & 1 & 2
(i=0, j=1, k=1) : 2 & 1 & 1
(i=0, j=1, k=2) : 2 & 1 & 3
(i=0, j=2, k=1) : 2 & 3 & 1
(i=1, j=0, k=0) : 1 & 2 & 2
(i=1, j=0, k=1) : 1 & 2 & 1
(i=1, j=0, k=2) : 1 & 2 & 3
(i=1, j=1, k=0) : 1 & 1 & 2
(i=1, j=2, k=0) : 1 & 3 & 2
(i=2, j=0, k=1) : 3 & 2 & 1
(i=2, j=1, k=0) : 3 & 1 & 2

Note:
1 <= A.length <= 1000
0 <= A[i] < 2^16
*/
class _0982_TriplesWithBitwiseAndEqualToZero {
public:
    int countTriplets(std::vector<int>& A);
};

/*
Given two integers A and B, return any string S such that:
S has length A + B and contains exactly A 'a' letters, 
and exactly B 'b' letters;
The substring 'aaa' does not occur in S;
The substring 'bbb' does not occur in S.

Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.

Input: A = 4, B = 1
Output: "aabaa" 

Note:

0 <= A <= 100
0 <= B <= 100
It is guaranteed such an S exists for the given A and B.
*/
class _0984_StringWithoutAAAOrBBB {
public:
    std::string strWithout3a3b(int A, int B);
};

/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in 
sorted order. Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with 
a <= x <= b. The intersection of two closed intervals is a set of real numbers that is 
either empty, or can be represented as a closed interval.  For example, the intersection 
of [1, 3] and [2, 4] is [2, 3].)

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not 
arrays or lists.
*/
class _0986_IntervalListIntersections {
public:
    std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B);
};

/*
Given an array equations of strings that represent relationships 
between variables, each string equations[i] has length 4 and takes 
one of two different forms: "a==b" or "a!=b".  Here, a and b are 
lowercase letters (not necessarily different) that represent 
one-letter variable names.
Return true if and only if it is possible to assign integers to 
variable names so as to satisfy all the given equations.

Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.

Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

Input: ["a==b","b==c","a==c"]
Output: true

Input: ["a==b","b!=c","c==a"]
Output: false
Example 5:

Input: ["c==c","b==d","x!=z"]
Output: true
 

Note:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] and equations[i][3] are lowercase letters
equations[i][1] is either '=' or '!'
equations[i][2] is '='
*/
class _0990_SatisfiabilityOfEqualityEquations {
public:
    bool equationPossible(std::vector<std::string>& equations);
};

}

#endif