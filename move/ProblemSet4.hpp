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


class _0413_ArighmeticSlices {
public:
    int numberOfArithmeticSlices(std::vector<int>& A);
private:
    int numberOfSubArith(int N);
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
class _0419_BattleshipsInABoard {
public:
    int countBattleships(std::vector<std::vector<char>>& board);
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
Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).

There are at least 3 and at most 10,000 points.
Coordinates are in the range -10,000 to 10,000.
You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). 
In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.

[[0,0],[0,1],[1,1],[1,0]]
Answer: True
Explanation:

[[0,0],[0,10],[10,10],[10,0],[5,5]]
Answer: False
Explanation:
*/
class _0469_ConvexPolygon {
public:
    bool isConvex(std::vector<std::vector<int>>& points);
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
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up,
down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the 
borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.


Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true

Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.


Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false

Explanation: There is no way for the ball to stop at the destination.

Note:

There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/
class _0490_TheMaze {
private:
    int M;
    int N;
    int di;
    int dj;
    int dirs[5] = {0, -1, 0, 1, 0};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination);
    bool hasPath(std::vector<std::vector<int>>& maze, int i, int j);
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



}

#endif