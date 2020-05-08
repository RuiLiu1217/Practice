#ifndef PROBLEM_SET7_HPP
#define PROBLEM_SET7_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

namespace LeetCode {

/*
Tag: Data Structure

Google

Design and implement a data structure for a compressed string iterator. 
It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed 
by a positive integer representing the number of this letter existing 
in the original uncompressed string.

next() - if the original string still has uncompressed characters, 
return the next letter; Otherwise return a white space.

hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, 
as static/class variables are persisted across multiple test cases. 
Please see here for more details.

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
*/
class _0604_DesignCompressedStringIterator {
private:
    std::queue<std::pair<std::string, int>> q;
public:
    _0604_DesignCompressedStringIterator(std::string compressedString);
    char next();
    bool hasNext();
};

/*
Given a list of directory info including directory path, and all the files with contents in this 
directory, you need to find out all the groups of duplicate files in the file system in terms of 
their paths.
A group of duplicate files consists of at least two files that have exactly the same content.
A single directory info string in the input list has the following format:
"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) 
in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of group of duplicate file paths. For each group, it contains all the file 
paths of the files that have the same content. A file path is a string that has the following format:

"directory_path/file_name.txt"

Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:  
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]

Note:

No order is required for the final output.
You may assume the directory name, file name and file content only has letters and digits, 
and the length of file content is in the range of [1,50].

The number of files given is in the range of [1,20000].
You may assume no files or directories share the same name in the same directory.
You may assume each given directory info represents a unique directory. Directory path and 
file info are separated by a single blank space.

Follow-up beyond contest:
Imagine you are given a real file system, how will you search files? DFS or BFS?
If the file content is very large (GB level), how will you modify your solution?
If you can only read the file by 1kb each time, how will you modify your solution?
What is the time complexity of your modified solution? What is the most time-consuming part and memory consuming part of it? How to optimize?
How to make sure the duplicated files you find are not false positive?
*/
class _0609_FindDuplicateFileInSystem {
public:
    std::vector<std::vector<std::string>> findDuplicate(std::vector<std::string>& paths);
private:
    std::pair<std::string, std::string> separateFileNameAndContent(const std::string& pf);
    std::vector<std::pair<std::string, std::string>> getOneFoldersFiles(const std::string& path);
};

/*

*/
class _0611_ValidTriangleNumber {
public:
    int triangleNumber(std::vector<int>& nums);
};

/*
Given two binary trees and imagine that when you put one of them to 
cover the other, some nodes of the two trees are overlapped while 
the others are not.
You need to merge them into a new binary tree. The merge rule is 
that if two nodes overlap, then sum node values up as the new 
value of the merged node. Otherwise, the NOT null node will be 
used as the node of new tree.

Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
 Note: The merging process must start from the root nodes of both trees.
*/
class _0617_MergeTwoBinaryTrees {
public:
    TreeNode<int>* mergeTrees(TreeNode<int>* t1, TreeNode<int>* t2);
};

class _0621_TaskScheduler {
public:
    int leastInterval(std::vector<char>& tasks, int n);
};

/*
622. Design Circular Queue
Design your implementation of the circular queue. The circular queue is a 
linear data structure in which the operations are performed based on FIFO 
(First In First Out) principle and the last position is connected back to 
the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the 
spaces in front of the queue. In a normal queue, once the queue becomes full, 
we cannot insert the next element even if there is a space in front of the 
queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.
 

Example:

MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
*/
class _0622_DesignCircularQueue {
    std::vector<int> q;
    int head, tail, N;
    bool empty;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    _0622_DesignCircularQueue(int k);
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value);
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue();
    
    /** Get the front item from the queue. */
    int Front();
    
    /** Get the last item from the queue. */
    int Rear();
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty();
    
    /** Checks whether the circular queue is full or not. */
    bool isFull();
};

/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
 

Example 2:

Input: 3
Output: False
*/
class _0633_SumOfSquareNumbers {
public:
    bool judgeSquareSum(int c);
};

