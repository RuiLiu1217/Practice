#include "headers.hpp"

TreeNode<int>* LeetCode::_0897_IncreasingOrderSearchTree::increasingBST(TreeNode<int>* root) {
    TreeNode<int>* head = new TreeNode<int>(-1);
    head->right = root;
    TreeNode<int>* t = head;
    TreeNode<int>* p = root;

    std::stack<TreeNode<int>*> st;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            TreeNode<int> * q= st.top();
            st.pop();

            t->right = q;
            t = q;
            q->left = nullptr;

            p = q->right;
        }
    }
    return head->right;
}