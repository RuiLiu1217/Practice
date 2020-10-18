#ifndef LEETCODE_TREEPROBLEMS_HPP
#define LEETCODE_TREEPROBLEMS_HPP
#include <unordered_map>
#include <vector>
#include <stack>
#include <sstream>
#include <string>
namespace LC {

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    struct NAryNode {
        int val;
        std::vector<NAryNode*> children;

        NAryNode(){}
        NAryNode(int v) : val(v) {}
        NAryNode(int v, std::vector<NAryNode*> c) : val(v), children(c) {}
    };

    struct NaryTreeNode {
    public:
        int data;
        std::vector<NaryTreeNode*> children;
        NaryTreeNode() {}
        NaryTreeNode(int _val, std::vector<NaryTreeNode*> _children) {
            data = _val;
            children = _children;
        }
    };


    // Quad Tree
    struct QuadTreeNode {
    public:
        int val;
        bool isLeaf;
        QuadTreeNode *topLeft;
        QuadTreeNode *topRight;
        QuadTreeNode *bottomLeft;
        QuadTreeNode *bottomRight;
        QuadTreeNode() {}
        QuadTreeNode(int v, int isL, QuadTreeNode *tl, QuadTreeNode *tr, QuadTreeNode *bl, QuadTreeNode *br) {
            val = v;
            isLeaf = isL;
            topLeft = tl;
            topRight = tr;
            bottomLeft = bl;
            bottomRight = br;
        }
    };



    /*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class _0095_UniqueBinarySearchTreeII {
public:
    std::vector<TreeNode*> generateTrees(int n);
    std::vector<TreeNode*> generateTreeHelper(int l, int r);
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
Tag: Tree
Given a binary tree, check whether it is a mirror of itself 
(ie, symmetric around its center). For example, this binary 
tree[1, 2, 2, 3, 4, 4, 3] is symmetric:
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
    bool isSymmetric(TreeNode *root);
private:
    bool preOrderIter(TreeNode *root);
};

/*
Tag: Tree
Given a binary tree, return the level order traversal of its 
nodes' values. (ie, from left to right, level by level).

Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[[3], [9,20], [15,7]]
*/
class _0102_BinaryTreeLevelOrderTraversal {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root);
};

/*
Tag: Tree
Given a binary tree, return the zigzag level order traversal of its nodes' 
values. (ie, from left to right, then right to left for the next level and 
alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[[3], [20,9], [15,7]]
*/
class _0103_BinaryTreeZigzagLevelOrderTraversal {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root);
};

/*
Tag: Tree
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root 
node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/
class _0104_MaximumDepthOfBinaryTree {
public:
    int maxDepth(TreeNode* root);
};

/*
Tag: Tree
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
class _0105_ConstructBinaryTreeFromPreorderAndInorderTraversal {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
};



/*
Tag: Tree
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
class _0106_ConstructBinaryTreeFromInorderAndPostorderTraversal {
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder);
private:
    TreeNode* buildTree(std::vector<int>& inorder, int inStart, int inEnd,
                       std::vector<int>& postorder, int postStart, int postEnd);
};


/*
Tag: Tree
Binary Tree Level Order Traversal II
Given a binary tree, return the bottom - up level order traversal of 
its nodes' values. (ie, from left to right, level by level from leaf to root).

For example :
Given binary tree[3, 9, 20, null, null, 15, 7],
    3
   / \
  9  20
 / \
15  7
return its bottom - up level order traversal as :
[
    [15, 7],
    [9, 20],
    [3]
]
*/
class _0107_BinaryTreeLevelOrderTraversalII {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root);
};

