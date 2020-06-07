#ifndef PROBLEM_SET4_HPP
#define PROBLEM_SET4_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"
namespace LeetCode {
    /*
A binary watch has 4 LEDs on the top which represent
the hours (0-11), and the 6 LEDs on the bottom represent
the minutes (0-59).

Each LED represents a zero or one, with the least significant
bit on the right.

For example, the above binary watch reads "3:25".
Given a non-negative integer n which represents the number of
LEDs that are currently on, return all possible times the watch
could represent.

Example:
    Input: n = 1
    Return: ["1:00", "2:00", "4:00", "8:00", "0:01", 
            "0:02", "0:04", "0:08", "0:16", "0:32"]

Note:
    The order of output does not matter.
    The hour must not contain a leading zero, for example "01:00"
    is not valid, it should be "1:00". The minute must be consist 
    of two digits and may contain a leading zero, for example 
    "10:2" is not valid, it should be "10:02".

Solution: 
    Thinking about it in the forward way is difficult, it is better 
    to think about it in an inverse way:
    There are total 12 * 60 combinations, why not enum them one by one 
    and pick up all satisfied items:
*/
class _0401_BinaryWatch
{
public:
    std::vector<std::string> readBinaryWatch(int num);
};

class _0404_SumOfLeftLeaves
{
public:
    int sumOfLeftLeaves(TreeNode<int> *root);
};


/*
Given a non-negative integer num represented as a string, remove k digits 
from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/
class _0402_RemoveKDigits {
private:
    std::string removeHeadZeros(std::string num);
public:
    std::string removeKdigits(std::string num, int k);
    std::string removeOnedig(std::string num);
};


/*
Given an integer, write an algorithm to convert it to hexadecimal. For 
negative integer, two’s complement method is used.
All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is 
zero, it is represented by a single zero character '0'; otherwise, the first 
character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed 
integer.
You must not use any method provided by the library which converts/formats 
the number to hex directly.
Input:  26         Output:  "1a"
Input:  -1         Output:  "ffffffff"
*/
class _0405_ConvertANumberToHexadecimal{
public:
    std::string toHex(int num);
};

class _0406_QueueReconstructionByHeight {
    public:
        std::vector<std::pair<int, int>> reconstructQueue(std::vector<std::pair<int, int>>& people);
};

class _0409_LongestPalindrome {
public:
    int longestPalindrome(std::string s);
};

class _0412_FizzBuzz {
public:
    std::vector<std::string> fizzBuzz(int n);
};
 
class _0413_ArighmeticSlices {
public:
    int numberOfArithmeticSlices(std::vector<int>& A);
private:
    int numberOfSubArith(int N);
};
 
class _0414_ThirdMaximumNumber{
public:
    int thirdMax(std::vector<int>& nums);
};

/*
Facebook

Tag: string operation, math

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class _0415_AddStrings {
public:
    std::string addStrings(std::string num1, std::string num2);
};

/*
Given a non-empty array containing only positive integers, find if the array 
can be partitioned into two subsets such that the sum of elements in both 
subsets is equal.
Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.

Example 1:
Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
 
Example 2:
Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/
class _0416_PartitionEqualSubsetSum {
public:
    bool canPartition(std::vector<int>& nums);
};

/*
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
*/
class _0419_BattleshipsInABoard{
public:
    int countBattleships(std::vector<std::vector<char>>& board);
};

// We want to use quad trees to store an N x N boolean grid. Each cell in the
// grid can only be true or false. The root node represents the whole grid. For
// each node, it will be subdivided into four children nodes until the values in
// the region it represents are all the same.
// Each node has another two boolean attributes : isLeaf and val. isLeaf is true
// if and only if the node is a leaf node. The valattribute for a leaf node contains
// the value of the region it represents.
// Your task is to use a quad tree to represent a given grid.

// 这是一道比较简单的题目，主要注意点就是先判断一个矩阵中的值是否一致，在看分隔中是否一致
class _0427_ConstructQuadTree
{
public:
    QuadTreeNode *construct(std::vector<std::vector<int>> &grid);
    QuadTreeNode *construct(std::vector<std::vector<int>> &grid,
                            int rowStart, int rowEnd, int colStart, int colEnd);

private:
    bool areConsistent(std::vector<std::vector<int>> &grid);
    bool areConsistent(std::vector<std::vector<int>> &grid,
                       int rowStart, int rowEnd, int colStart, int colEnd);