/*
On a single threaded CPU, we execute some functions.  Each function has a unique id between 0 and N-1.
We store logs in timestamp order that describe when a function is entered or exited.
Each log is a string with this format: "{function_id}:{"start" | "end"}:{timestamp}".  For example, 
"0:start:3" means the function with id 0 started at the beginning of timestamp 3.  "1:end:2" means the 
function with id 1 ended at the end of timestamp 2.
A function's exclusive time is the number of units of time spent in this function.  Note that this does 
not include any recursive calls to child functions.
The CPU is single threaded which means that only one function is being executed at a given time unit.
Return the exclusive time of each function, sorted by their function id.

Input:
n = 2
logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3, 4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 units of time and reaches the end of time 1.
Now function 1 starts at the beginning of time 2, executes 4 units of time and ends at time 5.
Function 0 is running again at the beginning of time 6, and also ends at the end of time 6, thus executing for 1 unit of time. 
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
 

Note:

1 <= n <= 100
Two functions won't start or end at the same time.
Functions will always log when they exit.
 
*/
class _0636_ExclusiveTimeOfFunctions {
public:
    std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs);
};

/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
*/
class _0637_AverageOfLevelsInBinaryTree {
public:
    std::vector<double> averageOfLevels(TreeNode<int>* root);
};



/*
Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:

MyCircularDeque(k): Constructor, set the size of the deque to be k.
insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
getRear(): Gets the last item from Deque. If the deque is empty, return -1.
isEmpty(): Checks whether Deque is empty or not. 
isFull(): Checks whether Deque is full or not.
 

Example:

MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4
 

Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Deque library.
*/
class _0641_DesignCircularDeque{
private:
    std::vector<int> q;
    int start;
    int end;
    int K;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    _0641_DesignCircularDeque(int k);
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value);

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value);
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront();
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast();
    
    /** Get the front item from the deque. */
    int getFront();
    
    /** Get the last item from the deque. */
    int getRear();

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty();
    
    /** Checks whether the circular deque is full or not. */
    bool isFull();
};

/*
You are given n pairs of numbers. In every pair, the first number is always 
smaller than the second number.
Now, we define a pair (c, d) can follow another pair (a, b) if and only if 
b < c. Chain of pairs can be formed in this fashion.
Given a set of pairs, find the length longest chain which can be formed. You 
needn't use up all the given pairs. You can select pairs in any order.

Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].
*/
class _0646_MaximumLengthOfPairChain {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs);
};

/*
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different 
substrings even they consist of same characters.

Input: "abc"        :        Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 
Input: "aaa"        :        Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/
class _0647_PalindromicSubstrings{
public:
    int countSubstrings(std::string s);
private:
    int sub(const std::string& s, int k);
};

/*
Given an integer array with no duplicates. A maximum tree 
building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left 
part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right 
part subarray divided by the maximum number.
Construct the maximum tree by the given array and output 
the root node of this tree.

Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
The size of the given array will be in the range [1,1000].
*/
class _0654_MaximumBinaryTree {
public:
    TreeNode<int>* constructMaximumBinaryTree(std::vector<int>& nums);
private:
    TreeNode<int>* constructMaximumBinaryTree_impl(std::vector<int>& nums, int l, int r);
};

/*
Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of 
the first row it can be put. The column and the row where the root node belongs 
will separate the rest space into two parts (left-bottom part and right-bottom 
part). You should print the left subtree in the left-bottom part and print the 
right subtree in the right-bottom part. The left-bottom part and the right-bottom 
part should have the same size. Even if one subtree is none while the other is 
not, you don't need to print anything for the none subtree but still need to 
leave the space as large as that for the other subtree. However, if two subtrees 
are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].
这道题一下子蒙住了，实际上这道题很简单，还是一个递归调用，首先要建立起整个矩阵，用空字符串填满
这里就需要计算好本身这棵树有多高，那么有多宽就可以算出来，
每层都是在正中间填充数字，递归调用把左右两边的范围分别变成 [l mid-1]， [mid + 1, r] 就可以了
*/
class _0655_PrintBinaryTree {
public:
    std::vector<std::vector<std::string>> printTree(TreeNode<int>* root);
private:
    int getHeight(TreeNode<int>* root);
    void fill(TreeNode<int>* root, std::vector<std::vector<std::string>>& res, int h, int l, int r);
};