/*
Tag: Tree, Binary Search
Convert Sorted Array to Binary Search Tree
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
    TreeNode *sortedArrayToBST(std::vector<int> &nums);
private:
    TreeNode *bst(std::vector<int> &nums, int start, int end);
};

/*
Tag: Tree
Given a singly linked list where elements are sorted in ascending order, convert 
it to a height balanced BST. For this problem, a height-balanced binary tree is 
defined as a binary tree in which the depth of the two subtrees of every node 
never differ by more than 1.

Example:
Given the sorted linked list: [-10,-3,0,5,9], 
One possible answer is: [0,-3,9,-10,null,5], which represents the following 
height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/
class _0109_ConvertSortedListToBinarySearchTree {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };
    TreeNode* sortedListToBST(ListNode* head);
    void split(ListNode* head, ListNode*& root, 
        ListNode*& left, ListNode*& right);
};



/*
Tag: Tree, recursive
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:
Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
*/
class _0110_BalancedBinaryTree {
public:
    bool isBalanced(TreeNode* root);
private:
    int height(TreeNode* root);
};

/*
Tag: Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/
class _0111_MinimumDepthOfBinaryTree {
public:
    int minDepth(TreeNode* root);
};


/*
Tag: Backtracking, Tree, recursive
Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.
Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
class _0112_PathSum {
public:
    bool hasPathSum(TreeNode* root, int sum);
};


/*
Tag: Backtracking, Tree, recursive
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:
[[5,4,11,2], [5,8,4,5]]
*/
class _0113_PathSumII {
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum);
    void pathSum(TreeNode* root, int sum, std::vector<int> tmp, std::vector<std::vector<int>>& res);
};



/*
Tag: single linked list, Tree
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/
class _0114_FlattenBinaryTreeToLinkedList {
public:
    void flatten(TreeNode* root);
};


/*
Tag: Tree, recursive
You are given a perfect binary tree where all leaves are on the same level, 
and every parent has two children. The binary tree has the following definition:
Populate each next pointer to point to its next right node. If there is no next 
right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
*/
class _0116_PopulatingNextRightPointerInEachNode
{
public:
    class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node *next;
    };

    Node* connect(Node *root);
};



/*
Tag: recursive, Tree,
TODO: Constant space
117. Populating Next Right Pointers in Each Node II
Given a binary tree
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100
*/
class _0117_PopulatingNextRightPointersInEachNodeII {
public:
    struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    };

    Node* connect(Node* root);

    // /* Space Complexity O(1) Solution */
// struct myNode {
//     int val;
//     myNode* left;
//     myNode* right;
//     myNode* next;
//     myNode(int v, myNode* l, myNode* r, myNode* n) : val(v), left(l), right(r), next(n) {}
// };

// myNode* connect(myNode* root) {
//     myNode* dummy = new myNode(0, nullptr, nullptr, nullptr);
//     myNode* cur = dummy;
//     myNode* head = root;
//     while(root) {
//         if(root->left) {
//             cur->next = root->left;
//             cur = cur->next;
//         }
//         if(root->right) {
//             cur->next = root->right;
//             cur = cur->next;
//         }
//         root = root->next;
//         if(!root) {
//             cur = dummy;
//             root = dummy->next;
//             dummy->next = nullptr;
//         }
//     }
//     return head;
// }
};


/*
Facebook
!!! Copy from the solution !!!

Tag: recursive, Tree
TODO
Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to 
any node in the tree along the parent-child connections. The path must contain at least 
one node and does not need to go through the root.

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/
class _0124_BinaryTreeMaximumPathSum {
private:
    int res;
public:
    int helper(TreeNode* root);
    int maxPathSum(TreeNode* root);
};

/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/
class _0144_BinaryTreePreOrderTraversal {
public:
    std::vector<int> preorderTraversal(TreeNode* root);
};



/*
Tag: basic knowledge
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/
class _0145_BinaryTreePostorderTraversal {
public:
    std::vector<int> postorderTraversal(TreeNode* root);
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


    
    /*
    Facebook

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
        _0173_BinarySearchTreeIterator(TreeNode* root);
        
        /** @return the next smallest number */
        int next();
        
        /** @return whether we have a next smallest number */
        bool hasNext();
    private:
        std::stack<TreeNode*> st;
    };


