#ifndef PROBLEM_SET9_HPP
#define PROBLEM_SET9_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

namespace LeetCode {
    /*
International Morse Code defines a standard encoding where each letter is 
mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" 
maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet 
is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
"--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
"-.--","--.."]

Now, given a list of words, each word can be written as a concatenation of 
the Morse code of each letter. For example, "cba" can be written as "-.-..--...", 
(which is the concatenation "-.-." + "-..." + ".-"). We'll call such a 
concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.
*/
class _0804_UniqueMorseCodeWords {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words);
};

/*
In a 2 dimensional array grid, each value grid[i][j] represents the height of a building 
located there. We are allowed to increase the height of any number of buildings, by any 
amount (the amounts can be different for different buildings). Height 0 is considered to 
be a building as well. 
At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, 
bottom, left, and right, must be the same as the skyline of the original grid. A city's 
skyline is the outer contour of the rectangles formed by all the buildings when viewed 
from a distance. See the following example.

What is the maximum total sum that the height of the buildings can be increased?

Example:
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: 
The grid is:
[ [3, 0, 8, 4], 
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]

The skyline viewed from top or bottom is: [9, 4, 8, 7]
The skyline viewed from left or right is: [8, 7, 9, 3]

The grid after increasing the height of buildings without affecting skylines is:

gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]

Notes:
1 < grid.length = grid[0].length <= 50.
All heights grid[i][j] are in the range [0, 100].
All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.
*/
class _0807_MaxIncreaseToKeepCitySkyline {
public:
    int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid);
private:
    std::vector<int> rowMax(const std::vector<std::vector<int>>& grid);
    std::vector<int> colMax(const std::vector<std::vector<int>>& grid);
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

How many binary trees can we make?  Return the answer modulo 10 ** 9 + 7.

Input: A = [2, 4]
Output: 3
We can make these trees: [2], [4], [4, 2, 2]

Input: A = [2, 4, 5, 10]
Output: 7
We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].

Note:

1 <= A.length <= 1000.
2 <= A[i] <= 10 ^ 9.
*/
class _0823_BinaryTreeWithFactors {
public:
    int numFactoredBinaryTrees(std::vector<int>& A);
};

/*
In a string S of lowercase letters, these letters form consecutive groups of the same character.
For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
The final answer should be in lexicographic order.

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
*/
class _0830_PositionsOfLargeGroups {
public:
    std::vector<std::vector<int>> largetGroupPositions(std::string S);
};

/*
Given a binary matrix A, we want to flip the image horizontally, 
then invert it, and return the resulting image.
To flip an image horizontally means that each row of the image is 
reversed. For example, flipping [1, 1, 0] horizontally results in 
[0, 1, 1].
To invert an image means that each 0 is replaced by 1, and each 1 
is replaced by 0. For example, inverting [0, 1, 1] results in 
[1, 0, 0].

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
*/
class _0832_FlippingAnImage {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A);
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
 838 Push Dominoes
There are N dominoes in a line, and we place each domino vertically upright.
In the beginning, we simultaneously push some of the dominoes either to the 
left or to the right. After each second, each domino that is falling to the 
left pushes the adjacent domino on the left. Similarly, the dominoes falling 
to the right push their adjacent dominoes standing on the right.
When a vertical domino has dominoes falling on it from both sides, it stays 
still due to the balance of the forces. For the purposes of this question, 
we will consider that a falling domino expends no additional force to a 
falling or already fallen domino.
Given a string "S" representing the initial state. S[i] = 'L', if the i-th 
domino has been pushed to the left; S[i] = 'R', if the i-th domino has been 
pushed to the right; S[i] = '.', if the i-th domino has not been pushed.

Return a string representing the final state. 

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Note:
    0 <= N <= 10^5
    String dominoes contains only 'L', 'R' and '.'
*/
class _0838_PushDominoes {
  public:
    std::string pushDominoes(std::string dominoes);
};


/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.
For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, 
but "star" is not similar to "tars", "rats", or "arts".
Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that 
"tars" and "arts" are in the same group even though they are not similar. Formally, each group is such that a 
word is in the group if and only if it is similar to at least one other word in the group.

We are given a list A of strings.  Every string in A is an anagram of every other string in A. 
How many groups are there?

Input: A = ["tars","rats","arts","star"]
Output: 2

Constraints:
1 <= A.length <= 2000
1 <= A[i].length <= 1000
A.length * A[i].length <= 20000
All words in A consist of lowercase letters only.
All words in A have the same length and are anagrams of each other.
The judging time limit has been increased for this question.
*/
class _0839_SimilarStringGroups {
public:
    int numSimilarGroups(std::vector<std::string>& A);
private:
    bool areSimilar(const std::string& a, const std::string& b);
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
Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that 
A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that 
A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Input: [0,1,0]
Output: 1

Input: [0,2,1,0]
Output: 1
Note:

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.
*/
class _0852_PeakIndexInAMountainArray {
public:
    int peakIndexInMountainArray(std::vector<int>& A);
};

/*
We have a two dimensional matrix A where each value is 0 or 1.
A move consists of choosing any row or column, and toggling each 
value in that row or column: changing all 0s to 1s, and all 1s to 0s.
After making any number of moves, every row of this matrix is 
interpreted as a binary number, and the score of the matrix is the 
sum of these numbers.
Return the highest possible score.

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

Note:
1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] is 0 or 1.
*/
class _0861_ScoreAfterFlippingMatrix {
public:
    int matrixScore(std::vector<std::vector<int>>& A);
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
A robot on an infinite grid starts at point (0, 0) and faces 
north. The robot can receive one of three possible types of 
commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. 

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])
If the robot would try to move onto them, the robot stays on the 
previous grid square instead (but still continues following the 
rest of the route.)
Return the square of the maximum Euclidean distance that the robot 
will be from the origin.

Input: commands = [4,-1,3], obstacles = []    :    Output: 25
Explanation: robot will go to (3, 4)

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]    :   Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
*/
class _0874_WalkingRobotSimulation {
public:
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles);
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
Given a non-empty, singly linked list with head node head, return a middle node of 
linked list. If there are two middle nodes, return the second middle node.

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
*/
class _0876_MiddleOfTheLinkedList {
public:
    ListNode<int>* middleNode(ListNode<int>* head);
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
On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the 
x, y, and z axes. Each value v = grid[i][j] represents a tower of v cubes 
placed on top of grid cell (i, j). Now we view the projection of these 
cubes onto the xy, yz, and zx planes. 
A projection is like a shadow, that maps our 3 dimensional figure to a 2 
dimensional plane. Here, we are viewing the "shadow" when looking at the 
cubes from the top, the front, and the side.
Return the total area of all three projections.

Input: [[2]]
Output: 5

Input: [[1,2],[3,4]]
Output: 17
Explanation: 
Here are the three projections ("shadows") of the shape made with each axis-aligned plane.
*/
class _0883_ProjectionAreaOf3DShapes {
public:
    int projectionArea(std::vector<std::vector<int>>& grid);
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