#include "headers.hpp"

bool LeetCode::_0098_ValidateBinarySearchTree::isValidBST(TreeNode<int>* root) {
    if(!root) {
        return true;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return true;
    }

    TreeNode<int>* p = root;
    std::stack<TreeNode<int>*> st;
    int preV = INT_MIN;
    bool notfound = true;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            TreeNode<int>* q = st.top();
            st.pop();
            // Make the decision, if it is the first time get the value, just let it go
            // if not, we need to compare whether the current value is larger than
            // the previous value.
            if(notfound) {
                preV = q->val;
                notfound = false;
            } else {
                if(q->val <= preV) {
                    return false;
                } else {
                    preV = q->val;
                }
            }
            p = q->right;
        }
    }
    return true;
}