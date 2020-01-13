#ifndef HEADERS_HPP
#define HEADERS_HPP
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "Tree.hpp"
#include "LinkList.hpp"

#include "ProblemSet1.hpp" // Problem 1 - 100
#include "ProblemSet2.hpp" // Problem 101 - 200
#include "ProblemSet3.hpp" // Problem 201 - 300
#include "ProblemSet4.hpp" // Problem 301 - 400
#include "ProblemSet5.hpp" // Problem 401 - 500
#include "ProblemSet6.hpp" // Problem 501 - 600

namespace LeetCode
{
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


/* 1103. distribute candies to people:
We distribute some number of candies, to a row of n = num_people 
people in the following way:
We then give 1 candy to the first person, 2 candies to the second 
person, and so on until we give n candies to the last person.Then, 
we go back to the start of the row, giving n + 1 candies to the 
first person, n + 2 candies to the second person, and so on until 
we give 2 * n candies to the last person.
This process repeats (with us giving one more candy each time, and 
moving to the start of the row after we reach the end) until we run 
out of candies. The last person will receive all of our remaining 
candies (not necessarily one more than the previous gift).
Return an array (of length num_people and sum candies) that represents 
the final distribution of candies. 

Example 1:

Input: candies = 7, num_people = 4
Output: [1,2,3,1]
Explanation:
On the first turn, ans[0] += 1, and the array is [1,0,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0,0].
On the third turn, ans[2] += 3, and the array is [1,2,3,0].
On the fourth turn, ans[3] += 1 (because there is only one candy left), and the final array is [1,2,3,1].
Example 2:

Input: candies = 10, num_people = 3
Output: [5,2,3]
Explanation: 
On the first turn, ans[0] += 1, and the array is [1,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0].
On the third turn, ans[2] += 3, and the array is [1,2,3].
On the fourth turn, ans[0] += 4, and the final array is [5,2,3].
*/
class _1103_DistributeCandiesToPeople {
public:
    std::vector<int> distributeCandies(int candies, int num_people);
};

/*
In an infinite binary tree where every node has two children, the nodes are 
labelled in row order.
In the odd numbered rows (ie., the first, third, fifth,...), the labelling 
is left to right, while in the even numbered rows (second, fourth, sixth,...), 
the labelling is right to left.

Given the label of a node in this tree, return the labels in the path from 
the root of the tree to the node with that label.

Input: label = 14
Output: [1,3,4,14]

Input: label = 26
Output: [1,2,6,10,26]
*/
class _1104_PathInZigzagLabelledBinaryTree {
public:
    std::vector<int> pathInZigZagTree(int label);
};

/*
We have a sequence of books: the i-th book has thickness books[i][0] 
and height books[i][1]. 
We want to place these books in order onto bookcase shelves that have 
total width shelf_width.
We choose some of the books to place on this shelf (such that the sum 
of their thickness is <= shelf_width), then build another level of 
shelf of the bookcase so that the total height of the bookcase has 
increased by the maximum height of the books we just put down. We repeat 
this process until there are no more books to place.

Note again that at each step of the above process, the order of the 
books we place is the same order as the given sequence of books. 
For example, if we have an ordered list of 5 books, we might place the 
first and second book onto the first shelf, the third book on the second 
shelf, and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be after 
placing shelves in this manner.

Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.

Constraints:
1 <= books.length <= 1000
1 <= books[i][0] <= shelf_width <= 1000
1 <= books[i][1] <= 1000
*/
class _1105_FillingBookcaseShelves {
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelf_width);
};


/*
Return the result of evaluating a given boolean expression, represented as a string.

An expression can either be:

"t", evaluating to True;
"f", evaluating to False;
"!(expr)", evaluating to the logical NOT of the inner expression expr;
"&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...
 

Example 1:

Input: expression = "!(f)"
Output: true
Example 2:

Input: expression = "|(f,t)"
Output: true
Example 3:

Input: expression = "&(t,f)"
Output: false
Example 4:

Input: expression = "|(&(t,f,t),!(t))"
Output: false
 

Constraints:

1 <= expression.length <= 20000
expression[i] consists of characters in {'(', ')', '&', '|', '!', 't', 'f', ','}.
expression is a valid expression representing a boolean, as given in the description.
*/
class _1106_ParsingABolleanExpression {
public:
    bool parseBoolExpr(std::string expression);
};


