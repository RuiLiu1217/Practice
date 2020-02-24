#ifndef PROBLEM_SET13_HPP
#define PROBLEM_SET13_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include "Tree.hpp"
#include "LinkList.hpp"
namespace LeetCode {
    /*
Write a program to find the n-th ugly number.
Ugly numbers are positive integers which are divisible by a or b or c.

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
Example 2:

Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
Example 3:

Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
Example 4:

Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
Output: 1999999984

Constraints:
1 <= n, a, b, c <= 10^9
1 <= a * b * c <= 10^18
It's guaranteed that the result will be in range [1, 2 * 10^9]
*/
class _1201_UglyNumberIII {
public:
    // it looks like a DP problem, but actually it is a Binary Search Problem
    // Calculate how many numbers from 1 to num are divisble by either a, b or c
    // using the formula:
    // num / a + num / b + num / c - num / lcm(ab) - num / lcm(bc) - num / lcm(ac) + num / lcm(abc)
    int nthUglyNumber(int n, int a, int b, int c);
private:
    long long gcb(long long a, long long b);
    long long lcm(long long a, long long b);
    int count(long long num, long long a, long long b, long long c);
};

/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = 
[a, b] indicates 2 indices(0-indexed) of the string. You can swap the characters at any pair of 
indices in the given pairs any number of times.
Return the lexicographically smallest string that s can be changed to after using the swaps.

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/
class _1202_SmallestStringWithSwaps {
public:
    std::string smallestStringWithSwaps(std::string s, std::vector<std::vector<int>>& pairs);
};

/*
Given an array of integers arr, write a function that returns true if and only if the 
number of occurrences of each value in the array is unique.

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the 
same number of occurrences.

Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
*/
class _1207_UniqueNumberOfOccurances {
public:
    bool uniqueOccurrences(std::vector<int>& arr);
};


/*
Hint: 祖玛
Given a string s, a k duplicate removal consists of choosing k adjacent and 
equal letters from s and removing them causing the left and the right side 
of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made.
It is guaranteed that the answer is unique.

Input: s = "abcd", k = 2                  :                Output: "abcd"
Input: s = "deeedbbcccbdaa", k = 3        :                Output: "aa"
Input: s = "pbbcggttciiippooaais", k = 2  :                Output: "ps"

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
*/
class _1209_RemoveAllAdjacentDuplicatesInStringII {
public:
    std::string removeDuplicates(std::string s, int k);
};

/*
Given two binary search trees, return True if and only if 
there is a node in the first tree and a node in the second 
tree whose values sum up to a given integer target.

Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false

Constraints:

Each tree has at most 5000 nodes.
-10^9 <= target, node.val <= 10^9
*/
class _1214_TwoSumBSTs{
public:
    bool twoSumBSTs(TreeNode<int>* root1, TreeNode<int>* root2, int target);
};

/*
Given an integer array arr and an integer difference, return the length of the 
longest subsequence in arr which is an arithmetic sequence such that the 
difference between adjacent elements in the subsequence equals difference.

Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
 
Constraints:

1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4
*/
class _1218_LongestArithmeticSubsequenceOfGivenDifference {
public:
    int longestSubsequence(std::vector<int>& arr, int difference);
};

/*
Split a String in Balanced Strings
Balanced strings are those who have equal quantity of 'L' and 'R' characters.
Given a balanced string s split it in the maximum amount of balanced strings.
Return the maximum amount of splitted balanced strings.

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'

Constraints:
1 <= s.length <= 1000
s[i] = 'L' or 'R'
*/
class _1221_SplitAStringInBalancedStrings {
public:
    int balancedStringSplit(std::string s);
};


/*
On an 8x8 chessboard, there can be multiple Black Queens and one White King.
Given an array of integer coordinates queens that represents the positions of the 
Black Queens, and a pair of coordinates king that represent the position of the 
White King, return the coordinates of all the queens (in any order) that can 
attack the King.


Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
Output: [[0,1],[1,0],[3,3]]
Explanation:  
The queen at [0,1] can attack the king cause they're in the same row. 
The queen at [1,0] can attack the king cause they're in the same column. 
The queen at [3,3] can attack the king cause they're in the same diagnal. 
The queen at [0,4] can't attack the king cause it's blocked by the queen at [0,1]. 
The queen at [4,0] can't attack the king cause it's blocked by the queen at [1,0]. 
The queen at [2,4] can't attack the king cause it's not in the same row/column/diagnal as the king.

Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
Output: [[2,2],[3,4],[4,4]]

Input: queens = [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],
[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],
[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]], king = [3,4]
Output: [[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
 

Constraints:

1 <= queens.length <= 63
queens[0].length == 2
0 <= queens[i][j] < 8
king.length == 2
0 <= king[0], king[1] < 8
At most one piece is allowed in a cell.
*/
class _1222_QueensThatCanAttackTheKing {
public:
    std::vector<std::vector<int>> queensAttackTheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king);
};

