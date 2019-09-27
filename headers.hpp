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
    }
}