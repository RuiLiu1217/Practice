#include "headers.hpp"

TreeNode<int>* insertIntoBST(TreeNode<int>* root, int val) {
    if(!root) {
        return nullptr;
    }
    TreeNode<int>* p = root;
    TreeNode<int>* q;
    while(p) {
        if(p->val < val) {
            q = p;
            p = p->right;
        } else {
            q = p;
            p = p->left;
        }
    }
    TreeNode<int>* v = new TreeNode<int>(val);
    if(q->val < val) {
        q->right = v;
    } else {
        q->left = v;
    }
    return root;
}