/*
There is a robot starting at position (0, 0), the origin, on a 2D plane. 
Given a sequence of its moves, judge if this robot ends up at (0, 0) after 
it completes its moves.
The move sequence is represented by a string, and the character moves[i] 
represents its ith move. Valid moves are R (right), L (left), U (up), 
and D (down). If the robot returns to the origin after it finishes all of 
its moves, return true. Otherwise, return false.
Note: The way that the robot is "facing" is irrelevant. "R" will always 
make the robot move to the right once, "L" will always make it move left, 
etc. Also, assume that the magnitude of the robot's movement is the same 
for each move.

Input: "UD"
Output: true 
Explanation: The robot moves up once, and then down once. All moves have 
the same magnitude, so it ended up at the origin where it started. 
Therefore, we return true.

Input: "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the 
left of the origin. We return false because it is not at the origin at 
the end of its moves.
*/
class _0657_RobotReturnToOrigin {
public:
    bool judgeCircle(std::string moves);
};

/*
Tag: Priority Queue

Google
Given a sorted array, two integers k and x, find the k closest elements 
to x in the array. The result should also be sorted in ascending order. 
If there is a tie, the smaller elements are always preferred.

Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]

Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of 
the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
*/
class _0658_FindKClosetElements {
public:
    std::vector<int> findClosetElements(std::vector<int>&arr, int k, int n);
};

/*
You are given an integer array sorted in ascending order (may contain 
duplicates), you need to split them into several subsequences, where 
each subsequences consist of at least 3 consecutive integers. Return 
whether you can make such a split.

Example 1:

Input: [1,2,3,3,4,5] :  Output: True
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5

Example 2:
Input: [1,2,3,3,4,4,5,5] : Output: True
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
 

Example 3:
Input: [1,2,3,4,4,5]  :  Output: False

Note:
The length of the input is in range of [1, 10000]
*/
class _0659_SplitArrayIntoConsecutiveSubsequences {
public:
    bool isPossible(std::vector<int>& nums);
};

/*
Given a 2D integer matrix M representing the gray scale of an image, 
you need to design a smoother to make the gray scale of each cell 
becomes the average gray scale (rounding down) of all the 8 surrounding 
cells and itself. If a cell has less than 8 surrounding cells, then 
use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
*/
class _0661_ImageSmoother {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& M);
};


/*
There is a strange printer with the following two special requirements:
The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any 
places, and will cover the original existing characters.
Given a string consists of lower English letters only, your job is to count the minimum 
number of turns the printer needed in order to print it.

Input: "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Input: "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, 
which will cover the existing character 'a'.
Hint: Length of the given string will not exceed 100.
*/
class _0664_StrangePrinter {
public:
    int strangePrinter(const std::string& s);
private:
    int turn(const std::string& s, int i, int j);
    std::vector<std::vector<int>> DP;
};

/*
Given two integers n and k, you need to construct a list which contains 
n different positive integers ranging from 1 to n and obeys the following 
requirement:
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, 
|a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Input: n = 3, k = 1           :            Output: [1, 2, 3]
Input: n = 3, k = 2           :            Output: [1, 3, 2]
Note:
The n and k are in the range 1 <= k < n <= 104.
*/
class _0667_BeautifulArrangementII {
public:
    std::vector<int> constructArray(int n, int k);
};



/*
On an NxN chessboard, a knight starts at the r-th row and c-th 
column and attempts to make exactly K moves. The rows and columns 
are 0 indexed, so the top-left square is (0, 0), and the 
bottom-right square is (N-1, N-1).
A chess knight has 8 possible moves it can make, as illustrated 
below. Each move is two squares in a cardinal direction, then one 
square in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible 
moves uniformly at random (even if the piece would go off the 
chessboard) and moves there.
The knight continues moving until it has made exactly K moves or 
has moved off the chessboard. Return the probability that the knight 
remains on the board after it has stopped moving.

Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep 
the knight on the board. From each of those positions, there are also 
two moves that will keep the knight on the board. The total probability 
the knight stays on the board is 0.0625.

Note:
N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.
*/
class _0668_KnightProbabilityInChessboard {
public:
    double knightProbability(int N, int K, int r, int c);
};

