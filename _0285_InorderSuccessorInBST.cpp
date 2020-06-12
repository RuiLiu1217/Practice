#include "headers.hpp"

TreeNode<int>* LeetCode::_0285_InorderSuccessorInBST::getNext() {
    if(!st.empty()) {
        TreeNode<int>* p = st.top();
            st.pop();
            TreeNode<int>* t = p->right;
            while(t) {
                st.push(t);
                t = t->left;
            }
            return p;
    } else {
        return nullptr;
    }
}

TreeNode<int>* LeetCode::_0285_InorderSuccessorInBST::inorderSuccessor(TreeNode<int>* root, TreeNode<int>* p) {
    while(root) {
        st.push(root);
        root = root->left;
    }
    while(true) {
        TreeNode<int>* t = getNext();
        if(!t || t == p) {
            break;
        }
    }
    return getNext();
}