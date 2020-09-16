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

}
#endif