#ifndef LEETCODE_TREEPROBLEMS_HPP
#define LEETCODE_TREEPROBLEMS_HPP
#include <unordered_map>
namespace LC {

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    /*
    Facebook
    Tag: Tree
    Given a binary tree, determine if it is a valid binary search tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

        2
       / \
      1   3

    Input: [2,1,3]
    Output: true

        5
       / \
      1   4
         / \
        3   6

    Input: [5,1,4,null,null,3,6]
    Output: false
    Explanation: The root node's value is 5 but its right child's value is 4.
    */
    class _0098_ValidateBinarySearchTree {
    public:
        bool isValidBST(TreeNode *root);
    };


    /*
    Tag: Tree
    Given two binary trees, write a function to check if they are the same or not.
    Two binary trees are considered the same if they are structurally identical 
    and the nodes have the same value.

    Input:     1         1
              / \       / \
             2   3     2   3

            [1,2,3],   [1,2,3]

    Output: true

    Input:     1         1
              /           \
             2             2

            [1,2],     [1,null,2]

    Output: false

    Input:     1         1
              / \       / \
             2   1     1   2

            [1,2,1],   [1,1,2]

    Output: false
    */
    class _0100_SameTree {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q);
    };


    /*
    A binary tree is given such that each node contains an additional random pointer which could point to any node in the tree or null.

    Return a deep copy of the tree.

    The tree is represented in the same input/output way as normal binary trees where each node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (in the input) where the random pointer points to, or null if it does not point to any node.
    You will be given the tree in class Node and you should return the cloned tree in class NodeCopy. NodeCopy class is just a clone of Node class with the same attributes and constructors.

    

    Example 1:


    Input: root = [[1,null],null,[4,3],[7,0]]
    Output: [[1,null],null,[4,3],[7,0]]
    Explanation: The original binary tree is [1,null,4,7].
    The random pointer of node one is null, so it is represented as [1, null].
    The random pointer of node 4 is node 7, so it is represented as [4, 3] where 3 is the index of node 7 in the array representing the tree.
    The random pointer of node 7 is node 1, so it is represented as [7, 0] where 0 is the index of node 1 in the array representing the tree.
    Example 2:


    Input: root = [[1,4],null,[1,0],null,[1,5],[1,5]]
    Output: [[1,4],null,[1,0],null,[1,5],[1,5]]
    Explanation: The random pointer of a node can be the node itself.
    Example 3:


    Input: root = [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
    Output: [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
    Example 4:

    Input: root = []
    Output: []
    Example 5:

    Input: root = [[1,null],null,[2,null],null,[1,null]]
    Output: [[1,null],null,[2,null],null,[1,null]]
    */
    class _1485_CloneBinaryTreeWithRandomPointer {
        struct Node {
            int val;
            Node *left;
            Node *right;
            Node *random;
            Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
            Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
            Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
        };

        struct NodeCopy {
            int val;
            NodeCopy *left;
            NodeCopy *right;
            NodeCopy *random;
            NodeCopy() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
            NodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
            NodeCopy(int x, NodeCopy *left, NodeCopy *right, NodeCopy *random) : val(x), left(left), right(right), random(random) {}
        };
        
        private:
            std::unordered_map<Node*, NodeCopy*> map;
        public:
            NodeCopy* copyRandomBinaryTree(Node* root);
    };
}
#endif