/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"

Constraints: The given address is a valid IPv4 address.
*/
class _1108_DefangingAnIPAddress {
public:
    std::string defangIPaddr(std::string address); 
};

/*
  Given the root of a binary tree, each node in the tree has a distinct value.
  After deleting all nodes with a value in to_delete, we are left with a forest 
  (a disjoint union of trees). 
  Return the roots of the trees in the remaining forest. You may return the 
  result in any order.

  Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
  Output: [[1,2,null,4],[6],[7]]

Constraints:

    The number of nodes in the given tree is at most 1000.
    Each node has a distinct value between 1 and 1000.
    to_delete.length <= 1000
    to_delete contains distinct values between 1 and 1000.
*/
class _1110_DeleteNodesAndReturnForest {
    // Copy from a solution
private:
    std::vector<TreeNode<int>*> result;
    std::unordered_set<int> toDeleteSet;
public:
    std::vector<TreeNode<int>*> delNodes(TreeNode<int>* root, std::vector<int>& to_delete);
    TreeNode<int>* helper(TreeNode<int>* node, std::vector<TreeNode<int>*>& result,
                    std::unordered_set<int>& toDeleteSet, bool isRoot);
};


/*
A string is a valid parentheses string (denoted VPS) if and only if it consists of "(" and ")" 
characters only, and:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.
We can similarly define the nesting depth depth(S) of any VPS S as follows:

depth("") = 0
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example,  "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

Given a VPS seq, split it into two disjoint subsequences A and B, such that A and B are VPS's 
(and A.length + B.length = seq.length).
Now choose any such A and B such that max(depth(A), depth(B)) is the minimum possible value.
Return an answer array (of length seq.length) that encodes such a choice of A and B: 
answer[i] = 0 if seq[i] is part of A, else answer[i] = 1. 
Note that even though multiple answers may exist, you may return any of them.

Input: seq = "(()())"
Output: [0,1,1,1,1,0]

Input: seq = "()(())()"
Output: [0,0,0,1,1,0,1,1]

Constraints:

1 <= seq.size <= 10000
*/
class _1111_MaximumNestingDepthOfTwoValidParenthesesStrings {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq);
};

/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all 
elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are 
the same as in arr2.  Elements that don't appear in arr2 should be placed at 
the end of arr1 in ascending order.

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
 
Constraints:

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
Each arr2[i] is distinct.
Each arr2[i] is in arr1.
*/
class _1122_RelativeSortArray {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2);
};

/*
In a project, you have a list of required skills req_skills, and a list of people.
The i-th person people[i] contains a list of skills that person has.
Consider a sufficient team: a set of people such that for every required skill in 
req_skills, there is at least one person in the team who has that skill. 
We can represent these teams by the index of each person: for example, 
team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].

Return any sufficient team of the smallest possible size, represented by the index of each person.
You may return the answer in any order.  It is guaranteed an answer exists.

Example 1:
Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]

Example 2:
Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], 
people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],
["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
 
Constraints:

1 <= req_skills.length <= 16
1 <= people.length <= 60
1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
Elements of req_skills and people[i] are (respectively) distinct.
req_skills[i][j], people[i][j][k] are lowercase English letters.
Every skill in people[i] is a skill in req_skills.
It is guaranteed a sufficient team exists.
*/
class _1125_SmallestSufficientTeam {
public:
    std::vector<int> smallestSufficientTeam(
        std::vector<std::string>& req_skills, 
        std::vector<std::vector<std::string>>& people);
};

/*
Given two arrays of integers with equal lengths, return the 
maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
where the maximum is taken over all 0 <= i, j < arr1.length. 

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]           :   Output: 13
Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4] :   Output: 20

Constraints:
2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6
*/
class _1131_MaximumOfAbsoluteValueExpression {
public:
    int maxAbsValExpr(std::vector<int>& arr1, std::vector<int>& arr2);
};


