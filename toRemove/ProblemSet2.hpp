#ifndef PROBLEM_SET2_HPP
#define PROBLEM_SET2_HPP

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
Tag: palindrome, KMP
TODO: Familar with KMP algorithm, especially how to calculate the next[] array

Given a string s, you are allowed to convert it to a palindrome by 
adding characters in front of it. Find and return the shortest 
palindrome you can find by performing this transformation.

Input: "aacecaaa"           :          Output: "aaacecaaa"
Input: "abcd"               :          Output: "dcbabcd"
Credits:
Special thanks to @ifanchu for adding this problem and creating all test 
cases. Thanks to @Freezen for additional test cases. 
*/
class _0214_ShortestPalindrome {
public:
    std::string shortestPalindrome(std::string s);
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
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a
distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo 
(Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

Buildings Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are 
the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed 
that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles 
grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], 
[19 24 8] ] .
The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that 
uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, 
where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. 
Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], 
[11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: 
[...[2 3], [4 5], [12 7], ...]
*/
//https://youtu.be/8Kd-Tn_Rz7s
class _0218_TheSkylineProblem {
    public:
        std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings);
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
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
class _0224_BasicCalculator {
public:
    int calculate(std::string s);
private:
    void pushNum(std::stack<double>& numStack, std::string& tmp);
    void cal(std::stack<double>& numStack, char op);
    int priority(char op);
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
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Input: "3+2*2"       :         Output: 7
Input: " 3/2 "       :         Output: 1
Input: " 3+5 / 2 "   :         Output: 5

Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
class _0227_BasicCalculatorII {
public:
    int calculate(std::string s);
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
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.

Input: [3,2,3]
Output: [3]

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/
class _0229_MajorityElementII {
public:
    std::vector<int> majorityElement(std::vector<int>& nums);
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

/*
Given an integer n, count the total number of digit 1 appearing 
in all non-negative integers less than or equal to n.

Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

Hint:
Beware of overflow.
*/
class _0233_NumberOfDigitOne {
public:
    int countDigitOne(int n);
};

/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/
class _0234_PalindromeLinkedList {
public:
    bool isPalindrome(ListNode<int>* head);
private:
    ListNode<int>* reverse(ListNode<int>* head);
};


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
class _0235_LowestCommonAncestor{ 
public:
    TreeNode<int> *lowestCommonAncestorRecursive(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q);
    TreeNode<int> *lowestCommonAncestorIterative(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q);
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
Given an array nums, there is a sliding window of size k which is moving from the 
very left of the array to the very right. You can only see the k numbers in the 
window. Each time the sliding window moves right by one position. Return the max 
sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/
class _0239_SlidingWindowMaximum {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);
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
class _0240_SearchA2DMatrix_II {
private:
    std::map<std::string, std::vector<int>> map;
public:
    bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target);
};

/*
Given a string of numbers and operators, return all possible results from computing 
all the different possible ways to group numbers and operators. The valid operators 
are +, - and *.

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/
class _0241_DifferentWaysToAddParentheses {
private:
    std::unordered_map<std::string, std::vector<int>> map;
public:
    std::vector<int> diffWaysToCompute(std::string input);
    std::vector<int> diffWaysToComp(const std::string& input, int start, int end);
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
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/
class _0243_ShortestWordDistance {
public:
    int shortestDistance(std::vector<std::string>& words, std::string word1, std::string word2);
};

/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
Note:
You may assume word1 and word2 are both in the list.
*/
class _0245_ShortestWordDistanceIII {
public:
    int shortestWordDistance(std::vector<std::string>& words, std::string word1, std::string word2);
};

/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false
*/
class _0246_StrobogrammaticNumber {
public:
    bool isStrobogrammatic(std::string num);
};

/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.

Example:

Input:  n = 2
Output: ["11","69","88","96"]
*/
class _0247_StrobogrammaticNumberII {
public:
    std::vector<std::string> findStrobogrammatic(int n);
private:
    void DFS(std::unordered_set<char> set, int curLen, int n, std::string tmp, std::vector<std::string>& res);
};

/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/
class _0249_GroupShiftedStrings {
public:
    std::vector<std::vector<std::string>> groupStrings(std::vector<std::string>& strings);
    std::string transback(std::string& s);
};

/*
Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.

Input:  root = [5,1,5,5,5,null,5]

        5
       / \
      1   5
     / \   \
    5   5   5

Output: 4
*/
class _0250_CountUnivalueSubtrees {
public:
    int countUnivalSubtrees(TreeNode<int>* root);
private:
    int count = 0;
    bool isUnique(TreeNode<int>* root);
};

/*
Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.

Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // return 1
iterator.next(); // return 2
iterator.next(); // return 3
iterator.hasNext(); // return true
iterator.hasNext(); // return true
iterator.next(); // return 4
iterator.hasNext(); // return false

Notes:

Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted across multiple test cases. Please see here for more details.
You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector when next() is called.

Follow up:

As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/
class _0251_Flatten2DVector {
private:
    std::vector<std::vector<int>>::iterator i, iEnd;
    int j = 0;
public:
    _0251_Flatten2DVector(std::vector<std::vector<int>>& v);
    int next();
    bool hasNext();
};

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Input: [[0,30],[5,10],[15,20]]
Output: false

Input: [[7,10],[2,4]]
Output: true
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class _0252_MeetingRooms {
public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals);
};

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
Input: [[0, 30],[5, 10],[15, 20]]            :         Output: 2
Input: [[7,10],[2,4]]                        :         Output: 1
*/
class _0253_MeetingRoomsII {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals);
};

/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:

You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Example 1:

Input: 1
Output: []
Example 2:

Input: 37
Output:[]
Example 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Example 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/
class _0254_FactorCombinations {
public:
    // Copy from the solution
    std::vector<std::vector<int>> getFactors(int n);
private:
    void DFS(std::vector<std::vector<int>>& res, std::vector<int>& tmp, int n);
};

/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Consider the following binary search tree: 

     5
    / \
   2   6
  / \
 1   3
Example 1:

Input: [5,2,6,1,3]
Output: false
Example 2:

Input: [5,2,1,3,6]
Output: true
Follow up:
Could you do it using only constant space complexity?
*/
class _0255_VerifyPreorderSequenceInBinarySearchTree {
public:
    bool verifyPreorder(std::vector<int>& preorder);
    bool isPreorder(std::vector<int>& preorder, int startIdx, int endIdx);
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
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a 
pair of nodes), write a function to check whether these edges make up a valid tree.

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges 
are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
*/
class _0261_GraphValidTree {
public:
    bool validTree(int n, std::vector<std::vector<int>>& edges);
    bool DFS(std::vector<std::unordered_set<int>>& graph, std::vector<int>& visited, int source, int target);
};

class _0262_TripsAndUsers; // it s a MySQL problem

/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:

Input: 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2
Example 3:

Input: 14
Output: false 
Explanation: 14 is not ugly since it includes another prime factor 7.
Note:

1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range: [−231,  231 − 1].
*/
class _0263_UglyNumber {
public:
    bool isUgly(int num);
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
Given a string, determine if a permutation of the string could form a palindrome.
Input: "code"       :      Output: false
Input: "aab"        :      Output: true
Input: "carerac"    :      Output: true
*/
class _0266_PalinndromePermutation {
public:
    bool canPermutePalindrome(std::string s);
};

/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:

Input: "aabb"
Output: ["abba", "baab"]
Example 2:

Input: "abc"
Output: []
*/
class _0267_PalindromePermutationII {
public:
    std::vector<std::string> generatePalindromes(std::string s);
private:
    void backtracking(std::string hs, int level, std::vector<int>& visited, std::string& tmp, std::vector<std::string>& res);
};

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Input: [3,0,1]               :         Output: 2
Input: [9,6,4,2,3,5,7,0,1]   :         Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/
class _0268_MissingNumber {
public:
    // How to deal with overflow?
    int missingNumber(std::vector<int>& nums);
};

/*

Facebook

There is a new alien language which uses the latin alphabet. However, 
the order among letters are unknown to you. You receive a list of 
non-empty words from the dictionary, where words are sorted lexicographically 
by the rules of this new language. Derive the order of letters in 
this language.

Input:
["wrt", "wrf", "er", "ett", "rftt"]
Output: "wertf"

Input:
["z", "x"]
Output: "zx"

Input:
["z", "x", "z"] 
Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b 
in the given dictionary. If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/
class _0269_AlienDictionary {
public:
    std::string alienOrder(std::vector<std::string>& words);
private:
    std::vector<int> topologicalSort(std::vector<std::vector<int>>& adjList);
};

/*
Given a non-empty binary search tree and a target value, find the 
value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that 
is closest to the target.

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3
Output: 4
*/
class _0270_ClosetBinarySearchTreeValue {
public:
    int closestValue(TreeNode<int>* root, double target); 
};

/*
Tag: serialization

Google, but I don't know why I cannot get a correct result

Design an algorithm to encode a list of strings to a string. 
The encoded string is then sent over the network and is decoded 
back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

The string may contain any possible characters out of 256 valid ascii characters. 
Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and 
decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should 
implement your own encode/decode algorithm.
*/
class _0271_EncodeAndDecodeStrings {
/////////////////////////////////////////
};

/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Input: 123
Output: "One Hundred Twenty Three"

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/
class _0273_IntegerToEnglishWords {
public:
    std::string numberToWords(int num);
};

/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3 
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
             received 3, 0, 6, 1, 5 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/
class _0274_HIndex {
public:
    int hIndex(std::vector<int>& citations);
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
There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.

Example:

Input: n = 3, k = 2
Output: 6
Explanation: Take c1 as color 1, c2 as color 2. All possible ways are:

            post1  post2  post3      
 -----      -----  -----  -----       
   1         c1     c1     c2 
   2         c1     c2     c1 
   3         c1     c2     c2 
   4         c2     c1     c1  
   5         c2     c1     c2
   6         c2     c2     c1
*/
class _0276_PaintFence {
public:
    int numWays(int n, int k);
};

/*
Facebook

You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. Since 
each version is developed based on the previous version, all the versions after 
a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad 
one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version 
is bad. Implement a function to find the first bad version. You should minimize 
the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
*/
class _0278_FirstBadVersion {
public:
    int firstBadVersion(int n);
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
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]
*/
class _0280_WiggleSort {
public:
    void wiggleSort(std::vector<int>& nums);
};

/*
Given two 1d vectors, implement an iterator to return their elements alternately.

Input:
v1 = [1,2]
v2 = [3,4,5,6] 
Output: [1,3,2,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of 
elements returned by next should be: [1,3,2,4,5,6].
 
Follow up:

What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question:
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. 
If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

Input:
[1,2,3]
[4,5,6,7]
[8,9]

Output: [1,4,8,2,5,9,3,6,7].
*/
class _0281_ZigzagIterator {
private:
    std::vector<std::vector<int>::iterator> it;
    std::vector<std::vector<int>::iterator> endIt;
    int N; 
    int i;
public:
    _0281_ZigzagIterator(std::vector<int>&v1, std::vector<int>& v2);
    int next();
    bool hasNext();
};

/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to 
add binary operators (not unary) +, -, or * between the digits so they evaluate to the target 
value.

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"] 

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]

Input: num = "3456237490", target = 9191
Output: []
*/
class _0282_ExpressionAddOperators {
public:
    std::vector<std::string> addOperators(std::string num, int target);
private:
    void DFS(const std::string& num, const int target, int pos, std::string exp, long prev, long curr, std::vector<std::string>& ans);
};

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
class _0283_MoveZeros {
public:
    void moveZeroes(std::vector<int>& nums);
};


/*
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() 
operation -- it essentially peek() at the element that will be returned by the next call to next().


Assume that the iterator is initialized to the beginning of the list: [1,2,3].

Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2. 
You call next() the final time and it returns 3, the last element. 
Calling hasNext() after that should return false.
Follow up: How would you extend your design to be generic and work with all types, not just integer?
*/
class Iterator {
public:
    struct Data {};
    Data* data;
    Iterator(const std::vector<int>& nums) {

    }
    Iterator(const Iterator& iter);

    int next();
    bool hasNext() const;
};

class _0284_PeekingIterator : public Iterator {
public:
    _0284_PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {}
    int peek() {
        return Iterator(*this).next(); // The only difficulty is why here?
    }
    int next() {
        return Iterator::next();
    }
    bool hasNext() const {
        return Iterator::hasNext();
    }
};

/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
The successor of a node p is the node with the smallest key greater than p.val.

Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.

Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 
Note:

If the given node has no in-order successor in the tree, return null.
It's guaranteed that the values of the tree are unique.

*/
class _0285_InorderSuccessorInBST {
private:
    std::stack<TreeNode<int>*> st;
    TreeNode<int>* getNext();
public:
    TreeNode<int>* inorderSuccessor(TreeNode<int>* root, TreeNode<int>* p);
};

/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/
class _0286_WallsAndGates {
public:
    void wallsAndGates(std::vector<std::vector<int>>& rooms);
};

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.


Input: [1,3,4,2,2]
Output: 2

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
class _0287_FindTheDuplicateNumber {
public:
    int findDuplicate(std::vector<int>& nums);
};

/*
Tag: hash
Google

An abbreviation of a word follows the form <first letter><number><last letter>. 
Below are some examples of word abbreviations:
a) it --> it    (no abbreviation)

     1
     ↓
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
     ↓   ↓    ↓    ↓  ↓    
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
     ↓   ↓    ↓
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is 
unique in the dictionary. A word's abbreviation is unique if no other word from 
the dictionary has the same abbreviation.

Example:
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/
class _0288_UniqueWordAbbreviation {
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> mp;
public:
    _0288_UniqueWordAbbreviation(std::vector<std::string>& dictionary);
    bool isUnique(std::string word);
};

/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using 
the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current 
state. The next state is created by applying the above rules simultaneously to every cell in
the current state, where births and deaths occur simultaneously.

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: 
You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, 
which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/
class _0289_GameOfLife {
public:
    void gameOfLife(std::vector<std::vector<int>>& board);
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
You are playing the following Nim Game with your friend: There is a heap of stones 
on the table, each time one of you take turns to remove 1 to 3 stones. The one who 
removes the last stone will be the winner. You will take the first turn to remove the stones.
Both of you are very clever and have optimal strategies for the game. Write a 
function to determine whether you can win the game given the number of stones in the heap.

Input: 4
Output: false 
Explanation: If there are 4 stones in the heap, then you will never win the game;
             No matter 1, 2, or 3 stones you remove, the last stone will always be 
             removed by your friend.
*/
class _0292_NimGame {
public:
    bool canWinNim(int n);
};


/*
You are playing the following Flip Game with your friend: Given a string that contains 
only these two characters: + and -, you and your friend take turns to flip two consecutive
"++" into "--". The game ends when a person can no longer make a move and therefore the 
other person will be the winner.
Write a function to compute all possible states of the string after one valid move.

Input: s = "++++"
Output: 
[
  "--++",
  "+--+",
  "++--"
]
Note: If there is no valid move, return an empty list [].
*/
class _0293_FlipGame {
public:
    std::vector<std::string> generatePossibleNextMoves(std::string s);
};

/*
Facebook

Serialization is the process of converting a data structure or object into a 
sequence of bits so that it can be stored in a file or memory buffer, or 
transmitted across a network connection link to be reconstructed later in the 
same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no 
restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and 
this string can be deserialized to the original tree structure.

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary 
tree. You do not necessarily need to follow this format, so please be creative 
and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your 
serialize and deserialize algorithms should be stateless.
*/
class _0297_SerializeAndDeserializeBinaryTree {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode<int>* root);
    // Decodes your encoded data to tree.
    TreeNode<int>* deserialize(std::string data);
};

/*
You are playing the following Bulls and Cows game with your friend: You write down 
a number and ask your friend to guess what the number is. Each time your friend 
makes a guess, you provide a hint that indicates how many digits in said guess match 
your secret number exactly in both digit and position (called "bulls") and how many 
digits match the secret number but locate in the wrong position (called "cows"). 
Your friend will use successive guesses and hints to eventually derive the secret 
number.
Write a function to return a hint according to the secret number and friend's guess, 
use A to indicate the bulls and B to indicate the cows. 
Please note that both secret number and friend's guess may contain duplicate digits.

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:
Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
Note: You may assume that the secret number and your friend's guess only contain 
digits, and their lengths are always equal.
*/
class _0299_BullsAndCows {
public:
    std::string getHint(std::string secret, std::string guess);
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