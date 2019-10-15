#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "Tree.hpp"
#include "LinkList.hpp"

#include "ProblemSet1.hpp" // Problem 1 - 100


namespace LeetCode
{


/*
        Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
    For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :

          1
         / \
        2   2
       / \ / \
      3  4 4  3

    But the following[1, 2, 2, null, 3, null, 3] is not:
           1
          / \
         2   2
          \   \
           3   3
    Note:
    Bonus points if you could solve it both recursively and iteratively.

    Solution:  utilize the preorder framework
    */
class _0101_SymmetricTree
{
public:
    bool isSymmetric(TreeNode<int> *root);

private:
    bool preOrderIter(TreeNode<int> *root);
};

/* Binary Tree Level Order Traversal II
    Given a binary tree, return the bottom - up level order traversal of 
    its nodes' values. (ie, from left to right, level by level from leaf to root).
    
    For example :
    Given binary tree[3, 9, 20, null, null, 15, 7],
       3
      / \
     9  20
    / \
  15   7
    return its bottom - up level order traversal as :
    [
        [15, 7],
        [9, 20],
        [3]
    ]
    */
class _0107_BinaryTreeLevelOrderTraversalII
{
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode<int> *root);
};

/* Convert Sorted Array to Binary Search Tree
    Given an array where elements are sorted in ascending order, 
    convert it to a height balanced BST.
    
    For this problem, a height-balanced binary tree is defined as a binary tree in
    which the depth of the two subtrees of every node never differ by more than 1.
    
    Example:
    Given the sorted array: [-10,-3,0,5,9],
    One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
                 0
                / \
              -3   9
              /   /
            -10  5
    */
class _0108_ConvertSortedArrayToBinarySearchTree
{
public:
    TreeNode<int> *sortedArrayToBST(std::vector<int> &nums);

private:
    TreeNode<int> *bst(std::vector<int> &nums, int start, int end);
};

/*
    You are given a perfect binary tree where all leaves are on the same level, 
    and every parent has two children. The binary tree has the following definition:

    Populate each next pointer to point to its next right node. If there is no next 
    right node, the next pointer should be set to NULL.
    Initially, all next pointers are set to NULL.
    */
class _0116_PopulatingNextRightPointerInEachNode
{
public:
    class Node
    {
    public:
        int val;
        Node *left;
        Node *right;
        Node *next;
    };

    void connect(Node *root);
};

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class _0120_Triangle{
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle);
};


/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell 
one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.
Input: [7,1,5,3,6,4]                   :                   Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Input: [7,6,4,3,1]                     :                   Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
class _0121_BestTimeToBuyAndSellStock {
public:
// Solution : 
// The points of interest are the peaks and valleys in the given graph. We need to find 
// the largest peak following the smallest valley. We can maintain two variables - minprice 
// and maxprofit corresponding to the smallest valley and maximum profit (maximum 
// difference between selling price and minprice) obtained so far respectively.
    int maxProfit(std::vector<int>& prices);
};


class _0133_CloneGraph {
    
public:
    class Node {
        public:
            int val;
            std::vector<Node*> neighbors;
            Node(){}
            Node(int _val, std::vector<Node*> _neighbors): val(_val), neighbors(_neighbors) {}
    };
    Node* cloneGraph(Node* node);
private:
    std::unordered_map<Node*, Node*> map;
};


// Sort a linked list in O(NlogN) time using constant space complexity.
class _0148_SortList
{
public:
    ListNode<int> *sortList(ListNode<int> *head);

private:
    ListNode<int> *merge(ListNode<int> *head1, ListNode<int> *head2);
    void splitList(ListNode<int> *&head, ListNode<int> *&left, ListNode<int> *&right);
};

/*
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
        push(x) -- Push element x onto stack.
        pop() -- Removes the element on top of the stack.
        top() -- Get the top element.
        getMin() -- Retrieve the minimum element in the stack.
    Example:
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.getMin();   --> Returns -3.
        minStack.pop();
        minStack.top();      --> Returns 0.
        minStack.getMin();   --> Returns -2.
    */
class _0155_MinStack
{
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    /** initialize your data structure here. */
    _0155_MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized 
with the root node of a BST. Calling next() will return the next smallest number in the BST.
BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false
 
Note:
next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the 
height of the tree. You may assume that next() call will always be valid, that is, there 
will be at least a next smallest number in the BST when next() is called.
*/
class _0173_BinarySearchTreeIterator {
public:
    _0173_BinarySearchTreeIterator(TreeNode<int>* root);
    
    /** @return the next smallest number */
    int next();
    