/*
n passengers board an airplane with exactly n seats. The first passenger has 
lost the ticket and picks a seat randomly. But after that, the rest of 
passengers will:

Take their own seat if it is still available, 
Pick other seats randomly when they find their seat occupied 
What is the probability that the n-th person can get his own seat?

Input: n = 1                   :             Output: 1.00000
Input: n = 2                   ：            Output: 0.50000
Explanation: The second person has a probability of 0.5 to get the second 
seat (when first person gets the first seat).
*/
class _1227_AirplaneSeatAssignmentProbability {
public:
    double nthPersionGetsNthSeat(int n);
};


/*
You are given an array coordinates, coordinates[i] = [x, y], 
where [x, y] represents the coordinate of a point. Check if 
these points make a straight line in the XY plane.

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:
2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/
class _1232_CheckIfItIsAStraightLine {
public:
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates);
};

/*
Given a function  f(x, y) and a value z, return all positive integer pairs x and y where f(x,y) == z.
The function is constantly increasing, i.e.:
f(x, y) < f(x + 1, y)
f(x, y) < f(x, y + 1)
The function interface is defined like this:
interface CustomFunction {
public:
  // Returns positive integer f(x, y) for any given positive integer x and y.
  int f(int x, int y);
};
For custom testing purposes you're given an integer function_id and a target z as input, where 
function_id represent one function from an secret internal list, on the examples you'll know only two 
functions from the list.

You may return the solutions in any order.

Input: function_id = 1, z = 5
Output: [[1,4],[2,3],[3,2],[4,1]]
Explanation: function_id = 1 means that f(x, y) = x + y

Input: function_id = 2, z = 5
Output: [[1,5],[5,1]]
Explanation: function_id = 2 means that f(x, y) = x * y

Constraints:

1 <= function_id <= 9
1 <= z <= 100
It's guaranteed that the solutions of f(x, y) == z will be on the range 1 <= x, y <= 1000
It's also guaranteed that f(x, y) will fit in 32 bit signed integer if 1 <= x, y <= 1000
*/
class _1237_FindPositiveIntegerSolutionForAGivenEquation {
public:
    class CustomFunction;
    std::vector<std::vector<int>> findSolution(CustomFunction& customfunction, int z);
};

/*
1238. Circular Permutation in Binary Representation 
Given 2 integers n and start. Your task is return any permutation p of (0,1,2.....,2^n -1) such that :
    p[0] = start
    p[i] and p[i+1] differ by only one bit in their binary representation.
    p[0] and p[2^n -1] must also differ by only one bit in their binary representation.

Input: n = 2, start = 3
Output: [3,2,0,1]
Explanation: The binary representation of the permutation is (11,10,00,01). 
All the adjacent element differ by one bit. Another valid permutation is [3,1,0,2]

Input: n = 3, start = 2
Output: [2,6,7,5,4,0,1,3]
Explanation: The binary representation of the permutation is (010,110,111,101,100,000,001,011).

Constraints:

    1 <= n <= 16
    0 <= start < 2 ^ n
*/
class _1238_CicularPermutationInBinaryRepresentation {
  public:
    std::vector<int> circularPermutation(int n, int start);
  private:
    std::vector<int> grayVector(int n);
};