/*
Two players play a turn based game on a binary tree.  We are given the root
of this binary tree, and the number of nodes n in the tree. n is odd, and 
each node has a distinct value from 1 to n.
Initially, the first player names a value x with 1 <= x <= n, and the second 
player names a value y with 1 <= y <= n and y != x. The first player colors 
the node with value x red, and the second player colors the node with value 
y blue.
Then, the players take turns starting with the first player. In each turn, 
that player chooses a node of their color (red if player 1, blue if player 2) 
and colors an uncolored neighbor of the chosen node (either the left child,
 right child, or parent of the chosen node.)
If (and only if) a player cannot choose such a node in this way, they must 
pass their turn. If both players pass their turn, the game ends, and the 
winner is the player that colored more nodes.

You are the second player.  If it is possible to choose such a y to ensure 
you win the game, return true.  If it is not possible, return false.
这道题赢的条件是谁拿到更多的节点而不是节点的和。当时看到这个题有点懵，以为是算节点
的和。
*/
class _1145_BinaryTreeColoringGame {
public:
    bool btreeGameWinningMove(TreeNode<int>* root, int n, int x);
private:
    int l_;
    int r_;
    int nodes(TreeNode<int>* root, int x);
};

/*
Implement a SnapshotArray that supports the following interface:
SnapshotArray(int length) initializes an array-like data structure with the 
given length.  Initially, each element equals 0.

void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5

Constraints:
1 <= length <= 50000
At most 50000 calls will be made to set, snap, and get.
0 <= index < length
0 <= snap_id < (the total number of times we call snap())
0 <= val <= 10^9
*/
class _1146_SnapshotArray {
private:
    std::vector<std::map<int, int>> A;
    int snap_id = 0;
public:
    _1146_SnapshotArray(int length);
    void set(int index, int val);
    int snap();
    int get(int index, int snaid);
};

/*
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Input: date = "2019-02-10"
Output: 41

Input: date = "2003-03-01"
Output: 60

Input: date = "2004-03-01"
Output: 61

Constraints:
date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
*/
class _1154_DayOfTheYear {
public:
    int dayOfYear(std::string dt) {
        int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int y = stoi(dt.substr(0, 4)), m = stoi(dt.substr(5, 2)), d = stoi(dt.substr(8));
        if (m > 2 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ++d; 
        while (--m > 0) d += days[m - 1];
        return d;
    }    
};


/*
You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars 
(each character can only be used once).
Return the sum of lengths of all good strings in words.

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.
*/
class _1160_FindWordsThatCanBeFormedByCharacters {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars);
};

/*
Given the root of a binary tree, the level of its root is 1, the 
level of its children is 2, and so on.
Return the smallest level X such that the sum of all the values 
of nodes at level X is maximal.

Input: [1,7,0,7,-8,null,null]
Output: 2
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Note:

The number of nodes in the given tree is between 1 and 10^4.
-10^5 <= node.val <= 10^5
*/
class _1161_MaximumLevelSumOfABinaryTree {
public:
    int maxLevelSum(TreeNode<int>* root);
};

/*
Let's define a function f(s) over a non-empty string s, which calculates the frequency 
of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the 
smallest character is "c" and its frequency is 2.
Now, given string arrays queries and words, return an integer array answer, where each 
answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words. 

Input: queries = ["cbd"], words = ["zaaaz"]      :      Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]   :   Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").

Constraints:

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j], words[i][j] are English lowercase letters.
*/
class _1170_CompareStringByFrequencyOfTheSmallestCharacter {
public:
    std::vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words);
    
};



/*
Return the number of permutations of 1 to n so that prime numbers are at prime 
indices (1-indexed.) (Recall that an integer is prime if and only if it is greater 
than 1, and cannot be written as a product of two positive integers both smaller than it.)
Since the answer may be large, return the answer modulo 10^9 + 7.

Input: n = 5             :              Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.

Input: n = 100           :              Output: 682289015
*/
class _1175_PrimeArrangements {
public:
    constexpr static auto MOD = static_cast<int>(1e9+7); // Use C++11 constexpr
    int numPrimeArrangements(int n, int primes, long long ans);
private:
    bool isPrime(int n);
};


/*
 1186 Maximum Subarray Sum With One Deletion
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) 
with at most one element deletion. In other words, you want to choose a subarray and optionally 
delete one element from it so that there is still at least one element left and the sum of the 
remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, 
then get an empty subarray to make the sum equals to 0. 

Constraints:

    1 <= arr.length <= 10^5
    -10^4 <= arr[i] <= 10^4

 */