/*
Facebook

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/
class _0199_BinaryTreeRightSideView {
public:
    std::vector<int> rightSideView(TreeNode* root);
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
    int countNodes(TreeNode* root);
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
    TreeNode* invertTree(TreeNode* root);
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
    int kthSmallest(TreeNode* root, int k);
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
    TreeNode *lowestCommonAncestorRecursive(TreeNode *root, TreeNode *p, TreeNode *q);
    TreeNode *lowestCommonAncestorIterative(TreeNode *root, TreeNode *p, TreeNode *q);
};


/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1         :         Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4         :         Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Note:
All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
*/
class _0236_LowestCommonAncestorBinaryTree {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
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
    std::vector<std::string> binaryTreePaths(TreeNode* root);
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
    int closestValue(TreeNode* root, double target); 
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
    std::stack<TreeNode*> st;
    TreeNode* getNext();
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);
};


/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.

Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7 

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]
Examples 2:

Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7 

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Examples 3:

Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
*/
class _0314_BinaryTreeVertialOrderTraversal {
public:
    std::vector<std::vector<int>> verticalOrder(TreeNode* root);
};


/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a 
non-null node, we record the node's value. If it is a null node, we record using a 
sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", 
where # represents a null node.
Given a string of comma separated values, verify whether it is a correct preorder traversal 
serialization of a binary tree. Find an algorithm without reconstructing the tree.
Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
You may assume that the input format is always valid, for example it could never contain two 
consecutive commas such as "1,,3".

Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true

Input: "1,#"
Output: false

Input: "9,#,#,1"
Output: false
*/
class _0331_VerifyPreorderSerializationOfABinaryTree {
public:
    bool isValidSerialization(std::string preorder);
private:
    bool isValidSerialization1(std::string preorder) {
        std::istringstream in(preorder);
        std::vector<std::string> v;
        std::string t = "";
        int cnt = 0;
        while (getline(in, t, ',')) v.push_back(t);
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i] == "#") {
                if (cnt == 0) return false;
                --cnt;
            } else ++cnt;
        }
        return cnt == 0 && v.back() == "#";
    }
    bool isValidSerialization2(std::string preorder) {
        std::istringstream in(preorder);
        std::string t = "";
        int degree = 1;
        bool degree_is_zero = false;;
        while (getline(in, t, ',')) {
            if (degree_is_zero) return false;
            if (t == "#") {
                if (--degree == 0) degree_is_zero = true;
            } else ++degree;
        }
        return degree == 0;
    }

    bool isValidSerialization3(std::string preorder) {
        int capacity = 1;
        preorder += ",";
        for (int i = 0; i < preorder.size(); ++i) {
            if (preorder[i] != ',') continue;
            if (--capacity < 0) return false;
            if (preorder[i - 1] != '#') capacity += 2;
        }
        return capacity == 0;
    }
};

