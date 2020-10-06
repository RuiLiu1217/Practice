#ifndef PROBLEM_SET8_HPP
#define PROBLEM_SET8_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include "Tree.hpp"
#include "LinkList.hpp"

namespace LeetCode {

/*
Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  In these strings 
like "heeellooo", we have groups of adjacent letters that are all the same:  "h", "eee", "ll", "ooo".
For some given string S, a query word is stretchy if it can be made to be equal to S by any number of applications of the following 
extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the 
size of the group is 3 or more.
For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since 
the group "oo" has size less than 3.  Also, we could do another extension like "ll" -> "lllll" to get "helllllooo".  
If S = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = S.

Given a list of query words, return the number of words that are stretchy. 

Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more. 

Notes:

0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters
*/
class _0809_ExpressiveWords {
public:
    int expressiveWords(std::string S, std::vector<std::string>& words);
private:
    bool check(std::string S, std::string W);
};

/*
A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have 
"com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When 
we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and 
"com" implicitly.
Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), 
followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".
We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, 
(in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.

Example 1:
Input: 
["9001 discuss.leetcode.com"]
Output: 
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
Explanation: 
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and 
"com" will also be visited. So they will all be visited 9001 times.

Input: 
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output: 
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation: 
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. 
For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

Notes:
The length of cpdomains will not exceed 100. 
The length of each domain name will not exceed 100.
Each address will have either 1 or 2 "." characters.
The input count in any count-paired domain will not exceed 10000.
The answer output can be returned in any order.
*/
class _0811_SubdomainVisitCount {
public:
    std::vector<std::string> subdomainVisits(std::vector<std::string>& cpdomains);
};

/*
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.

Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.
*/
class _0812_LargestTriangleArea {
public:
    double largestTriangleArea(std::vector<std::vector<int>>& points);
};

/*
We are given the head node root of a binary tree, where additionally every
node's value is either a 0 or a 1.
Return the same tree where every subtree (of the given tree) not containing 
a 1 has been removed.
(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

Example 1:
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]
 
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Input: [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Input: [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

Note:

The binary tree will have at most 100 nodes.
The value of each node will only be 0 or 1.
*/
class _0814_BinaryTreePruning {
public:
    TreeNode<int>* pruneTree(TreeNode<int>* root);
};

/*
We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". 
Then, we removed all commas, decimal points, and spaces, and ended 
up with the string S. Return a list of strings representing all 
possibilities for what our original coordinates could have been.

Our original representation never had extraneous zeroes, so we never 
started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", 
or any other number that can be represented with less digits. Also, a 
decimal point within a number never occurs without at least one digit 
occuring before it, so we never started with numbers like ".1".

The final answer list can be returned in any order.  Also note that 
all coordinates in the final answer have exactly one space between 
them (occurring after the comma.)

Input: "(123)"
Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]

Input: "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation: 
0.0, 00, 0001 or 00.01 are not allowed.

Input: "(0123)"
Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]

Input: "(100)"
Output: [(10, 0)]
Explanation: 
1.0 is not allowed.

Note:
4 <= S.length <= 12.
S[0] = "(", S[S.length - 1] = ")", and the other elements in S are digits.
*/
class _0816_AmbiguousCoordinates {
public:
    std::vector<std::string> ambiguousCoordinates(std::string S);
};

/*
    Given an array of unique integers, each integer is strictly greater than 1.
    We make a binary tree using these integers and each number may be used for 
    any number of times. Each non-leaf node's value should be equal to the 
    product of the values of it's children.
    How many binary trees can we make? Return the answer modulo 10 ** 9 + 7.

    Input: A = [2, 4]             :              Output: 3
    We can make these trees: [2], [4], [4, 2, 2]

    Input: A = [2, 4, 5, 10]      :              Output: 7
    We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].

    1 <= A.length <= 1000.
    2 <= A[i] <= 10 ^ 9.
*/
class _0823_BinaryTreeWithFactors {
public:
    int numFactoredBinaryTrees(std::vector<int>& A);
};


/*
To some string S, we will perform some replacement operations that replace groups of 
letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and 
a target word y. The rule is that if x starts at position i in the original string S, 
then we will replace that occurrence of x with y. If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, 
x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string S, 
we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, 
x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", 
this second operation does nothing because in the original string S[2] = 'c', 
which doesn't match x[0] = 'e'.

All these operations occur simultaneously. It's guaranteed that there won't be any overlap 
in replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a 
valid test case.

Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
Output: "eeebffff"
Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".

Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation: "ab" starts at index 0 in S, so it's replaced by "eee". 
"ec" doesn't starts at index 2 in the original S, so we do nothing.
Notes:

0 <= indexes.length = sources.length = targets.length <= 100
0 < indexes[i] < S.length <= 1000
All characters in given inputs are lowercase letters.
*/
class _0833_FindAndReplaceInString {
public:
    std::string findReplaceString(std::string S, std::vector<int>& indexes, std::vector<std::string>& sources,
    std::vector<std::string>& targets);
};



/*
There are N rooms and you start in room 0. Each room has a distinct number in 0, 
1, 2, ..., N-1, and each room may have some keys to access the next room. 
Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an 
integer in [0, 1, ..., N-1] where N = rooms.length. A key rooms[i][j] = v opens 
the room with number v.
Initially, all the rooms start locked (except for room 0). You can walk back and 
forth between rooms freely.
Return true if and only if you can enter every room.

Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.

Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
Note:

1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.
*/
class _0841_KeysAndRooms {
public:
     bool canVisitAllRooms(std::vector<std::vector<int>>& rooms);
};


/*
Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
F.length >= 3;
and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Input: "123456579"   :    Output: [123,456,579]
Input: "11235813"    :    Output: [1,1,2,3,5,8,13]
Input: "112358130"   :    Output: []
Explanation: The task is impossible.

Input: "0123"        :    Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.

Input: "1101111"     :    Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.
Note:

1 <= S.length <= 200
S contains only digits.
*/
class _0842_SplitArrayIntoFibonacciSequence {
public:
// Copy from the solution, the difficulty is how to design the function interface
    std::vector<int> splitIntoFibonacci(std::string S);
};

/*
Tag: Unknow, my solution is slow

Google

Alice has a hand of cards, given as an array of integers.
Now she wants to rearrange the cards into groups so that each 
group is size W, and consists of W consecutive cards.

Return true if and only if she can.

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.

Note:
1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length
*/
class _0846_HandOfStraights {
public:
    bool isNStraightHand(std::vector<int>& hand, int W);
private:
    bool isNStraightHand(std::map<int, int>& hand, int W, int S);
};

/*
In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different amounts of money, and different levels of quietness.
For convenience, we'll call the person with label x, simply "person x".
We'll say that richer[i] = [x, y] if person x definitely has more money than person y.  Note that richer may only be a subset of valid observations.
Also, we'll say quiet[x] = q if person x has quietness q.
Now, return answer, where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]), among all people who definitely have equal to or more money than person x.

Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
Explanation: 
answer[0] = 5.
Person 5 has more money than 3, which has more money than 1, which has more money than 0.
The only person who is quieter (has lower quiet[x]) is person 7, but
it isn't clear if they have more money than person 0.

answer[7] = 7.
Among all people that definitely have equal to or more money than person 7
(which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x])
is person 7.

The other answers can be filled out with similar reasoning.
Note:

1 <= quiet.length = N <= 500
0 <= quiet[i] < N, all quiet[i] are different.
0 <= richer.length <= N * (N-1) / 2
0 <= richer[i][j] < N
richer[i][0] != richer[i][1]
richer[i]'s are all different.
The observations in richer are all logically consistent.
*/
class _0851_LoudAndRich {
private:
    std::unordered_map<int, std::vector<int>> richer2;
    std::vector<int> res;
public:
    std::vector<int> loudAndRich(std::vector<std::vector<int>>& richer, std::vector<int>& quiet);
    int dfs(int i, std::vector<int>& quiet);
};

/*
Return the length of the shortest, non-empty, contiguous subarray of A 
with sum at least K.
If there is no non-empty subarray with sum at least K, return -1.

Input: A = [1], K = 1
Output: 1

Input: A = [1,2], K = 4
Output: -1

Input: A = [2,-1,2], K = 3
Output: 3

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9
这道题完全没有头绪，是抄答案的，关键点需要使用一个双向队列
*/
class _0862_ShortestSubarrayWithSumAtLeastK {
public:
    int shortestSubarray(std::vector<int>& A, int K);
};

/*
Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.
A node is deepest if it has the largest depth possible among any node in the entire tree.
The subtree of a node is that node, plus the set of all descendants of that node.
Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]

We return the node with value 2, colored in yellow in the diagram.
The nodes colored in blue are the deepest nodes of the tree.
The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
Both the input and output have TreeNode type.

Note:

The number of nodes in the tree will be between 1 and 500.
The values of each node are unique.
*/
class _0865_SmallestSubtreeWithAllTheDeepestNodes {
public:
    TreeNode<int>* subtreeWithAllDeepest(TreeNode<int>* root);
    std::pair<int, TreeNode<int>*> depth(TreeNode<int>* root);
};

/*
Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].
Return any permutation of A that maximizes its advantage with respect to B.

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]

Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12] 

Note:

1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9
*/
class _0870_AdvancedShuffle {
public:
    std::vector<int> advantageCount(std::vector<int>& A, std::vector<int>& B);
private:
    void updateA(std::vector<int>& A, int idx);
    int binarySearch(std::vector<int>& A, int v);
};

/*
A sequence X_1, X_2, ..., X_n is fibonacci-like if:

n >= 3
X_i + X_{i+1} = X_{i+2} for all i + 2 <= n

Given a strictly increasing array A of positive integers forming 
a sequence, find the length of the longest fibonacci-like 
subsequence of A. If one does not exist, return 0.
(Recall that a subsequence is derived from another sequence A 
by deleting any number of elements (including none) from A, without 
changing the order of the remaining elements. For example, 
[3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)

Input: [1,2,3,4,5,6,7,8]
Output: 5
Explanation:
The longest subsequence that is fibonacci-like: [1,2,3,5,8].

Input: [1,3,7,11,12,14,18]
Output: 3
Explanation:
The longest subsequence that is fibonacci-like:
[1,11,12], [3,11,14] or [7,11,18].

Note:

3 <= A.length <= 1000
1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
*/
class _0873_LengthOfLongestFibonacciSubsequence {
public:
    int lenLongestFibSubseq(std::vector<int>& A);
};


/*
Koko loves to eat bananas. There are N piles of bananas, the i-th pile has piles[i] bananas. 
The guards have gone and will come back in H hours.

Koko can decide her bananas-per-hour eating speed of K. Each hour, she chooses some pile of 
bananas, and eats K bananas from that pile. If the pile has less than K bananas, she eats all 
of them instead, and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
Return the minimum integer K such that she can eat all the bananas within H hours.

Input: piles = [3,6,7,11], H = 8
Output: 4

Input: piles = [30,11,23,4,20], H = 5
Output: 30

Input: piles = [30,11,23,4,20], H = 6
Output: 23
 
Note:

1 <= piles.length <= 10^4
piles.length <= H <= 10^9
1 <= piles[i] <= 10^9
*/
class _0875_KokoEatingBananas {
public:
    int minEatingSpeed(std::vector<int>& piles, int H);
};


/*
Alex and Lee play a game with piles of stones. There are an even number 
of piles arranged in a row, and each pile has a positive integer number
of stones piles[i]. The objective of the game is to end with the most 
stones.  The total number of stones is odd, so there are no ties. Alex 
and Lee take turns, with Alex starting first.  Each turn, a player takes 
the entire pile of stones from either the beginning or the end of the row.  
This continues until there are no more piles left, at which point the 
person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex 
wins the game.

Input: [5,3,4,5]           :           Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
*/
class _0877_StoneGame {
private:
    std::vector<int> totStone;
    std::vector<std::vector<int>> alexMap;
    std::vector<std::vector<int>> leeMap;
public:
    bool stoneGame(std::vector<int>& piles);
    int AlexMax(std::vector<int>& piles, int start, int end);
    int LeeMax(std::vector<int>& piles, int start, int end);
};


/*
On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.
Here, the north-west corner of the grid is at the first row and column, and the south-east
corner of the grid is at the last row and column.
Now, we walk in a clockwise spiral shape to visit every position in this grid. 
Whenever we would move outside the boundary of the grid, we continue our walk outside the 
grid (but may return to the grid boundary later.) 

Eventually, we reach all R * C spaces of the grid.
Return a list of coordinates representing the positions of the grid in the order they were visited.

Input: R = 1, C = 4, r0 = 0, c0 = 0
Output: [[0,0],[0,1],[0,2],[0,3]]

Input: R = 5, C = 6, r0 = 1, c0 = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],
         [3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],
         [2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
Note:

1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C
Accepted
*/
class _0885_SpiralMatrixIII {
public:
    std::vector<std::vector<int>> spiralMatrixIII(int R, int C, int r0, int c0);
};

/*
You have a list of words and a pattern, and you want to know which words in words 
matches the pattern. A word matches the pattern if there exists a permutation of 
letters p so that after replacing every letter x in the pattern with p(x), we get 
the desired word. (Recall that a permutation of letters is a bijection from letters 
to letters: every letter maps to another letter, and no two letters map to the 
same letter.)
Return a list of the words in words that match the given pattern. 
You may return the answer in any order.

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.

Note:

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
*/
class _0890_FindAndReplacePattern {
public:
    std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern);
};