/*
You are given two strings s1 and s2 of equal length consisting of 
letters "x" and "y" only. Your task is to make these two strings 
equal to each other. You can swap any two characters that belong 
to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, 
or return -1 if it is impossible to do so.

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: 
Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: 
Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.

Input: s1 = "xx", s2 = "xy"
Output: -1

Input: s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
Output: 4

Constraints:

1 <= s1.length, s2.length <= 1000
s1, s2 only contain 'x' or 'y'.
*/
class _1247_MinimumSwapsToMakeStringsEqual {
public:
    int minimumSwap(std::string s1, std::string s2);
};

/*
Tag: Number theory
Given an array nums of positive integers. Your task is to 
select some subset of nums, multiply each element by an 
integer and add all these numbers. The array is said to 
be good if you can obtain a sum of 1 from the array by 
any possible subset and multiplicand.

Return True if the array is good otherwise return False.

Input: nums = [12,5,7,23]
Output: true
Explanation: Pick numbers 5 and 7.
5*3 + 7*(-2) = 1

Input: nums = [29,6,10]
Output: true
Explanation: Pick numbers 29, 6 and 10.
29*1 + 6*(-3) + 10*(-1) = 1

Input: nums = [3,6]
Output: false

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/
class _1250_CheckIfItIsAGoodArray {
public:
    bool isGoodArray(std::vector<int>& nums);
private:
    int gcd(int a, int b);
};

/*
Given n and m which are the dimensions of a matrix 
initialized by zeros and given an array indices 
where indices[i] = [ri, ci]. For each pair of [ri, ci] 
you have to increment all cells in row ri and 
column ci by 1.
Return the number of cells with odd values in the matrix 
after applying the increment to all indices. 

Input: n = 2, m = 3, indices = [[0,1],[1,1]]
Output: 6
Explanation: Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.

Input: n = 2, m = 2, indices = [[1,1],[0,0]]
Output: 0
Explanation: Final matrix = [[2,2],[2,2]]. There is no odd number in the final matrix.
*/
class _1252_CellsWithOddValuesInAMatrix {
public:
    int oddCells(int n, int m, std::vector<std::vector<int>>& indices);
};


/*
1254 Number of closed islands
     Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally 
connected group of 0s and a closed island is an island totally (all left, top, right, bottom) 
surrounded by 1s.

Return the number of closed islands.

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

Constraints:

    1 <= grid.length, grid[0].length <= 100
    0 <= grid[i][j] <=1
*/
class _1254_NumberOfClosedIslands {
    int M;
    int N;
    int count;
  public:
    int closedIsland(std::vector<std::vector<int>>& grid);
    void DFS(std::vector<std::vector<int>>& grid, int I, int J, bool& touchEdge);
};

/*
Given a list of words, list of  single letters (might be repeating) and score of every 
character. Return the maximum score of any valid set of words formed by using the given 
letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used 
once. Score of letters 'a', 'b', 'c', ... ,'z' is given by 
score[0], score[1], ... , score[25] respectively.

Input: 
words = ["dog","cat","dad","good"], 
letters = ["a","a","c","d","d","d","g","o","o"], 
score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.

Example 2:
Input: 
words = ["xxxz","ax","bx","cx"], 
letters = ["z","a","b","c","x","x","x"], 
score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
Output: 27
Explanation:
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.

Example 3:
Input: 
words = ["leetcode"], 
letters = ["l","e","t","c","o","d"], 
score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
Output: 0
Explanation:
Letter "e" can only be used once.
 
Constraints:
1 <= words.length <= 14
1 <= words[i].length <= 15
1 <= letters.length <= 100
letters[i].length == 1
score.length == 26
0 <= score[i] <= 10
words[i], letters[i] contains only lower case English letters.
*/
class _1255_MaximumScoreWordsFormedByLetters {
private:
    int maxScore = 0;
public:
    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score);
private:
    int getWordScore(const std::vector<int>& word, const std::vector<int>& score);    
    bool canCreateAWord(const std::vector<int>& letterMap, const std::vector<int>& word);    
    void createAWord(std::vector<int>& letterMap, const std::vector<int>& word);    
    void removeAWord(std::vector<int>& letterMap, const std::vector<int>& word);    
    bool noMoreWordsCanGenerated(const std::vector<std::vector<int>>& words,int startIdx, const std::vector<int>& letterMap);
    void scoreWords(std::vector<std::vector<int>>& words, int startIdx, std::vector<int>& letterMap,
                   std::vector<int>& score, int& myScore);
};

