#include "headers.hpp"

int LeetCode::_0230_KthSmallestElementInABST::kthSmallest(TreeNode<int>* root, int k) {
    TreeNode<int>* p = root;
    std::stack<TreeNode<int>*> st;
    TreeNode<int>* q = nullptr;
    int count = 1;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            q = st.top();
            st.pop();
            if(count == k) {
                break;
            } else {
                ++count;
                p = q->right;
            }
        }
    }
    return q->val;
}