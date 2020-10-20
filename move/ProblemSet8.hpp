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