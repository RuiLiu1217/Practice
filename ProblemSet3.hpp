#ifndef PROBLEM_SET3_HPP
#define PROBLEM_SET3_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include "Tree.hpp"
#include "LinkList.hpp"
#include "Trie.hpp"
namespace LeetCode {


/*
Tag: bit operations
TODO: n & (n-1) trick
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/
class _0201_BitwiseANDofNumbersRange {
public:
    int rangeBitwiseAnd(int m, int n);
};

/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive 
integer, replace the number by the sum of the squares of its digits, and repeat the 
process until the number equals 1 (where it will stay), or it loops endlessly in a cycle 
which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/
class _0202_HappyNumber {
private:
    int gat(int n);
public:
    bool isHappy(int n);
};

/*
Remove all elements from a linked list of integers that have value val.

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/
class _0203_RemoveLinkedListElements {
public:
    ListNode<int>* removeElements(ListNode<int>* head, int val);
};

/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
class _0204_CountPrimes {
public:
    int countPrimes(int n);
};


/*
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same 
character but a character may map to itself.

Input: s = "egg", t = "add"
Output: true

Input: s = "foo", t = "bar"
Output: false

Input: s = "paper", t = "title"
Output: true
*/
class _0205_IsomorphicStrings {
public:
    bool isIsomorphic(std::string s, std::string t);
};

/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
class _0206_ReverseLinkedList {
public:
    ListNode<int>* reverseList(ListNode<int>* head);
};

/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to 
first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible 
for you to finish all courses?

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
class _0207_CourseSchedule {
    using Graph = std::vector<std::vector<int>>;
    Graph createGraph(int numCourses, std::vector<std::vector<int>>& prerequisites);
    bool isCyclicUtils(Graph g, int v, std::vector<bool>& visited, std::vector<bool>& recStack);
    std::vector<int> computeIndegrees(Graph& g);
public:    
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);
};

/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
class _0208_ImplementTrie {
public:
     /** Initialize your data structure here. */
    _0208_ImplementTrie();
    
    /** Inserts a word into the trie. */
    void insert(std::string word);
    
    /** Returns if the word is in the trie. */
    bool search(std::string word);

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix);
private:
    std::unordered_map<char, _0208_ImplementTrie*> children;
    bool isWord = false;
};

/*
Given an array of n positive integers and a positive integer s, find the minimal length 
of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/
class _0209_MinimumSizeSubarraySum {
public:
    int minSubArrayLen(int s, std::vector<int>& nums);
};

/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you 
have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of 
them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 
you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
There are a total of 4 courses to take. To take course 3 you should have finished both     
courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not 
adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
class _0210_CourseScheduleII {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites);
private:
     void BFS(const std::vector<std::vector<int>>& graph, std::vector<int>& inDegree, std::vector<int>& res);
};

/*
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string 
containing only letters a-z or .. A . means it can represent any one letter.

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/
class _0211_AddAndSearchWordDataStructureDesign {
    class TrieNode {
        public:
            bool word;
            TrieNode* children[26];
            TrieNode() {
                word = false;
                for(int i = 0; i < 26; ++i) {
                    children[i] = nullptr;
                }
            }
    };
public:
    _0211_AddAndSearchWordDataStructureDesign() {}
    void addWord(std::string word);
    bool search(std::string word);
private:
    TrieNode* root = new TrieNode();
    bool search(const char* word, TrieNode* node);
};

/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" 
cells are those horizontally or vertically neighboring. The same letter cell may not 
be used more than once in a word.

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Note:
All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/
class _0212_WordSearchII {
private:
    std::unordered_set<std::string> res;
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words);
    void findWords(std::vector<std::vector<char>>& board, int i, int j, const std::string& word, int idx);
};

/*
You are a professional robber planning to rob houses along a street. Each house 
has a certain amount of money stashed. All houses at this place are arranged in 
a circle. That means the first house is the neighbor of the last one. Meanwhile, 
adjacent houses have security system connected and it will automatically contact 
the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each 
house, determine the maximum amount of money you can rob tonight without alerting 
the police.

Input: [2,3,2]            :            Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
because they are adjacent houses.

Input: [1,2,3,1]          :            Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
这道题也是一下子蒙住了，实际上很简单，因为第一个房子和最后一个房子不能都抢，因此分别算两次，
即排除第一个房子的情况，以及排除最后一个房子的情况。然后取大的。
*/
class _0213_HouseRobberII {
public:
    int rob(std::vector<int>& nums);
private:
    int robHelp(std::vector<int>& nums);
};

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest 
element in the sorted order, not the kth distinct element.

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
class _0215_KthLargestElementInAnArray {
public:
    int findKthLargest(std::vector<int>& nums, int k);
};

