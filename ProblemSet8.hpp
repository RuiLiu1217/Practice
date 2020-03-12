#ifndef PROBLEM_SET8_HPP
#define PROBLEM_SET8_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

namespace LeetCode {
    /*
701. Insert into a Binary Search Tree
Given the root node of a binary search tree (BST) and a value to 
be inserted into the tree, insert the value into the BST. Return 
the root node of the BST after the insertion. It is guaranteed 
that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, 
as long as the tree remains a BST after insertion. You can 
return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4
*/
class _0701_InsertIntoABinarySearchTree {
public:
    TreeNode<int>* insertIntoBST(TreeNode<int>* root, int val);
};

/*
709. To Lower Case
Implement function ToLowerCase() that has a string parameter 
str, and returns the same string in lowercase.

Input: "Hello"
Output: "hello"

Input: "here"
Output: "here"

Input: "LOVELY"
Output: "lovely"
*/
class _0709_ToLowerCase {
public:
    std::string toLowerCase(std::string str);
};

/*
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. 
If you find more than one maximum elements, only remove the top-most one.

MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
*/
class _0716_MaxStack {
private:
    std::stack<int> normal;
    std::stack<int> maximu;
public:
    _0716_MaxStack() {}
    void push(int x);
    int pop();
    int top();
    int peekMax();
    int popMax();
};

/*
We have two special characters. The first character can be represented by 
one bit 0. The second character can be represented by two bits (10 or 11).
Now given a string represented by several bits. Return whether the last 
character must be a one-bit character or not. The given string will always 
end with a zero.


Input:  bits = [1, 0, 0]        :        Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.

Input:  bits = [1, 1, 1, 0]     :        Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
*/
class _0717_OneBitAndTwoBitsCharacters{
public:
    bool isOneBitCharacter(std::vector<int>& bits);
private:
    bool isOneBitCharacter(std::vector<int>& bits, int start, int end);
};

/*
Given a (singly) linked list with head node root, write a 
function to split the linked list into k consecutive linked 
list "parts".
The length of each part should be as equal as possible: no 
two parts should have a size differing by more than 1. This 
may lead to some parts being null.
The parts should be in order of occurrence in the input list, 
and parts occurring earlier should always have a size greater 
than or equal parts occurring later.
Return a List of ListNode's representing the linked list parts 
that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, 
root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation
 as a ListNode is [].
Example 2:
Input: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference
 at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
*/
class _0725_SplitLinkedListInParts {
public:
    std::vector<ListNode<int>*> splitListToParts(ListNode<int>* root, int k);
};

/*
A self-dividing number is a number that is divisible by every digit 
it contains.
For example, 128 is a self-dividing number 
because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
Also, a self-dividing number is not allowed to contain the digit zero.
Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
*/
class _0728_SelfDividingNumbers {
public:
    std::vector<int> selfDividingNumbers(int left, int right);
};


class _0729_MyCalendarI {
public:
    _0729_MyCalendarI();
    bool book(int start, int end);
private:
    std::vector<std::pair<int,int>> a;
    std::map<int, int> booked;              // use binary search:  |     [10        (20)]      |     [(15)    20]
    // floor:    largest entry whose key <= query key         |       [(12)   18]         |  [12    (18)]
    // ceiling:  smallest entry whose key > query key         |    floor.end > q.start    |     ceiling.start < q.end
    // Time complexity: O(nlogn)   Space complexity: O(n)
};


/*
Given two sentences words1, words2 (each represented as an array of strings), and a list of 
similar word pairs pairs, determine if two sentences are similar. For example, 
      "great acting skills" 
and 
      "fine drama talent" 
are similar, if the similar word pairs are 
pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].
Note that the similarity relation is not transitive. For example, if "great" and "fine" are 
similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.
However, similarity is symmetric. For example, "great" and "fine" being similar is the same 
as "fine" and "great" being similar. Also, a word is always similar with itself. For example, 
the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though 
there are no specified similar word pairs.
Finally, sentences can only be similar if they have the same number of words. So a sentence 
like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].
*/
class _0734_SentenceSimilarity {
public:
    bool areSentencesSimilar(std::vector<std::string>& words1, std::vector<std::string>& words2,
    std::vector<std::vector<std::string>>& pairs);
};

/*
We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents
its direction (positive meaning right, negative meaning left). Each asteroid moves
at the same speed. Find out the state of the asteroids after all collisions. If 
two asteroids meet, the smaller one will explode. If both are the same size, both 
will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5, 10, -5]           :      Output: [5, 10]

Example 2:
Input: asteroids = [8, -8]               :      Output: []

Example 3:
Input: asteroids = [10, 2, -5]           :      Output: [10]

Example 4:
Input: asteroids = [-2, -1, 1, 2]        :      Output: [-2, -1, 1, 2]
Explanation: 
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other.
*/
class _0735_AsteroidCollision {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids);
};