class _1186_MaximumSubarraySumWithOneDeletion {
  public:
    int maximumSum(std::vector<int>& arr);
    
};




/*
Given a string text, you want to use the characters of text to form as many instances 
of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances 
that can be formed.

Input: text = "nlaebolko"              :             Output: 1
Input: text = "loonbalxballpoon"       :             Output: 2
Input: text = "leetcode"               :             Output: 0
*/
class _1189_MaximumNumberOfBalloons {
public:
    int maxNumberOfBalloons(std::string text);
    bool updateBallon(std::vector<int>& map);
};

/*
You are given a string s that consists of lower case English letters and brackets. 
Reverse the strings in each pair of matching parentheses, starting from the innermost 
one. Your result should not contain any brackets.

Input: s = "(abcd)"                    :         Output: "dcba"
Input: s = "(u(love)i)"                :         Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Input: s = "(ed(et(oc))el)"            :         Output: "leetcode"
Input: s = "a(bcdefghijkl(mno)p)q"     :         Output: "apmnolkjihgfedcbq"

Constraints:
0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.
*/
class _1190_ReverseSubstringsBetweenEachPairOfParentheses {
public:
    std::string reverseParentheses(std::string s);
};


/*
Given an array of distinct integers arr, find all pairs of elements with the minimum 
absolute difference of any two elements. 
Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] 
follows
a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. 
List all pairs with difference equal to 1 in ascending order.

Input: arr = [1,3,6,10,15]
Output: [[1,3]]

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]

Constraints:

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
*/
class _1200_MinimumAbsoluteDifference {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr);
};

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

/*
You are given a square board of characters. You can move on the board starting 
at the bottom right square marked with the character 'S'.
You need to reach the top left square marked with the character 'E'. The rest 
of the squares are labeled either with a numeric character 1, 2, ..., 9 or with 
an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if 
there is no obstacle there.
Return a list of two integers: the first integer is the maximum sum of numeric 
characters you can collect, and the second is the number of such paths that you
 can take to get that maximum sum, taken modulo 10^9 + 7.
In case there is no path, return [0, 0].

Input: board = ["E23","2X2","12S"]
Output: [7,1]

Input: board = ["E12","1X1","21S"]
Output: [4,2]

Input: board = ["E11","XXX","11S"]
Output: [0,0]
 
Constraints:

2 <= board.length == board[i].length <= 100
*/
class _1301_NumberOfPathsWithMaxScore {
public:
    std::vector<int> pathsWithMaxScore(std::vector<std::string>& bd);
};

/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Input: n = 3
Output: [-1,0,1]

Input: n = 1
Output: [0]

Constraints:
1 <= n <= 1000
*/
class _1304_FindNUniqueIntegersSumupToZero {
public:
    std::vector<int> sumZero(int n);
};

/*
Given two binary search trees root1 and root2.
Return a list containing all the integers from both trees sorted in ascending order.

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]

Constraints:
Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
*/
class _1305_AllElementsInTwoBinarySearchTrees {
public:
    std::vector<int> getAllElements(TreeNode<int>* root1, TreeNode<int>* root2);
};

/*
Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English 
lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.
It's guaranteed that a unique mapping will always exist.

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

Input: s = "1326#"
Output: "acz"

Input: s = "25#"
Output: "y"

Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"

Constraints:
1 <= s.length <= 1000
s[i] only contains digits letters ('0'-'9') and '#' letter.
s will be valid string such that mapping is always possible.
*/
class _1309_DecryptStringFromAlphabetToIngeterMapping {
public:
    std::string freqAlphabets(std::string s);
};

/*
Given the array arr of positive integers and the array queries where 
queries[i] = [Li, Ri], for each query i compute the XOR of elements 
from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
Return an array containing the result for the given queries.

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
*/
class _1310_XORQueriesOfASubarray {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries);
};

/*
Given a binary tree, return the sum of values of nodes with even-valued grandparent. 
(A grandparent of a node is the parent of its parent, if it exists.)
If there are no nodes with an even-valued grandparent, return 0.

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue 
nodes are the even-value grandparents. 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.
*/
class _1315_SumOfNodesWithEvenvaluedGrandparent {
public:
    int sumEvenGrandparent(TreeNode<int>* root);
};

} // namespace LeetCode





















