/*
Given a non-empty special binary tree consisting of nodes with the non-negative 
value, where each node in this tree has exactly two or zero sub-node. If the node 
has two sub-nodes, then this node's value is the smaller value among its two 
sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) 
always holds.

Given such a binary tree, you need to output the second minimum value in the set 
made of all the nodes' value in the whole tree.
If no such second minimum value exists, output -1 instead.

Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
 

Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
*/
class _0671_SecondMinimumNodeInABinaryTree {
private:
    int min1;
    int ans = INT_MAX;
public:
    void dfs(TreeNode<int>* root);
    int findSecondMinimumValue(TreeNode<int>* root);
};

/*
Implement a magic directory with buildDict, and search methods.
For the method buildDict, you'll be given a list of non-repetitive 
words to build a dictionary.
For the method search, you'll be given a word, and judge whether if you 
modify exactly one character into another character in this word, the 
modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think 
about highly efficient algorithm after the contest. Please remember to RESET 
your class variables declared in class MagicDictionary, as static/class 
variables are persisted across multiple test cases. Please see here for 
more details.
*/
class _0676_ImplementMagicDictionary {
public:
    _0676_ImplementMagicDictionary();
    void buildDict(std::vector<std::string> dict);
    bool search(std::string word);
private:
    std::unordered_map<int, std::unordered_set<std::string>> _dict;
};


/*
You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated 
through *, /, +, -, (, ) to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
*/
class _0679_24Games{
public:
    bool judgePoint24(std::vector<int>& nums);
private:
    bool valid(std::vector<int>& nums);
    bool valid(double a, double b, double c);
    bool valid(double a, double b); 
};

/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Input: "aba"
Output: True

Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/
class _0680_ValidPalindromeII {
public:
    bool validPalindrome(std::string s);
};

/*
Given a time represented in the format "HH:MM", form the next 
closest time by reusing the current digits. There is no limit 
on how many times a digit can be reused.

You may assume the given input string is always valid. For 
example, "01:34", "12:09" are all valid. "1:34", "12:9" are 
all invalid.

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 
3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, 
because this occurs 23 hours and 59 minutes later.

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 
9, is 22:22. It may be assumed that the returned time is next
day's time since it is smaller than the input time numerically.
*/
class _0681_NextClosetTime {
public:
    std::string nextClosetTime(std::string time);
};

/*
In this problem, a tree is an undirected graph that is connected and has no cycles.
The given input is a graph that started as a tree with N nodes (with distinct values 
1, 2, ..., N), with one additional edge added. The added edge has two different 
vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair 
[u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array. 
The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is 
an undirected graph. For the directed graph follow up please see Redundant Connection II). 
We apologize for any inconvenience caused.
*/
class _0684_RedundantConnection {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges);
};

/*
Given two strings A and B, find the minimum number of times A has to be 
repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".
Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring 
of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/
class _0686_RepeatedStringMatch {
public:
    int repeatedStringMatch(std::string A, std::string B);
};

/*
Given a binary tree, find the length of the longest path where each 
node in the path has the same value. This path may or may not pass 
through the root.
The length of path between two nodes is represented by the number 
of edges between them.

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2
Note: The given binary tree has not more than 10000 nodes. The 
height of the tree is not more than 1000.
*/
class _0687_LongestUnivaluePath {
public:
    int longestUnivaluePath(TreeNode<int>* root);
private:
    int univaluePath(TreeNode<int>* root, int* ans);
};

/*
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. If 
two words have the same frequency, then the word with the lower 
alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/
class _0692_TopKFrequentWords {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k);
};

/*
Given the root node of a binary search tree (BST) and a value. 
You need to find the node in the BST that the node's value equals 
the given value. Return the subtree rooted with that node. 
If such node doesn't exist, you should return NULL.

Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2
You should return this subtree:

      2     
     / \   
    1   3
In the example above, if we want to search the value 5, since 
there is no node with value 5, we should return NULL.
Note that an empty tree is represented by NULL, therefore you 
would see the expected output (serialized tree format) as [], 
not null.
*/
class _0700_SearchInABinarySearchTree {
public:
    TreeNode<int>* searchBST(TreeNode<int>* root, int val);
};
}

#endif