/*
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
In one shift operation:
    Element at grid[i][j] becomes at grid[i][j + 1].
    Element at grid[i][n - 1] becomes at grid[i + 1][0].
    Element at grid[n - 1][n - 1] becomes at grid[0][0].
Return the 2D grid after applying shift operation k times.

Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]

Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 50
1 <= n <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100
*/
class _1260_Shift2DGrid {
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int K);        
};

/*
Given a binary tree with the following rules:
root.val == 0
If treeNode.val == x and treeNode.left != null, 
then treeNode.left.val == 2 * x + 1
If treeNode.val == x and treeNode.right != null, 
then treeNode.right.val == 2 * x + 2

Now the binary tree is contaminated, which means all 
treeNode.val have been changed to -1.

You need to first recover the binary tree and then 
implement the FindElements class:

FindElements(TreeNode* root) Initializes the object 
with a contamined binary tree, you need to recover it 
first.
bool find(int target) Return if the target value 
exists in the recovered binary tree.
 
Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True 

Example 2:
Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False


Example 3:
Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True

Constraints:

TreeNode.val == -1
The height of the binary tree is less than or equal to 20
The total number of nodes is between [1, 10^4]
Total calls of find() is between [1, 10^4]
0 <= target <= 10^6
*/
class _1261_FindElementsInAContaminatedBinaryTree {
    TreeNode<int>* rot;
    std::unordered_set<int> res;
public:
    _1261_FindElementsInAContaminatedBinaryTree(TreeNode<int>* root);
    bool find(int target);
    void recover(TreeNode<int>* root);
};

/*
On a plane there are n points with integer coordinates 
points[i] = [xi, yi]. Your task is to find the minimum 
time in seconds to visit all points.

You can move according to the next rules:
1. In one second always you can either move vertically, 
horizontally by one unit or diagonally (it means to move 
one unit vertically and one unit horizontally in 
one second).
2. You have to visit the points in the same order as 
they appear in the array. 
*/
class _1266_MinimumTimeVisitingAllPoints {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points);
};


/*
You are given a map of a server center, represented as a m * n integer matrix grid, 
where 1 means that on that cell there is a server and 0 means that it is no server. 
Two servers are said to communicate if they are on the same row or on the same column.
Return the number of servers that communicate with any other server.

Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.

Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. 
The two servers in the third column can communicate with each other. The server 
at right bottom corner can't communicate with any other server.
*/
class _1267_CountServersThatCommunicate {
public:
    int countServers(std::vector<std::vector<int>>& grid);
};

/*
You have a pointer at index 0 in an array of size arrLen. 
At each step, you can move 1 position to the left, 1 position 
to the right in the array or stay in the same place  
(The pointer should not be placed outside the array at any time).
Given two integers steps and arrLen, return the number of ways 
such that your pointer still at index 0 after exactly steps steps.

Since the answer may be too large, return it modulo 10^9 + 7.

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay

Input: steps = 4, arrLen = 2
Output: 8

Constraints:

1 <= steps <= 500
1 <= arrLen <= 10^6
*/
class _1269_NumberOfWaysToStayInTheSamePlaceAfterSomeSteps {
private:
    int MOD = (1000000000 + 7);
    void updateDP(std::vector<long long>& cur, std::vector<long long>& nex, const int N);
public:
    int numWays(int steps, int arrLen);
};

/*
Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:
Jumbo Burger: 4 tomato slices and 1 cheese slice.
Small Burger: 2 Tomato slices and 1 cheese slice.
Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the 
number of remaining cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices 
and cheeseSlices equal to 0 return [].

Input: tomatoSlices = 16, cheeseSlices = 7
Output: [1,6]
Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 
cheese. There will be no remaining ingredients.

Input: tomatoSlices = 17, cheeseSlices = 4
Output: []
Explantion: There will be no way to use all ingredients to make small and jumbo burgers.

Input: tomatoSlices = 4, cheeseSlices = 17
Output: []
Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there 
will be 15 cheese remaining.

Input: tomatoSlices = 0, cheeseSlices = 0
Output: [0,0]

Input: tomatoSlices = 2, cheeseSlices = 1
Output: [0,1]
*/
class _1276_NumberofBurgersWithNoWasteOfIngredients {
public:
    std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices);
};