namespace LintCode {

    /*
    Write a function that add two numbers A and B. There is no need to read data 
    from standard input stream. Both parameters are given in function aplusb, your 
    job is to calculate the sum and return it.
    
    Have you met this question in a real interview?  
    Clarification
    Are a and b both 32-bit integers? Yes.
    
    Can I use bit operation? Sure you can.
    
    Input:  a = 1, b = 2
    Output: 3	
    Explanation: return the result of a + b.
    
    Example 2:
    Input:  a = -1, b = 1
    Output: 0	
    Explanation: return the result of a + b.
    Challenge
    Of course you can just return a + b to get accepted. But Can you challenge not 
    do it like that?(You should not use + or any arithmetic operators.)
    */    
    class _0001_APlusBProblem {
        public:
            int aplusb(int a, int b);
    };

    /*
    Write an algorithm which computes the number of trailing zeros in n factorial. 
    
    Example 1:
	Input:  11         :        Output: 2	
	Explanation: 
	11! = 39916800, so the output should be 2

	Input:  5          :        Output: 1	
	Explanation: 
	5! = 120, so the output should be 1.

    Challenge   O(log N) time
    还没有理解为什么，可以用笔一点一点照着solution写出来看看
    */
    class _0002_TrailingZeros {
        public:
            long long trailingZeros(long long n);
    };

/*
Ugly number is a number that only have prime factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

Note that 1 is typically treated as an ugly number.

Have you met this question in a real interview?  
Example
Example 1:

Input: 9
Output: 10
Example 2:

Input: 1
Output: 1
Challenge
O(n log n) or O(n) time.
*/
class _0004_UglyNumberII {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n);
};

/*
Merge two given sorted ascending integer array A and B into a new sorted integer array.
Have you met this question in a real interview?  

Input:  A=[1], B=[1]        :        Output: [1,1]	
Input:  A=[1,2,3,4], B=[2,4,5,6]  :  Output: [1,2,2,3,4,4,5,6]	

How can you optimize your algorithm if one array is very large and the other is very small?
Related Problems
*/
class _0006_MergeTwoSortedArrays {
public:
    std::vector<int> mergeSortedArray(std::vector<int> &A, std::vector<int> &B);
};

/*
Description
Given a string(Given in the way of char array) and an offset, rotate the string by offset in place. (rotate from left to right).

offset >= 0
the length of str >= 0
Make changes on the original input data

Have you met this question in a real interview?  
Example

Input: str="abcdefg", offset = 3
Output: str = "efgabcd"	

Input: str="abcdefg", offset = 0
Output: str = "abcdefg"	

Input: str="abcdefg", offset = 1
Output: str = "gabcdef"	

Input: str="abcdefg", offset =2
Output: str = "fgabcde"	

Input: str="abcdefg", offset = 10
Output: str = "efgabcd"	
Explanation: Note that it is rotated in place, that is, after str is rotated, it becomes "efgabcd".
Challenge
Rotate in-place with O(1) extra memory.
*/
class _0008_RotateString {
public:
    void rotateString(std::string &str, int offset);
};