    std::vector<std::vector<std::vector<int>>> divideGrid(std::vector<std::vector<int>> &grid);
};

/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/
class _0423_ReconstructOriginalDigitFromEnglish {
public:
    std::string originalDigits(std::string s);
};

/*
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.
You can think of the left and right pointers as synonymous to the predecessor 
and successor pointers in a doubly-linked list. For a circular doubly linked list, 
the predecessor of the first element is the last element, and the successor of 
the last element is the first element.
We want to do the transformation in place. After the transformation, the left 
pointer of the tree node should point to its predecessor, and the right pointer 
should point to its successor. You should return the pointer to the smallest 
element of the linked list.

Input: root = [4,2,5,1,3]
Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST. The solid line indicates 
the successor relationship, while the dashed line means the predecessor relationship.

Input: root = [2,1,3]
Output: [1,2,3]

Input: root = []
Output: []
Explanation: Input is an empty tree. Output is also an empty Linked List.

Input: root = [1]
Output: [1]
 

Constraints:

-1000 <= Node.val <= 1000
Node.left.val < Node.val < Node.right.val
All values of Node.val are unique.
0 <= Number of Nodes <= 2000
*/
class _0426_ConvertBinarySearchTreeToSortedDoublyLinkedList {
public:
    struct Node {
        int val;
        Node* left;
        Node* right;
    };
    Node* treeToDoublyList(Node* root);
private:
    std::pair<Node*, Node*> conn(Node* root);
};

/*
Given an n-ary tree, return the level order traversal 
of its nodes' values. (ie, from left to right, level by level).

For example, given a 3-ary tree:
    We should return its level order traversal:
    [
        [1],
        [3,2,4],
        [5,6]
    ]
Note:
    The depth of the tree is at most 1000.
    The total number of nodes is at most 5000.
*/
class _0429_NaryTreelevelOrderTraversal
{
public:
    std::vector<std::vector<int>> levelOrder(NaryTreeNode<int> *root);
};

/*
You are given a doubly linked list which in addition to the next and 
previous pointers, it could have a child pointer, which may or may not 
point to a separate doubly linked list. These child lists may have one
or more children of their own, and so on, to produce a multilevel data
 structure, as shown in the example below.
Flatten the list so that all the nodes appear in a single-level, doubly 
linked list. You are given the head of the first level of the list.

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:
After flattening the multilevel linked list it becomes:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL

Input: head = []
Output: []
How multilevel linked list is represented in test case:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
Constraints:
Number of Nodes will not exceed 1000.
1 <= Node.val <= 10^5
*/
class _0430_FlattenAMultilevelDoublyLinkedList {
    class Node{
        public:
            int val;
            Node* prev;
            Node* next;
            Node* child;
    };
public:
    Node* flatten(Node* head);
};

/*
A gene string can be represented by an 8-character long string, with choices 
from "A", "C", "G", "T". Suppose we need to investigate about a mutation 
(mutation from "start" to "end"), where ONE mutation is defined as ONE single 
character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
Also, there is a given gene "bank", which records all the valid gene mutations. 
A gene must be in the bank to make it a valid gene string.
Now, given 3 things - start, end, bank, your task is to determine what is the 
minimum number of mutations needed to mutate from "start" to "end". If there 
is no such a mutation, return -1.

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]
return: 1
 
start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
return: 2

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
return: 3
*/
class _0433_MinimumGeneticMutation {
public:
    int minMutation(std::string start, std::string end, std::vector<std::string>& bank);
};

class _0434_NumberOfSegmentsInAString {
public:
    int countSegments(std::string s);
};

/*
Given a collection of intervals, find the minimum number of intervals you need
to remove to make the rest of the intervals non-overlapping.

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
*/
class _0435_NonOverlappingIntervals {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals);
};

class _0437_PathSumIII {
    
};