/*
Find the sum of all left leaves in a given binary tree.

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/
class _0404_SumOfLeftLeaves {
public:
    int sumOfLeftLeaves(TreeNode *root);
};

/*
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.
You can think of the left and right pointers as synonymous to the predecessor 
and successor pointers in a doubly-linked list. For a circular doubly linked list, 
the predecessor of the first element is the last element, and the successor of 
the last element is the first element.
We want to do the transformation in place. After the transformation, the left 
pointer of the tree node should point to its predecessor, and the right pointer 
should point to its successor. You should return the pointer to the smallest 
element of the linked list.

Input: root = [4,2,5,1,3]
Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST. The solid line indicates 
the successor relationship, while the dashed line means the predecessor relationship.

Input: root = [2,1,3]
Output: [1,2,3]

Input: root = []
Output: []
Explanation: Input is an empty tree. Output is also an empty Linked List.

Input: root = [1]
Output: [1]
 

Constraints:

-1000 <= Node.val <= 1000
Node.left.val < Node.val < Node.right.val
All values of Node.val are unique.
0 <= Number of Nodes <= 2000
*/
class _0426_ConvertBinarySearchTreeToSortedDoublyLinkedList {
public:
    struct Node {
        int val;
        Node* left;
        Node* right;
    };
    Node* treeToDoublyList(Node* root);
private:
    std::pair<Node*, Node*> conn(Node* root);
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
Serialization is the process of converting a data structure or object into a sequence of bits 
so that it can be stored in a file or memory buffer, or transmitted across a network connection 
link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree 
in which each node has no more than N children. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree 
can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree as [1 [3[5 6] 2 4]]. Note that this is 
just an example, you do not necessarily need to follow this format.

Or you can follow LeetCode's level order traversal serialization format, where each group of 
children is separated by the null value.

For example, the above tree may be serialized as 
[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

You do not necessarily need to follow the above suggested formats, there are many more different 
formats that work so please be creative and come up with different approaches yourself.

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 10^4]
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
*/
class _0428_SerializeAndDeserializeNAryTree {
public:
    std::string serialize(NAryNode* root);
    NAryNode* deserialize(std::string data);
private:
    void serializeHelper(NAryNode* root, std::string& res) {
        if(root == nullptr) {
            res += "#";
        } else {
            res += std::to_string(root->val) + " " + std::to_string(root->children.size()) + " ";
            for(auto child : root->children) {
                serializeHelper(child, res);
            }
        }
    }

    NAryNode* deserializeHelper(std::istringstream& iss) {
        std::string val = "";
        std::string size = "";
        iss >> val;
        if(val == "#") return nullptr;
        iss >> size;
        NAryNode* node = new NAryNode(std::stoi(val), {});
        for(int i = 0; i < std::stoi(size); ++i) {
            node->children.push_back(deserializeHelper(iss));
        }
        return node;
    }
};

/* Given an n-ary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level). For example, given a 3-ary tree:

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
class _0429_NaryTreelevelOrderTraversal {
public:
    std::vector<std::vector<int>> levelOrder(NaryTreeNode *root);
};



/*
Given a node in a binary search tree, find the in-order successor of that node in the BST.
If that node has no in-order successor, return null.
The successor of a node is the node with the smallest key greater than node.val.
You will have direct access to the node but not to the root of the tree. Each node will 
have a reference to its parent node. Below is the definition for Node:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
 

Follow up:
Could you solve it without looking up any of the node's values?


Input: tree = [2,1,3], node = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both the node and the return value is of Node type.

Input: tree = [5,3,6,2,4,null,null,1], node = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.

Input: tree = [15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9], node = 15
Output: 17

Input: tree = [15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9], node = 13
Output: 15

Input: tree = [0], node = 0
Output: null
 

Constraints:

-10^5 <= Node.val <= 10^5
1 <= Number of Nodes <= 10^4
All Nodes will have unique values.
*/
class _0510_InorderSuccessorInBSTII {
public:
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* parent;
        Node(int v) : val(v), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    Node* inorderSuccessor(Node* node);
};

/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that 
every key of the original BST is changed to the original key plus sum of 
all keys greater than the original key in BST.

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*/
class _0538_ConvertBSTToGreaterTree {
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* p = root;
        std::stack<TreeNode*> st;
        int lasNum = 0;
        while(p != nullptr || !st.empty()) {
            if(p != nullptr) {
                st.push(p);
                p = p->right;
            } else {
                TreeNode* q = st.top();
                st.pop();
                
                lasNum += q->val;
                q->val = lasNum;
                
                p = q->left;
            }
        }
        return root;
    }
};


/*
Given a n-ary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root 
node down to the farthest leaf node.
Nary-Tree input serialization is represented in their level order traversal, 
each group of children is separated by the null value (See examples).

Input: root = [1,null,3,2,4,null,5,6]
Output: 3

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5

Constraints:

The depth of the n-ary tree is less than or equal to 1000.
The total number of nodes is between [0, 10^4].
*/
class _0559_MaximumDepthOfNaryTree {
public:
    int maxDepth(NaryTreeNode* root);
};