/*
Given an array nums of integers, you can perform operations on the array.
In each operation, you pick any nums[i] and delete it to earn nums[i] points. 
After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
You start with 0 points. Return the maximum number of points you can earn by 
applying such operations.

Input: nums = [3, 4, 2]
Output: 6
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.

Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
*/
class _0740_DeleteAndEarn {
public:
    int deleteAndEarn(std::vector<int>& nums);
};

/*
Tag: dynamic programming
In a N x N grid representing a field of cherries, each cell is 
one of three possible integers. 

0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.

Your task is to collect maximum number of cherries possible by 
following the rules below: 

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right 
or down through valid path cells (cells with value 0 or 1); 
After reaching (N-1, N-1), returning to (0, 0) by moving left or up 
through valid path cells;

When passing through a path cell containing a cherry, you pick it up 
and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no 
cherries can be collected. 


Input: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
Output: 5
Explanation: 
The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
 

Note:

grid is an N by N 2D array, with 1 <= N <= 50.
Each grid[i][j] is an integer in the set {-1, 0, 1}.
It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.
*/
class _0741_CherryPickup {
public:
    int cherryPickup(std::vector<std::vector<int>>& grid);
};

/*
Tag: dynamic programming
On a staircase, the i-th step has some non-negative cost cost[i] assigned 
(0 indexed). Once you pay the cost, you can either climb one or two steps. 
You need to find minimum cost to reach the top of the floor, and you can 
either start from the step with index 0, or the step with index 1.

Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].
*/
class _0746_MinCostClimbingStairs {
public:
    int minCostClimbingStairs(std::vector<int>& cost);
};

/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: 
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and 
wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move 
consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.
You are given a list of deadends dead ends, meaning if the lock displays any of these 
codes, the wheels of the lock will stop turning and you will be unable to open it.
Given a target representing the value of the wheels that will unlock the lock, return 
the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1
*/

class _0752_OpenTheLock {
public:
    int openLock(std::vector<std::string>& deadends, std::string target);
    int bidirectionalBFS(std::vector<std::string>& deadends, std::string target);
private:
    std::vector<std::string> nextNeighborString(std::string& key);
};

/*
We are stacking blocks to form a pyramid. Each block has a color which is a 
one letter string. We are allowed to place any color block C on top of two 
adjacent blocks of colors A and B, if and only if ABC is an allowed triple.
We start with a bottom row of bottom, represented as a single string. We also
start with a list of allowed triples allowed. Each allowed triple is represented 
as a string of length 3. 

Return true if we can build the pyramid all the way to the top, otherwise false.

Input: bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "FFF"]        :        Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  G   E
 / \ / \
B   C   D

We are allowed to place G on top of B and C because BCG is an allowed triple.
Similarly, we can place E on top of C and D, then A on top of G and E.

Input: bottom = "AABA", allowed = ["AAA", "AAB", "ABA", "ABB", "BAC"]       :      Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.

Note:

bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
*/
class _0756_PyramidTransitionMatrix {
public:
    bool pyramidTransition(std::string bottom, std::vector<std::string>& allowed);
private:
    bool pyramidTransition(std::string bottom, int start, std::string res, std::unordered_map<std::string, std::unordered_set<char>>& Map);
};

/*
Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings of S, and swapping them. (Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.)

At the end of any number of moves, what is the lexicographically largest resulting string possible?

Example 1:
Input: S = "11011000"
Output: "11100100"
Explanation:
The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
Note:

S has length at most 50.
S is guaranteed to be a special binary string as defined above.
*/
class _0761_SpecialBinaryString {
public:
    std::string makeLargestSpecial(std::string S);
    std::string makeLargestSpecialHelp(std::string S);
};

/*
A string S of lowercase letters is given. We want to partition 
this string into as many parts as possible so that each letter 
appears in at most one part, and return a list of integers 
representing the size of these parts.

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/
class _0763_PartitionLabels {
public:
    std::vector<int> partitionLabels(std::string S) ;
};

/*
Given a string S, check if the letters can be rearranged so that two characters 
that are adjacent to each other are not the same. If possible, output any possible 
result.  If not possible, return the empty string.

Input: S = "aab"
Output: "aba"

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/
class _0767_ReorganizeString {
public:
    std::string reorganizeString(std::string S);
};

/*
Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], 
we split the array into some number of "chunks" (partitions), and individually 
sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 10].
arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
*/
class _0769_MaxChunksToMakeSorted {
public:
    int maxChunksToSorted(std::vector<int>& arr);
};