/*

Facebook

Tag: hash, string

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p 
will not be larger than 20,100. The order of output does not matter.

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
class _0438_FindAllAnagramsInAString {
public:
    std::vector<int> findAnagrams(std::string s, std::string p);
};

class _0441_ArrangingCoins {
public:
    int arrangeCoins(int n);
};

class _0442_FindAllDuplicatesInAnArray {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums);
};

/*
Given n points in the plane that are all pairwise distinct, a 
"boomerang" is a tuple of points (i, j, k) such that the distance between 
i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and 
coordinates of points are all in the range [-10000, 10000] (inclusive).
Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2
Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/
class _0447_NumberOfBoomerangs {
public:
    int numberOfBoomerangs(std::vector<std::vector<int>>& points);
};

/*
Serialization is the process of converting a data structure or object 
into a sequence of bits so that it can be stored in a file or memory 
buffer, or transmitted across a network connection link to be 
reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. 
There is no restriction on how your serialization/deserialization 
algorithm should work. You just need to ensure that a binary search 
tree can be serialized to a string and this string can be deserialized 
to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. 
Your serialize and deserialize algorithms should be stateless.
*/
class _0449_SerializeAndDeserializeBST {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode<int>* root) {
        std::string s;
        serialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode<int>* deserialize(std::string data) {
        int pos = 0;
        return deserialize(data, pos, INT_MIN, INT_MAX);
    }

private:
    void serialize(TreeNode<int>* root, std::string& s) {
        if(!root) {
            return;
        }
        s.append(reinterpret_cast<const char*>(&root->val), sizeof(root->val));
        serialize(root->left, s);
        serialize(root->right, s);
    }
    
    TreeNode<int>* deserialize(const std::string& s, int& pos, int curMin, int curMax) {
        if(pos >= s.size()) {
            return nullptr;
        }
        int val = *reinterpret_cast<const int*>(s.data() + pos);
        if(val < curMin || val > curMax) {
            return nullptr;
        }
        pos += sizeof(val);
        TreeNode<int>* root = new TreeNode<int>(val);
        root->left = deserialize(s, pos, curMin, val);
        root->right = deserialize(s, pos, val, curMax);
        return root;
    }
};

/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
class _0451_SortCharactersByFrequency {
public:
    std::string frequencySort(std::string s);
};


/*
There are a number of spherical balloons spread in two-dimensional space. 
For each balloon, provided input is the start and end coordinates of the 
horizontal diameter. Since it's horizontal, y-coordinates don't matter 
and hence the x-coordinates of start and end of the diameter suffice. Start 
is always smaller than end. There will be at most 104 balloons.
An arrow can be shot up exactly vertically from different points along the 
x-axis. A balloon with xstart and xend bursts by an arrow shot at x if 
xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be 
shot. An arrow once shot keeps travelling up infinitely. The problem is to 
find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input: [[10,16], [2,8], [1,6], [7,12]] :   Output:  2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
*/
class _0452_MinimumNumberOfArrowsToBusrtBalloons {
    public:
        int findMinArrowShots(std::vector<std::vector<int>>& points);
};

/*
Assume you are an awesome parent and want to give your children some cookies. 
But, you should give each child at most one cookie. Each child i has a greed 
factor gi, which is the minimum size of a cookie that the child will be content 
with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie 
j to the child i, and the child i will be content. Your goal is to maximize 
the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.

Input: [1,2,3], [1,1]
Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children 
are 1, 2, 3. And even though you have 2 cookies, since their size is both 1, 
you could only make the child whose greed factor is 1 content. 
You need to output 1.

Input: [1,2], [1,2,3]
Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
*/
class _0455_AssignCookies {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s);
};

/*
There are 1000 buckets, one and only one of them is poisonous, while the rest are 
filled with water. They all look identical. If a pig drinks the poison it will die 
within 15 minutes. What is the minimum amount of pigs you need to figure out which 
bucket is poisonous within one hour?

Answer this question, and write an algorithm for the general case.
General case:
If there are n buckets and a pig drinking poison will die within m minutes, how many 
pigs (x) you need to figure out the poisonous bucket within p minutes? There is 
exactly one bucket with poison.
Note:

A pig can be allowed to drink simultaneously on as many buckets as one would like, 
and the feeding takes no time. After a pig has instantly finished drinking buckets, 
there has to be a cool down time of m minutes. During this time, only observation is 
allowed and no feedings at all. Any given bucket can be sampled an infinite number of 
times (by an unlimited number of pigs).
*/
class _0458_PoorPigs {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest);
};

