#include "headers.hpp"

// Facebook

// Inorder Traversal
LeetCode::_0173_BinarySearchTreeIterator::_0173_BinarySearchTreeIterator(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    while(p != nullptr) {
        st.push(p);
        p = p->left;
    }
}

/** @return the next smallest number */
int LeetCode::_0173_BinarySearchTreeIterator::next() {
    if(hasNext()) {
        TreeNode<int>* q = st.top();
        st.pop();
        TreeNode<int>* p = q->right;
        while(p) {
            st.push(p);
            p = p->left;
        }
        return q->val;
    } else {
        return INT_MAX;
    }        
}

/** @return whether we have a next smallest number */
bool LeetCode::_0173_BinarySearchTreeIterator::hasNext() {
    return !st.empty();
}