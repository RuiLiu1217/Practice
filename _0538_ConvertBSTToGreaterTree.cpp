#include "headers.hpp"

TreeNode<int>* LeetCode::_0538_ConvertBSTToGreaterTree::convertBST(TreeNode<int>* root) {
    inOrder(root);
    return root;
    
}
    
void LeetCode::_0538_ConvertBSTToGreaterTree::inOrder(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    std::stack<TreeNode<int>*> st;
    std::stack<TreeNode<int>*> accessSt;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            TreeNode<int>* t = st.top();
            st.pop();
            accessSt.push(t);
            p = t->right;
        }
    }
    int accumulateValue = 0;
    while(!accessSt.empty()) {
        TreeNode<int>* q = accessSt.top();
        q->val += accumulateValue;
        accumulateValue = q->val;
        accessSt.pop();            
    }
}