/*
Find all possible combinations of k numbers that add up to a number n, given that 
only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.

Input: k = 3, n = 7
Output: [[1,2,4]]

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
class _0216_CombinationSumIII{
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n);
private:
    void DFS(int k, int n, int curV, std::vector<int>& tmp, std::vector<std::vector<int>>& res);
};

/*
217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in 
the array, and it should return false if every element is distinct.
Input: [1,2,3,1]
Output: true

Input: [1,2,3,4]
Output: false

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/
class _0217_ContainsDuplicate {
public:
    bool containsDuplicate(std::vector<int>& nums);
};

/*
Given an array of integers and an integer k, find out whether there are
two distinct indices i and j in the array such that nums[i] = nums[j]
and the absolute difference between i and j is at most k.

Input: nums = [1,2,3,1], k = 3
Output: true

Input: nums = [1,0,1,1], k = 1
Output: true

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/
class _0219_ContainsDuplicateII {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k);
};

/*
Given an array of integers, find out whether there are two distinct 
indices i and j in the array such that the absolute difference between 
nums[i] and nums[j] is at most t and the absolute difference between 
i and j is at most k.

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/
class _0220_ContainsDuplicateIII {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t);
};

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest 
square containing only 1's and return its area.

Input: 
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/
class _0221_MaximalSquare {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix);
};

/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the 
last, is completely filled, and all nodes in the last level 
are as far left as possible. It can have between 1 and 2h 
nodes inclusive at the last level h.

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
*/
class _0222_CountCompleteTreeNodes {
public:
    int countNodes(TreeNode<int>* root);
};

/*
Find the total area covered by two rectilinear rectangles 
in a 2D plane. Each rectangle is defined by its bottom left 
corner and top right corner as shown in the figure.
*/
class _0223_RectangleArea {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
};

/*
225. Implement Stack using Queues
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only 
push to back, peek/pop from front, size, and is empty operations are valid.

Depending on your language, queue may not be supported natively. You may 
simulate a queue by using a list or deque (double-ended queue), as long 
as you use only standard operations of a queue. You may assume that all 
operations are valid (for example, no pop or top operations will be 
called on an empty stack).
*/
class _0225_ImplementStackUsingQueues {
public:
    _0225_ImplementStackUsingQueues();

    void push(int x);

    int pop();

    int top();

    bool empty();

private:
    std::queue<int> nums;
};

/*
Invert a binary tree.
Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
class _0226_InvertBinaryTree {
public:
    TreeNode<int>* invertTree(TreeNode<int>* root);
};



/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/
class _0228_SummaryRange {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums);
};

/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth 
smallest frequently? How would you optimize the kthSmallest routine?
*/
class _0230_KthSmallestElementInABST {
public:
    int kthSmallest(TreeNode<int>* root, int k);
};

/*
Given an integer, write a function to determine if it is a power of two.

Input: 1
Output: true 
Explanation: 20 = 1

Input: 16
Output: true
Explanation: 24 = 16

Input: 218
Output: false
*/
class _0231_PowerOfTwo {
public:
    bool isPowerOfTwo(int n);
};

/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop
from top, size, and is empty operations are valid. Depending on your language, stack may 
not be supported natively. You may simulate a stack by using a list or deque (double-ended 
queue), as long as you use only standard operations of a stack. You may assume that all 
operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/
class _0232_ImplementQueueUsingStacks {
private:
    std::stack<int> left;
    std::stack<int> right;
public:
    _0232_ImplementQueueUsingStacks();
    void push(int x);
    int pop();
    int peek();
    bool empty();
};

class _0235_LowestCommonAncestor
{
    /*
            Given a binary search tree (BST), find the lowest common 
            ancestor (LCA) of two given nodes in the BST.
            
            According to the definition of LCA on Wikipedia: The lowest 
            common ancestor is defined between two nodes p and q as the 
            lowest node in T that has both p and q as descendants (where 
            we allow a node to be a descendant of itself).
            
            Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
                _______6______
               /              \
            ___2__          ___8__
           /      \        /      \
           0       4       7       9
         /  \
        3   5

        Example 1:
            Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
            Output: 6
            Explanation: The LCA of nodes 2 and 8 is 6.
        Example 2:
            Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
            Output: 2
            Explanation: The LCA of nodes 2 and 4 is 2, since a node 
            can be a descendant of itself according to the LCA definition.
        Note:
            All of the nodes' values will be unique. p and q are different 
            and both values will exist in the BST.
        Challenge: 
            Think about the case that the tree is not a binary search tree?
        */
public:
    TreeNode<int> *lowestCommonAncestorRecursive(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q);
    TreeNode<int> *lowestCommonAncestorIterative(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q);
};


/*
Given an array nums of n integers where n > 1,  return an array output 
such that output[i] is equal to the product of all the elements of nums 
except nums[i].

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array 
does not count as extra space for the purpose of space complexity 
analysis.)
*/
class _0238_ProductOfArrayExceptSelf {

};

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Note:
All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
*/
class _0236_LowestCommonAncestorOfABinaryTree {
public:
    TreeNode<int>* lowestCommonAncestor(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q);
};