/*
The Hamming distance between two integers is the number of positions at which the 
corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.
Example:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
*/
class _0461_HammingDistance {
public:
    int hammingDistance(int x, int y);
};

/*
In the "100 game," two players take turns adding, to a running total, any 
integer from 1..10. The player who first causes the running total to reach 
or exceed 100 wins.
What if we change the game so that players cannot re-use integers?
For example, two players might take turns drawing from a common pool of 
numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, 
determine if the first player to move can force a win, assuming both 
players play optimally.

You can always assume that maxChoosableInteger will not be larger than 
20 and desiredTotal will not be larger than 300.

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers 
from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is 
>= desiredTotal. Same with other integers chosen by the first player, the 
second player will always win.
*/
class _0464_CanIWin {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal);
private:
    std::vector<char> m_; //
    bool canIWin(int M, int T, int state);
};

/*
Remember the story of Little Match Girl? By now, you know exactly what matchsticks 
the little match girl has, please find out a way you can make one square by using 
up all those matchsticks. You should not break any stick, but you can link them up, 
and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick 
length. Your output will either be true or false, to represent whether you could 
make one square using all the matchsticks the little match girl has.

Input: [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Input: [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
*/
class _0473_MatchsticksToSquare {
public:
    bool makesquare(std::vector<int>& nums);
private:
    bool DFS(std::vector<int>& nums, int startidx, std::vector<int>& edges, const int EDGE);
};

/*
Given a positive integer, output its complement number. The complement strategy 
is to flip the bits of its binary representation.

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 
Note:

The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
*/
class _0476_NumberComplement {
public:
    int findComplement(int num);
};

/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
*/
class _0477_TotalHammingDistance {
public:
    int totalHammingDistance(std::vector<int>& nums);
};

/*
A magical string S consists of only '1' and '2' and obeys the following rules:
The string S is magical because concatenating the number of contiguous occurrences 
of characters '1' and '2' generates the string S itself.
The first few elements of string S is the following: S = 
"1221121221221121122……"
If we group the consecutive '1's and '2's in S, it will be:
1 22 11 2 1 22 1 22 11 2 11 22 ......
and the occurrences of '1's or '2's in each group are:
1 2 2 1 1 2 1 2 2 1 2 2 ......
You can see that the occurrence sequence above is the S itself.
Given an integer N as input, return the number of '1's in the first N number in the magical string S.
Note: N will not exceed 100,000.
Example 1:
Input: 6
Output: 3
Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.
*/
class _0481_MagicalString {
public:
    int magicalString(int n);
};


/*
You are given a license key represented as a string S which consists only alphanumeric character and dashes. 
The string is separated into N+1 groups by N dashes.
Given a number K, we would want to reformat the strings such that each group contains exactly K characters, 
except for the first group which could be shorter than K, but still must contain at least one character. 
Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.

Example 1:
Input: S = "5F3Z-2e-9-w", K = 4
Output: "5F3Z-2E9W"

Explanation: The string S has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.
Example 2:
Input: S = "2-5g-3-J", K = 2
Output: "2-5G-3J"

Explanation: The string S has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
Note:
The length of string S will not exceed 12,000, and K is a positive integer.
String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
String S is non-empty.
*/
class _0482_LicenseKeyFormatting {
public:
    std::string licenseKeyFormatting(std::string S, int K);
};

/*
Tag: preSum, probability theory
Given a list of non-overlapping axis-aligned rectangles rects, write a 
function pick which randomly and uniformily picks an integer point in 
the space covered by the rectangles.

An integer point is a point that has integer coordinates. 
A point on the perimeter of a rectangle is included in the space covered 
by the rectangles. 
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer 
coordinates of the bottom-left corner, and [x2, y2] are the integer 
coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.
Example 1:

Input: 
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output: 
[null,[4,1],[4,1],[3,3]]

Input: 
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output: 
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array of rectangles rects. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.
*/
class _0497_RandomPointinNonoverlappingRectangles {
private:
    std::vector<std::vector<int>> rects;
public:
    _0497_RandomPointinNonoverlappingRectangles(std::vector<std::vector<int>>& rects) : rects(rects){}
    std::vector<int> pick(); 
};

/*
498. Diagonal Traverse
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]
The total number of elements of the given matrix will not exceed 10,000.
*/
class _0498_DiagonalTraverse {
    public:
        std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix);
};


}

#endif