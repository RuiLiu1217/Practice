#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "Tree.hpp"
#include "LinkList.hpp"



namespace LeetCode{
    // class _0004_MedianOfTwoSortedArrays {
    //     public:
    //         double findMedianOfSortedArrays(
    //             std::vector<int>& nums1,
    //             std::vector<int>& nums2);

    // };

    class _0005_LongestPalindromicSubstring{
        public:
            std::string longestPalidrome(std::string s);
        private:
            int expandAroundCenter(std::string& s, int i , int j);
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
    class _0039_CombinationSum{
        public:
            std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);
        private:
            void combinationSum(std::vector<int>& candidates, int target, std::vector<int>& tmp, std::vector<std::vector<int>>& res);
    };


    /*
        Given a collection of [distinct] integers, return all possible permutations
    Example:
        Input: [1,2,3]
        Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
    */
    class _0046_Permutations {
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
    class _0048_RotateImage {
        public:
            void rotate(std::vector<std::vector<int>>& matrix);
    };

    // Validate a binary tree is BST or not
    class _0098_ValidateBinarySearchTree {
        public:
            bool isValidBST(TreeNode<int>* root);
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
    class _0101_SymmetricTree {
        public:
            bool isSymmetric(TreeNode<int>* root);
        private:
            bool preOrderIter(TreeNode<int>* root);
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
    class _0107_BinaryTreeLevelOrderTraversalII {
        public:
            std::vector<std::vector<int>> levelOrderBottom(TreeNode<int>* root);

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
    class _0108_ConvertSortedArrayToBinarySearchTree {
        public:
            TreeNode<int>* sortedArrayToBST(std::vector<int>& nums);
        private:
            TreeNode<int>* bst(std::vector<int>& nums, int start, int end);
    };

    /*
    You are given a perfect binary tree where all leaves are on the same level, 
    and every parent has two children. The binary tree has the following definition:

    Populate each next pointer to point to its next right node. If there is no next 
    right node, the next pointer should be set to NULL.
    Initially, all next pointers are set to NULL.
    */
    class _0116_PopulatingNextRightPointerInEachNode {
        public:
        struct Node {
            int val;
            Node *left;
            Node *right;
            Node *next;
        };

        void connect(Node* root);
    };

    // Sort a linked list in O(NlogN) time using constant space complexity.
    class _0148_SortList {
        public:
            ListNode<int>* sortList(ListNode<int>* head);
        private:
            ListNode<int>* merge(ListNode<int>* head1, ListNode<int>* head2);
            void (ListNode<int>*& head, ListNode<int>*& left, ListNode<int>*& right)；
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
    class _0155_MinStack {
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


    class _0190_ReverseBits {
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



    class _0235_LowestCommonAncestor{
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

    class _0260_SingleNumberII{
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
            std::vector<int> singleNumber(const std::vector<int>& nums);
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
    class _0290_WordPattern {
        public:
            bool wordPattern(std::string pattern, std::string str);
    };
}