/*
Write a function to delete a node (except the tail) in a singly linked list, 
given only access to that node.
Given linked list -- head = [4,5,1,9], which looks like following:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.

Note:

The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.
*/
class _0237_DeleteNodeInALinkedList {
public:
    void deleteNode(ListNode<int>* node);
};

/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal 
to the product of all the elements of nums except nums[i].

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space 
for the purpose of space complexity analysis.)
*/
class _0238_ProductOfArrayExceptSelf {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums);
};

/*
Write an efficient algorithm that searches for a value 
in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

    Consider the following matrix:
    [
        [1,   4,  7, 11, 15],
        [2,   5,  8, 12, 19],
        [3,   6,  9, 16, 22],
        [10, 13, 14, 17, 24],
        [18, 21, 23, 26, 30]
    ]
    Given target = 5, return true.
    Given target = 20, return false.
*/
class _0240_SearchA2DMatrix_II
{
public:
    bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target);
};

/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
class _0242_ValidAnagram {
public:
    bool isAnagram(std::string s, std::string t);
};


/*
Given a binary tree, return all root-to-leaf paths.
Note: A leaf is a node with no children.

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]
Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/
class _0257_BinaryTreePaths {
public:
    std::vector<std::string> binaryTreePaths(TreeNode<int>* root);
};

/*
Given a non-negative integer num, repeatedly add all its digits until the 
result has only one digit.

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
    Since 2 has only one digit, return it.
*/
class _0258_AddDigits {
public:
    int addDigits(int num);
};

class _0260_SingleNumberII
{
    /*
        Given an array of numbers nums, in which exactly two elements 
        appear only once and all the other elements appear exactly twice.
        Find the two elements that appear only once.
        
        Example:
            Input:  [1,2,1,3,2,5]
            Output: [3,5]
        Note:
        The order of the result is not important. So in the above example, 
        [5, 3] is also correct. Your algorithm should run in linear runtime 
        complexity. Could you implement it using only constant space 
        complexity?
        
        Solution
            1. assume that A and B are the two elements which we want to find;
            2. use XOR for all elements,the result is : r = A^B,we just need 
            to distinguish A from B next step;
            3. if we can find a bit '1' in r,then the bit in corresponding 
                position in A and B must be different.We can use 
                {last = r & (~(r-1))} to get the last bit 1 int r;
            4. we use last to divide all numbers into two groups,then A and B 
                must fall into the two distrinct groups. XOR elements in eash 
                group,get the A and B.
    */
public:
    std::vector<int> singleNumber(const std::vector<int> &nums);
};


/*
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  
1 is typically treated as an ugly number.
n does not exceed 1690.
*/
class _0264_UglyNumberII {
public:
    int nthUglyNumber(int n);
};

/*
Given an array of citations sorted in ascending order (each citation is a 
non-negative integer) of a researcher, write a function to compute the researcher's 
h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h 
if h of his/her N papers have at least h citations each, and the other N − h 
papers have no more than h citations each."

Input: citations = [0,1,3,5,6]
Output: 3 
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
             received 0, 1, 3, 5, 6 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.

If there are several possible values for h, the maximum one is taken as the h-index.

This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
Could you solve it in logarithmic time complexity?
*/
class _0275_HIndexII {
public:
    int hIndex(std::vector<int>& citations);
};

/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
class _0279_PerfectSquares {
public:
    int numSquares(int n);
};

/*
        Given a pattern and a string str, find if str follows the same pattern.
        Here follow means a full match, such that there is a bijection between a 
        letter in pattern and a non - empty word in str.
        
        Example 1:
            Input: pattern = "abba", str = "dog cat cat dog"
            Output : true
        Example 2 :
            Input : pattern = "abba", str = "dog cat cat fish"
            Output : false
        Example 3 :
            Input : pattern = "aaaa", str = "dog cat cat dog"
            Output : false
        Example 4 :
            Input : pattern = "abba", str = "dog dog dog dog"
            Output : false
        Notes :
            You may assume pattern contains only lowercase letters, and str 
            contains lowercase letters separated by a single space.
    */
class _0290_WordPattern
{
public:
    bool wordPattern(std::string pattern, std::string str);
private:
    std::unordered_map<char, std::string> map;
    std::unordered_map<std::string, char> map2;
};


/*
Given an unsorted array of integers, find the length of longest increasing 
subsequence.
Example:
Input: [10,9,2,5,3,7,101,18]       :       Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:
There may be more than one LIS combination, it is only necessary for you to return 
the length. Your algorithm should run in O(n2) complexity. 
Follow up: Could you improve it to O(n log n) time complexity?
*/
class _0300_LongestIncreasingSubsequence {
public:
    int lengthOfLIS(std::vector<int>& nums);
private:
    int lengthOfLIS_N2(std::vector<int>& nums);
    int lengthOfLIS_NlogN(std::vector<int>& nums);
};

}
#endif