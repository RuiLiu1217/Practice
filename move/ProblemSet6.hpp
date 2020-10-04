#ifndef PROBLEM_SET6_HPP
#define PROBLEM_SET6_HPP

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


class _0621_TaskScheduler {
public:
    int leastInterval(std::vector<char>& tasks, int n);
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