/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

Constraints:
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/
class _1277_CountSquareSubmatricesWithAllOnes {
public:
    int countSquares(std::vector<std::vector<int>>& matrix);
};


class _1281_SubstractTheProductAndSumOfDigitsOfAnInteger {
public:
    int subtractProductAndSum(int n);
};
/*
There are n people whose IDs go from 0 to n - 1 and each person belongs exactly 
to one group. Given the array groupSizes of length n telling the group size each 
person belongs to, return the groups there are and the people's IDs each group 
includes.
You can return any solution in any order and the same applies for IDs. Also, it 
is guaranteed that there exists at least one solution. 

Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation: 
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].

Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]

Constraints:

groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n
*/
class _1282_GroupThePeopleGivenTheGroupSizeTheyBelongTo {
public:
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes);
};

/*
Given a m x n binary matrix mat. In one step, you can choose one cell and flip 
it and all the four neighbours of it if they exist (Flip is changing 1 to 0 and 
0 to 1). A pair of cells are called neighboors if they share one edge.
Return the minimum number of steps required to convert mat to a zero matrix or 
-1 if you cannot.
Binary matrix is a matrix with all cells equal to 0 or 1 only.
Zero matrix is a matrix with all cells equal to 0.

Input: mat = [[0,0],[0,1]]
Output: 3
Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.

Input: mat = [[0]]
Output: 0
Explanation: Given matrix is a zero matrix. We don't need to change it.

Input: mat = [[1,1,1],[1,0,1],[0,0,0]]
Output: 6

Input: mat = [[1,0,0],[1,0,0]]
Output: -1
Explanation: Given matrix can't be a zero matrix

Constraints:

m == mat.length
n == mat[0].length
1 <= m <= 3
1 <= n <= 3
mat[i][j] is 0 or 1.
*/
class _1284_MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrix {
private:
    int M;
    int N;

public:
    int minFlips(std::vector<std::vector<int>>& mat);
    int getInteger(std::vector<std::vector<int>>& mat);
    int oneFlip(int i, int j, int num);
};

/*
Design an Iterator class, which has:

A constructor that takes a string characters of sorted 
distinct lowercase English letters and a number 
combinationLength as arguments.

A function next() that returns the next combination of 
length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if 
there exists a next combination.

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.
*/
class _1286_IteratorForCombination {
private:
    std::string characters;
    int combinationLength;
    std::vector<int> combinIndex;
    bool isFirstCombination;
    int charactersLength;
public:
    _1286_IteratorForCombination(std::string cs, int cl);
    std::string next();
    bool hasNext();
};

/*
Given an integer array sorted in non-decreasing order, there is exactly one 
integer in the array that occurs more than 25% of the time.
Return that integer.

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Constraints:
1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5
*/
class _1287_ElementAppearingMoreThan25PercentInSortedArray {
public:
    int findSpecialInteger(std::vector<int>& arr);
};

/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
Example 5:

Input: head = [0,0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/
class _1290_ConvertBinaryNumberInALinkedListToInteger {
public:
    int getDecimalValue(ListNode<int>* head);
};

/*
Given an array nums of integers, return how many of them contain an even number of digits.

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.

Constraints:
1 <= nums.length <= 500
1 <= nums[i] <= 10^5
*/
class _1295_FindNumbersWithEvenNumberOfDigits {
public:
    int findNumber(std::vector<int>& nums);
};


/*
Given an array arr, replace every element in that array with the 
greatest element among the elements to its right, and replace the 
last element with -1.

After doing so, return the array.

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]

Constraints:
1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/
class _1299_ReplaceElementsWithGreatestElementOnRightSide {
public:
    std::vector<int> replaceElements(std::vector<int>& arr);
};
}

#endif