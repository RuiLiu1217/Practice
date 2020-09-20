#include "headers.hpp"

std::vector<int> inorderTraversal(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    std::stack<TreeNode<int>*> st;
    std::vector<int> res;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            TreeNode<int>* q = st.top();
            st.pop();
            
            res.push_back(q->val);
            
            p = q->right;
            
        }
    }
    return res;
}