#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

namespace LeetCode
{

    /*
    Given an array of integers, return indices of the two 
    numbers such that they add up to a specific target.
    You may assume that each input would have exactly one 
    solution, and you may not use the same element twice.
    Example:
        Given nums = [2, 7, 11, 15], target = 9,
        Because nums[0] + nums[1] = 2 + 7 = 9,
    Return [0, 1].
    */
    class _0001_TwoSum{
        public:
            std::vector<int> twoSum(std::vector<int>& nums, int target);
    };


// class _0004_MedianOfTwoSortedArrays {
//     public:
//         double findMedianOfSortedArrays(
//             std::vector<int>& nums1,
//             std::vector<int>& nums2);

// };

class _0005_LongestPalindromicSubstring
{
public:
    std::string longestPalidrome(std::string s);

private:
    int expandAroundCenter(std::string &s, int i, int j);
};

/*
Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21
*/
class _0007_ReverseInteger{
public:
    int reverse(int x);
};

/*
Determine whether an integer is a palindrome. An integer is a 
palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, 
it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
class _0009_PalindromeNumber{
public:
    bool isPalindrome(int x);
};



/*
Suppose an array sorted in ascending order is rotated at some pivot 
unknown to you beforehand. 
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return 
its index, otherwise return -1. You may assume no duplicate exists 
in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
// TODO: Modification of the binary search. Needs remember.
class _0033_SearchInRotatedSortedArray {
public:
    int search(std::vector<int>& nums, int target);
};



/*
    TODO: Modification of the binary search
Given an array of integers nums sorted in ascending order, find the 
starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class _0034_FindFirstAndLastPositionOfElementInSortedArray {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target);
};

/*
The count-and-say sequence is the sequence of integers with the first five 
terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
Note: Each term of the sequence of integers will be represented as a string.
*/
class _0038_CountAndSay {
public:
    std::string countAndSay(int n);
private:
    std::string countOnce(std::string& s);
};


/*  
    Given a set of candidate numbers (candidates without duplicates) 
    and a target number (target), find all unique combinations in 
    candidates where the candidate numbers sums to target.
    
    The same repeated number may be chosen from candidates unlimited number of times.
    Note:
        All numbers (including target) will be positive integers.
        The solution set must not contain duplicate combinations.
    Example 1:
        Input: candidates = [2,3,6,7], target = 7,
    A solution set is:
        [  [7],  [2,2,3] ]
    Example 2:
        Input: candidates = [2,3,5], target = 8, 
    A solution set is:
        [  [2,2,2,2],  [2,3,3],  [3,5] ]
    */
class _0039_CombinationSum
{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target);

private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<int> &tmp, std::vector<std::vector<int>> &res);
};

/*
        Given a collection of [distinct] integers, return all possible permutations
    Example:
        Input: [1,2,3]
        Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
    */
class _0046_Permutations
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums);

private:
    void permuteRecursive(std::vector<int> &nums, int begin, std::vector<std::vector<int>> &result);
};

/* 
        You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
        Note: You have to rotate the image in-place, which means you have to modify the input 2D matrix 
        directly. DO NOT allocate another 2D matrix and do the rotation.
    */
class _0048_RotateImage
{
public:
    void rotate(std::vector<std::vector<int>> &matrix);
};

// Validate a binary tree is BST or not
class _0098_ValidateBinarySearchTree
{
public:
    bool isValidBST(TreeNode<int> *root);
};

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
class _0240_SearchA2DMatrix_II {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target);
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
class NestedInteger {
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
class _0341_FlattenNestedListIterator{
    private:
        std::vector<NestedInteger> nl;
        _0341_FlattenNestedListIterator* itr = nullptr;
        int index = -1;        
    public:
        _0341_FlattenNestedListIterator(std::vector<NestedInteger>& nestedList);

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
class _0378_KthSmallestElementInASortedMatrix {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k);
private:
    int search_less_equal(std::vector<std::vector<int>>& matrix, int target);
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
class _0401_BinaryWatch{
public:
    std::vector<std::string> readBinaryWatch(int num);

};


class _0404_SumOfLeftLeaves{
public:
    int sumOfLeftLeaves(TreeNode<int>* root);
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
class _0427_ConstructQuadTree {
public:
    QuadTreeNode* construct(std::vector<std::vector<int>>& grid);
    QuadTreeNode* construct(std::vector<std::vector<int>>& grid, 
    int rowStart, int rowEnd, int colStart, int colEnd);
private:
    bool areConsistent(std::vector<std::vector<int>>& grid);
    bool areConsistent(std::vector<std::vector<int>>& grid, 
    int rowStart, int rowEnd, int colStart, int colEnd);

    std::vector<std::vector<std::vector<int>>> divideGrid(std::vector<std::vector<int>>& grid);
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
class _0429_NaryTreelevelOrderTraversal{
public:
    std::vector<std::vector<int>> levelOrder(NaryTreeNode<int>* root);
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
class _0506_RelativeRanks{
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& nums);
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
class _1025_DivisorGame{
    public:
        bool divisorGame(int N);

};

} // namespace LeetCode