/*
You're given strings J representing the types of stones that are jewels, 
and S representing the stones you have. Each character in S is a type of 
stone you have. You want to know how many of the stones you have are also 
jewels.
The letters in J are guaranteed distinct, and all characters in J and S 
are letters. Letters are case sensitive, so "a" is considered a different 
type of stone from "A".

Input: J = "aA", S = "aAAbbbb"
Output: 3

Input: J = "z", S = "ZZ"
Output: 0
Note: S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/
class _0771_JewelsAndStones {
public:
    int numJewelsInStones(std::string J, std::string S);
};

/*
Tag: math, permutation

Note: Based on the fact that if correct all local, and it is a
sorted 0~N-1, then local is the same as global

We have some permutation A of [0, 1, ..., N - 1], where N 
is the length of A.
The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].
The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].
Return true if and only if the number of global inversions is equal to the number of local inversions.

Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.

Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Note:

A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.
*/
class _0775_GlobalAndLocalInversions {
public:
    bool isIdealPermutation(std::vector<int>& A);
};

/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move 
consists of either replacing one occurrence of "XL" with "LX", or replacing one 
occurrence of "RX" with "XR". Given the starting string start and the ending string 
end, return True if and only if there exists a sequence of moves to transform one
string to the other.

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Note:

1 <= len(start) = len(end) <= 10000.
Both start and end will only consist of characters in {'L', 'R', 'X'}.
这道题由于理解错误，以为XL 和 LX 是可以互相变的， RX 和 XR 也是可以互相变的。
实际上，题目中给出的条件是 XL 只能单向变成 LX， 而 RX 只能单向变成 XR。
那么问题就变得简单了许多，这样想，如果只是单向变化，那么L在start中的位置相对于
end只能靠后，而 R 在start 中的位置相对于end只能靠前。换句话说，L 只能往前走，
而R 只能往后走。而且L, R 在两个字符串中的相对位置无法变化。
*/
class _0777_SwapAdjacentInLRString {
public:
    bool canTransform(const std::string& start, const std::string& end);
};

/*
Given an undirected graph, return true if and only if it is bipartite.
Recall that a graph is bipartite if we can split it's set of nodes into 
two independent subsets A and B such that every edge in the graph has 
one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j
for which the edge between nodes i and j exists.  Each node is an integer 
between 0 and graph.length - 1.  There are no self edges or parallel edges: 
graph[i] does not contain i, and it doesn't contain any element twice.

Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.

Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
*/
class _0785_IsGraphBipartitle {
private:
    std::vector<int> colored;
public:
    bool isBipartitle(std::vector<std::vector<int>>& graph);
    bool Color(const std::vector<std::vector<int>>& graph, int I, int color);
};

/*
Given a directed, acyclic graph of N nodes.  Find all possible paths 
from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  
graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:
The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
*/
class _0797_AllPathsFromSourceToTarget {
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph);
};

/*
We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, 
and so on until the 100th row.  Each glass holds one cup (250ml) of champagne.
Then, some champagne is poured in the first glass at the top.  When the top most glass is full, 
any excess liquid poured will fall equally to the glass immediately to the left and right of 
it.  When those glasses become full, any excess champagne will fall equally to the left and right 
of those glasses, and so on.  (A glass at the bottom row has it's excess champagne fall on the floor.)
For example, after one cup of champagne is poured, the top most glass is full.  After two cups 
of champagne are poured, the two glasses on the second row are half full.  After three cups of 
champagne are poured, those two cups become full - there are 3 full glasses total now.  After 
four cups of champagne are poured, the third row has the middle glass half full, and the two 
outside glasses are a quarter full, as pictured below.

Now after pouring some non-negative integer cups of champagne, return how full the j-th glass in 
the i-th row is (both i and j are 0 indexed.)

Input: poured = 1, query_glass = 1, query_row = 1
Output: 0.0
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.

Input: poured = 2, query_glass = 1, query_row = 1
Output: 0.5
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.
 
Note:
poured will be in the range of [0, 10 ^ 9].
query_glass and query_row will be in the range of [0, 99].
*/
class _0799_ChampagneTower {
public:
    double champagneTower(int poured, int query_row, int query_glass);
};

}

#endif