    /** @return whether we have a next smallest number */
    bool hasNext();
private:
    std::stack<TreeNode<int>*> st;
};

class _0190_ReverseBits
{
    /*
            Reverse bits of a given 32 bits unsigned integer.
            Example 1:
            Input: 00000010100101000001111010011100
            Output : 00111001011110000010100101000000
            Explanation : The input binary string 00000010100101000001111010011100 
            represents the unsigned integer 43261596, so return 964176192 which 
            its binary representation is 00111001011110000010100101000000.
            Example 2 :
            Input : 11111111111111111111111111111101
            Output : 10111111111111111111111111111111
            Explanation : The input binary string 11111111111111111111111111111101 
            represents the unsigned integer 4294967293, so return 3221225471 which 
            its binary representation is 10101111110010110010011101101001.

            Note :
            Note that in some languages such as Java, there is no unsigned integer 
            type. In this case, both input and output will be given as signed integer 
            type and should not affect your implementation, as the internal binary 
            representation of the integer is the same whether it is signed or unsigned.
            In Java, the compiler represents the signed integers using 2's complement 
            notation. Therefore, in Example 2 above the input represents the signed 
            integer -3 and the output represents the signed integer -1073741825.
        */
public:
    uint32_t reverseBits(uint32_t n);
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
};

/*
    Given a nested list of integers, implement an iterator to flatten it.
    Each element is either an integer, or a list -- whose elements may 
    also be integers or other lists.

    Example 1:
    Input: [[1,1],2,[1,1]]
    Output: [1,1,2,1,1]
    Explanation: By calling next repeatedly until hasNext returns false, 
    the order of elements returned by next should be: [1,1,2,1,1].

    Example 2:
    Input: [1,[4,[6]]]
    Output: [1,4,6]
    Explanation: By calling next repeatedly until hasNext returns false, 
    the order of elements returned by next should be: [1,4,6].
*/

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};
// TODO: COPY FROM A SOLUTION
class _0341_FlattenNestedListIterator
{
private:
    std::vector<NestedInteger> nl;
    _0341_FlattenNestedListIterator *itr = nullptr;
    int index = -1;

public:
    _0341_FlattenNestedListIterator(std::vector<NestedInteger> &nestedList);

    int next();
    bool hasNext();
    bool hasContent(std::vector<NestedInteger> V);
    void increaseIndex();
};

/*
    Given an integer (signed 32 bits), write a function 
    to check whether it is a power of 4.
    
    Example 1:
        Input: 16
        Output: true
    Example 2:
        Input: 5
        Output: false
    Follow up: Could you solve it without loops/recursion?
    */
class _0342_PowerOfFour
{
public:
    bool isPowerOfFour(int num);
};

/*
Given a positive integer n, break it into the sum of at least two 
positive integers and maximize the product of those integers. Return 
the maximum product you can get.

Input: 2      :       Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Input: 10     :       Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
*/
class _0343_IntegerBreak {
public:
    int intergerBreak(int n);
};

/*
Given two arrays, write a function to compute their intersection.

Input: nums1 = [1,2,2,1], nums2 = [2,2]           :          Output: [2,2]
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]       :          Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
class _0350_IntersectionOfTwoArraysII {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);
};

/*
        Given a non-negative integer n, count all numbers with unique 
        digits, x, where 0 ≤ x < pow(10, n).
        
        Example:
        Input: 2
        Output: 91 
        Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
                     excluding 11,22,33,44,55,66,77,88,99
    */
class _0357_CountNumbersWithUniqueDigits
{
public:
    int countNumbersWithUniqueDigits(int n);

private:
    // For n-digits, it is a simple combination problem
    // The first digit has 9 choices.
    // From the second digits, 9 , 8, 7 ... selections until 1
    int countExactDigit(int n);
};

/*
Calculate the sum of two integers a and b, but you 
are not allowed to use the operator + and -.

Example 1:
    Input: a = 1, b = 2
    Output: 3
Example 2:
    Input: a = -2, b = 3
    Output: 1
*/
class _0371_SumOfTwoIntegers
{
public:
    int getSum(int a, int b);
};

/*
    Given a n x n matrix where each of the rows and columns 
    are sorted in ascending order, find the kth smallest element 
    in the matrix.
    
    Note that it is the kth smallest element in the sorted order, 
    not the kth distinct element.
    
    Example:
    matrix = [
            [ 1,  5,  9],
            [10, 11, 13],
            [12, 13, 15]
    ], k = 8, 
    
    return 13.
*/
class _0378_KthSmallestElementInASortedMatrix
{
public:
    int kthSmallest(std::vector<std::vector<int>> &matrix, int k);

private:
    int search_less_equal(std::vector<std::vector<int>> &matrix, int target);
};

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
Given scores of N athletes, find their relative 
ranks and the people with the top three highest scores, 
who will be awarded medals: "Gold Medal", "Silver Medal" 
and "Bronze Medal".

Example 1:
    Input: [5, 4, 3, 2, 1]
    Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
    Explanation: The first three athletes got the top three 
    highest scores, so they got "Gold Medal", "Silver Medal" and 
    "Bronze Medal".
    For the left two athletes, you just need to output their relative 
    ranks according to their scores.
Note:
    N is a positive integer and won't exceed 10,000.
    All the scores of athletes are guaranteed to be unique.
*/
class _0506_RelativeRanks
{
public:
    std::vector<std::string> findRelativeRanks(std::vector<int> &nums);
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
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> pq;
        for(auto s : stones) {
            pq.push(s);
        }
        while(pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a == b) {
                continue;
            } else {
                pq.push(a - b);
            }
        }
        if(pq.empty()) {
            return 0;
        }
        return pq.top();
    }
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


} // namespace LeetCode


namespace LintCode {
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