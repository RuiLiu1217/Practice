#include "headers.hpp"
#include <stack>
std::vector<int> LeetCode::_0144_BinaryTreePreOrderTraversal::preorderTraversal(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    std::stack<TreeNode<int>*> st;
    std::vector<int> res;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            res.push_back(p->val);
            st.push(p);
            p = p->left;
        } else {
            TreeNode<int>* q = st.top();
            st.pop();
            p = q->right;
        }
    }
    return res;
}