/*
Description
Given number n. Print number from 1 to n. But:

when number is divided by 3, print "fizz".
when number is divided by 5, print "buzz".
when number is divided by both 3 and 5, print "fizz buzz".
when number can't be divided by either 3 or 5, print the number itself.
Have you met this question in a real interview?
Example
If n = 15, you should return:
[
  "1", "2", "fizz",
  "4", "buzz", "fizz",
  "7", "8", "fizz",
  "buzz", "11", "fizz",
  "13", "14", "fizz buzz"
]

If n = 10, you should return:
[
  "1", "2", "fizz",
  "4", "buzz", "fizz",
  "7", "8", "fizz",
  "buzz"
]
Challenge : Can you do it with only one if statement?
*/
class _0009_FizzBuzz {
public:
    std::vector<std::string> fizzBuzz(int n);
};


    /*
    Description
    In a 2D array grid, each value grid[i][j] represents the height of a building 
    located there. We are allowed to increase the height of any number of buildings, 
    by any amount (the amounts can be different for different buildings). Height 
    0 is considered to be a building as well.
    
    At the end, the "skyline" when viewed from all four directions of the grid, i.e. 
    west, east, north, and south, must be the same as the skyline of the original 
    grid. A city's skyline is the outer contour of the rectangles formed by all the 
    buildings when viewed from a distance. See the following example.
    
    What is the maximum total sum that the height of the buildings can be increased?
    1 < grid.length = grid[0].length <= 50.
    All heights grid[i][j] are in the range [0, 100].
    All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.
    Have you met this question in a real interview?  
    
    Example
    Input: 
    [   [3,0,8,4],
        [2,4,5,7],
        [9,2,6,3],
        [0,3,1,0] ]
        
    Output: 35
    Explanation: 
        The skyline viewed from north or south is: [9, 4, 8, 7]
        The skyline viewed from west or right is: [8, 7, 9, 3]
        The grid after increasing the height of buildings without affecting skylines is:
        [ [8,4,8,7],
          [7,4,7,7],
          [9,4,8,7],
          [3,3,3,3] ]
    */
    class _1010_MaxIncreaseToKeepCitySkyline {
        public:
            int maxIncreaseKeepingSkyline(std::vector<std::vector<int>> &grid);
    };

    class _1207_UniqueNumberOfOccurances {
        public:
            bool uniqueOccurrences(std::vector<int>& arr);
    };
    
    /* Description
    You're given strings J representing the types of stones that are jewels, and S 
    representing the stones you have. Each character in S is a type of stone you have. 
    You want to know how many of the stones you have are also jewels.
    
    The letters in J are guaranteed distinct, and all characters in J and S are letters. 
    Letters are case sensitive, so "a" is considered a different type of stone from "A".
    S and J will consist of letters and have length at most 50.
    
    The characters in J are distinct.
    Example
    Example 1:
    Input: J = "aA", S = "aAAbbbb"
    
    Output: 3
    Example 2:
    Input: J = "z", S = "ZZ"
    Output: 0
    */
    class _1038_JewelsAndStones{
        public:
            int numJewelInStones(std::string& J, std::string& S);
    };

    /*
    Initially, there is a Robot at position (0, 0). Given a 
    sequence of its moves, judge if this robot makes a circle, 
    which means it moves back to the original place finally.
    The move sequence is represented by a string. And each move 
    is represent by a character. The valid robot moves are R 
    (Right), L (Left), U (Up) and D (down). The output should be 
    true or false representing whether the robot makes a circle.

    Example 1: Input: "UD"      Output: true
    Example 2: Input: "LL"      Output: false
    */
    class _1104_JudgeRouteCircle {
        public:
            bool judgeCircle(std::string& moves);
    };

    /*
    Given a non-empty binary tree, return the average value of the nodes on each level 
    in the form of an array. The range of node's value is in the range of 32-bit signed 
    integer. 
    Example
    Example 1:
    Input:
        3
       / \'
      9  20
        /  \
       15   7
    Output: [3, 14.5, 11]
    */
    class _1115_AverageOfLevelsInBinaryTree{
        public:
            std::vector<double> averageOfLevels(TreeNode<int>* root);
    };

    /*
    Given two binary trees and imagine that when you put one of them 
    to cover the other, some nodes of the two trees are overlapped 
    while the others are not.
    
    You need to merge them into a new binary tree. The merge rule is 
    that if two nodes overlap, then sum node values up as the new 
    value of the merged node. Otherwise, the NOT null node will be 
    used as the node of new tree.
    
    The merging process must start from the root nodes of both trees.
    
    Example
    Example1
    Input: 
    {1,3,2,5}
    {2,1,3,#,4,#,7}
    Output:
    {3,4,5,5,4,#,7}
    Explanation:
    	Tree 1                     Tree 2                  
                  1                         2                             
                 / \                       / \                            
                3   2                     1   3                        
               /                           \   \                     
              5                             4   7                  
    Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
    */

    class _1126_MergeTwoBinaryTrees{
        public:
            TreeNode<int> * mergeTrees(TreeNode<int> * t1, TreeNode<int> * t2);
    };

    /*
    Given a complete binary tree, count the number of nodes.
    */
    class _1317_CountCompleteTreeNodes {
        public:
            int countNodes(TreeNode<int>* root);
    };

    /*
    Write a function that takes an unsigned integer and returns the number of ’1' bits the 
    corresponding binary number has (also known as the Hamming weight).
    
    Input：n = 11
    Output：3
    Explanation：11(10) = 1011(2), so return 3
    */
    class _1332_NumberOf1Bits{
        public:
            int hammingWeight(unsigned int n);
    };

    /*
    Given a non-negative integer numRows, generate the first numRows of 
    Pascal's triangle.
    In Pascal's triangle, each number is the sum of the two numbers 
    directly above it.
    
    Input: 5
    Output:
    [
    [1],
    [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1]]
    
    Input: 3
    Output:
    [
    [1],
    [1,1],
    [1,2,1]
    ]
    */
    class _1355_PascalsTriangle{
        public:
            std::vector<std::vector<int>> generate(int numRows);
    };

    /*
    Description: We have a two dimensional matrix A where
    each value is 0 or 1. A move consists of choosing any 
    row or column, and toggling each value in that row or
    column: changing all 0s to 1s, and all 1s to 0s.
    After making any number of moves, every row of this 
    matrix is interpreted as a binary number, and the 
    score of the matrix is the sum of these numbers.
    
    Return the highest possible score.
    1 <= A.length <= 20
    1 <= A[0].length <= 20
    A[i][j] is 0 or 1.
    
    
    Example 1:
    Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
    Output: 39
    
    Explanation:
    Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
    0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

    Example 2:
    Input: [[1,1],[0,0],[1,0],[1,0],[1,1]]
    Output: 13
    Explanation:
    Toggled to [[1,1],[1,1],[1,0],[1,0],[1,1]].
    0b11 + 0b11 + 0b10 + ob10 + ob11 = 3 + 3 + 2 + 2 + 3= 13
    */
    class _1508_ScoreAfterFlippingMatrix{
        public:
            int matrixScore(std::vector<std::vector<int>>& A);

        private:
            void flipRow(std::vector<std::vector<int>>& A, int rowIdx);
            void flipCol(std::vector<std::vector<int>>& A, int colIdx);
            int countOnes(std::vector<std::vector<int>>& A, int colIdx);
            int toNum(std::vector<int>& v);
    };


    /*
    There is a special square room with mirrors on each of the four walls. 
    Except for the southwest corner, there are receptors on each of the 
    remaining corners, numbered 0, 1, and 2.
    
    The square room has walls of length p, and a laser ray from the southwest 
    corner first meets the east wall at a distance q from the 0th receptor.
    
    Return the number of the receptor that the ray meets first. (It is 
    guaranteed that the ray will meet a receptor eventually.)

    Input: p = 2, q = 1
    Output: 2
    Explanation: The ray meets receptor 2 the first time it gets reflected 
    back to the left wall.

    Input: p = 3, q = 1
    Output: 1
    Explanation: The ray meets receptor 1 the first time it gets reflected 
    back to the left wall.
    这道题完全抄答案的
    */
    class _1511_MirrorReflection {
        public:
            int mirrorReflection(int p, int q);
        private:
            int gcd(int p, int q);

    };

    /*
    Implement function ToLowerCase() that has a string parameter str, 
    and returns the same string in lowercase.
    */
    class _1535_ToLowerCase {
        public:
            std::string toLowerCase(std::string &str);
    };

    /*
    You have a list of words and a pattern, and you want to know which words
    in words matches the pattern. A word matches the pattern if there exists 
    a permutation of letters p so that after replacing every letter x in the 
    pattern with p(x), we get the desired word.
    (Recall that a permutation of letters is a bijection from letters to letters: 
    every letter maps to another letter, and no two letters map to the same letter.)
    
    Return a list of the words in words that match the given pattern.
    You may return the answer in any order.
    
    1 <= words.length <= 501<=words.length<=50
    1 <= pattern.length = words[i].length <= 201<=pattern.length=words[i].length<=20
    
    Example
    Example 1:
    Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
    Output: ["aqq","mee"]
    
    Explanation: 
    "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
    "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
    since a and b map to the same letter.
    
    Example 2:
    Input: words = ["a","b","c"], pattern = "a"
    Output: ["a","b","c"]
    */
    class _1592_FindAndReplacePattern {
        public:
            std::vector<std::string> findAndReplacePattern(std::vector<std::string> &words, std::string &pattern);
        private:
            bool samePattern(std::string& A, std::string& B);
    };
}

#endif