/*
Given two non-empty binary trees s and t, check whether tree t has exactly 
the same structure and node values with a subtree of s. A subtree of s is 
a tree consists of a node in s and all of this node's descendants. The tree 
s could also be considered as a subtree of itself.
Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree 
of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
*/
class _0572_SubtreeOfAnotherTree {
public:
    bool isSubtree(TreeNode* s, TreeNode* t);
private:
    bool isSame(TreeNode* s, TreeNode* t);
};

/*
Given an n-ary tree, return the preorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order 
traversal, each group of children is separated by the null value 
(See examples). 

Follow up:
Recursive solution is trivial, could you do it iteratively?

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 10^4]
*/
class _0589_NaryTreePreorderTraversal {
public:
    std::vector<int> preorder(NaryTreeNode* root);
};

/*
Given an n-ary tree, return the postorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, 
each group of children is separated by the null value (See examples).

Recursive solution is trivial, could you do it iteratively?
Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
*/
class _0590_NaryTreePostOrderTraversal {
public:
    std::vector<int> postorder(NaryTreeNode* root);
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);
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
    std::vector<double> averageOfLevels(TreeNode* root);
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
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums);
private:
    TreeNode* constructMaximumBinaryTree_impl(std::vector<int>::iterator l, std::vector<int>::iterator r);
};

/*
Given a binary tree with n nodes, your task is to check if it's possible to partition the 
tree to two trees which have the equal sum of values after removing exactly one edge on 
the original tree.

Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15
Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000
*/
class _0663_EqualTreePartition {
public:
    bool checkEqualTree(TreeNode* root);
    int treeSum(TreeNode* root);
    int foo(TreeNode* root, int target, bool& divisible);
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
    TreeNode* insertIntoBST(TreeNode* root, int val);
};

/*
Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
 

Constraints:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
*/
class _0897_IncreasingOrderSearchTree {
public:
    TreeNode* increasingBST(TreeNode* root);
};

/*
Tag: Tree
Interview : Google
For a binary tree T, we can define a flip operation as follows: 
choose any node, and swap the left and right child subtrees.
A binary tree X is flip equivalent to a binary tree Y if and only 
if we can make X equal to Y after some number of flip operations.
Write a function that determines whether two binary trees are flip 
equivalent.  The trees are given by root nodes root1 and root2.

Input: 
root1 = [1,2,3,4,5,6,null,null,null,7,8], 
root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.

Note:

Each tree will have at most 100 nodes.
Each value in each tree will be a unique integer in the range [0, 99].
*/
class _0951_FlipEquivalentBinaryTrees {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) {
            return true;
        } else if ((!root1 && root2) || (root1 &&!root2)) {
            return false;
        } else if (root1->val != root2->val) {
            return false;
        } else {
            return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
                (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
        }
    }
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
public:
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        return bstFromPreorder(preorder.begin(), preorder.end());
    }
    TreeNode* bstFromPreorder(std::vector<int>::iterator left, std::vector<int>::iterator right) {
        if(left == right) {
            return nullptr;
        }
        TreeNode* r = new TreeNode(*left);
        if(left + 1 != right) {        
            std::vector<int>::iterator lb = left + 1;
            while(lb < right && *lb < *left) {
                ++lb;
            }
            r->left = bstFromPreorder(left + 1, lb);
            r->right = bstFromPreorder(lb, right);
        }
        return r;        
    }
};

/*
Given a binary tree, return the sum of values of its deepest leaves.

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]          :        Output: 15
Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.
*/
class _1302_DeepestLeavesSum {
private:
    int maxDepth = 0;
    int val = 0;
public:
    int deepestLeavesSum(TreeNode* root) {
        deepestLeavesSum(root, 0);
        return val;
    }
    
