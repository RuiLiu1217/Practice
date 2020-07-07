#include "headers.hpp"

bool LeetCode::_0100_SameTree::isSameTree(TreeNode<int> *p, TreeNode<int> *q) {
    if (p==nullptr && q==nullptr) {
        return true;
    }
    if ((p == nullptr && q != nullptr) ||(p != nullptr && q == nullptr)) {
        return false;
    }
    
    if(p->val != q->val) {
        return false;
    } else {
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
    
}



// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         TreeNode* ptr = root;
//         while(root) {
//             if(root->left && root->right) {
//                 TreeNode* p = root->left;
//                 while(p->right) {
//                     p = p->right;
//                 }
//                 p->right = root->right;
//                 root->right = nullptr;
//             }
//             if(root->left) {
//                 root->right = root->left;
//                 root->left = nullptr;
//             }
//             root = root->right;
//         }
//     }
// };