/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.
Return a list of all possible full binary trees with N nodes.  Each element of the 
answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.
You may return the final list of trees in any order. 

Example 1:

Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
*/
class _0894_AllPossibleFullBinaryTrees {
public:
    std::vector<TreeNode<int>*> allPossibleFBT(int N);
};

/*
Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 
Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].
 

Note:

Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
The total number of FreqStack.push calls will not exceed 10000 in a single test case.
The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
*/
class _0895_MaximumFrequencyStack {
private:
    // Copy inspired by the solution
    std::map<int, int> freq; // A Map from x to the number of frequency occurences of x
    std::map<int, std::stack<int>> group; // group data according to their frequency. If push 5, 5 -->  group[1]->5,  group[2]->5 respectively.
    int maxFreq; // Keep the maximum frequency
public:
    _0895_MaximumFrequencyStack();
    void push(int x);
    int pop();
};


/*
A string S of lowercase letters is given.  Then, we may make any number of moves.
In each move, we choose one of the first K letters (starting from the left), remove it, and place it at the end of the string.
Return the lexicographically smallest string we could have after any number of moves.

Input: S = "cba", K = 1
Output: "acb"
Explanation: 
In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".
In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".

Input: S = "baaca", K = 3
Output: "aaabc"
Explanation: 
In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".
In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".
*/
class _0899_OrderlyQueue {
public:
    std::string orderlyQueue(std::string S, int K);
};

}

#endif