    void deepestLeavesSum(TreeNode* root, int depth) {
        if(!root) {
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            if(depth > maxDepth) {
                val = root->val;
                maxDepth = depth;
            } else if(depth == maxDepth) {
                val += root->val;
            }
        }
        deepestLeavesSum(root->left, depth + 1);
        deepestLeavesSum(root->right, depth + 1);
    }
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
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        class BSTIterator {
        public:
            std::stack<TreeNode*> st;
            BSTIterator(TreeNode* p) {
                while(p) {
                    st.push(p);
                    p = p->left;
                }
            }
            bool hasNext() {
                return !st.empty();
            }
            TreeNode* getNext() {
                return st.top();
            }
            void update() {
                TreeNode* res = st.top(); 
                st.pop();

                res = res->right;
                while(res) {
                    st.push(res);
                    res = res->left;
                }
            }
        };

        BSTIterator r1(root1);
        BSTIterator r2(root2);
        std::vector<int> res;
        while(r1.hasNext() && r2.hasNext()) {
            int t1 = r1.getNext()->val;
            int t2 = r2.getNext()->val;
            if(t1 < t2) {
                res.push_back(t1);
                r1.update();
            } else {
                res.push_back(t2);
                r2.update();
            }
        }
        while(r1.hasNext()) {
            res.push_back(r1.getNext()->val);
            r1.update();
        }
        while(r2.hasNext()) {
            res.push_back(r2.getNext()->val);
            r2.update();
        }
        return res;
    }
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
    int sumEvenGrandparent(TreeNode* root) {
        res = 0;
        sumGrand(root, -1, -1);
        return res;
    }

private:
    int res = 0;
    void sumGrand(TreeNode* root, int parent, int grand) {
        if(!root) {return;}

        if(grand % 2 == 0) {
            res += root->val;
        }
        sumGrand(root->left, root->val, parent);
        sumGrand(root->right, root->val, parent);
    }
};


/*
Given two binary trees original and cloned and given a reference to a node 
target in the original tree.
The cloned tree is a copy of the original tree. Return a reference to the 
same node in the cloned tree. Note that you are not allowed to change any 
of the two trees or the target node and the answer must be a reference to 
a node in the cloned tree.
Follow up: Solve the problem if repeated values on the tree are allowed.

Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.

Input: tree = [7], target =  7
Output: 7

Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4

Input: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
Output: 5

Input: tree = [1,2,null,3], target = 2
Output: 2

Constraints:

The number of nodes in the tree is in the range [1, 10^4].
The values of the nodes of the tree are unique.
target node is a node from the original tree and is not null.
*/
class _1379_FindACorrespondingNodeOfABinaryTreeInACloneOfThatTree {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target);
};

/*
Given a binary search tree, return a balanced binary search tree with 
the same node values.
A binary search tree is balanced if and only if the depth of the two 
subtrees of every node never differ by more than 1.
If there is more than one answer, return any of them.


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, 
[3,1,4,null,2,null,null] is also correct.

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.
*/
class _1382_BalanceABinarySearchTree {
public:
    TreeNode* balanceBST(TreeNode* root);
private:
    TreeNode* createBST(const std::vector<int>& arr, int start, int end);
    std::vector<int> inOrderTraverse(TreeNode* root);
};

/*
Given a root of an N-ary tree, return a deep copy (clone) of the tree.
Each node in the n-ary tree contains a val (int) and a list (List[Node]) of its children.

class Node {
    public int val;
    public List<Node> children;
}
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Follow up: Can your solution work for the graph problem?

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 
Constraints: 

The depth of the n-ary tree is less than or equal to 1000.
The total number of nodes is between [0, 10^4].
*/
class _1490_CloneNaryTree {
public:
    NaryTreeNode* cloneTree(NaryTreeNode* root) {
        if(!root) {
            return nullptr;
        }
        NaryTreeNode* newRoot = new NaryTreeNode(root->data, root->children); 
        for(int i = 0; i < root->children.size(); ++i) {
            newRoot->children[i] = cloneTree(root->children[i]);
        }
        return newRoot;
    }
};

}
#endif