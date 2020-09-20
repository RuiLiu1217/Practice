#include "headers.hpp"


std::vector<int> LeetCode::_0971_FlipBinaryTreeToMatchPreorderTraversal::flipMatchVoyage(TreeNode<int>* root, std::vector<int>& voyage) {
	TreeNode<int>* p = root;
    std::stack<TreeNode<int>*> st;
    int voIdx = 0;
    std::vector<int> res;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            if(p->val != voyage[voIdx]) { // if mismatch the current node. return -1
                return {-1};
            }
            if(p->left && p->right) {
                if((voIdx+1) < voyage.size() && p->left->val != voyage[voIdx+1]) { // if the left node doesn't match its voyage[volIdx + 1], swap it with its right child.
                    std::swap(p->left, p->right);
                    res.push_back(p->val);
                }
            }
            ++voIdx;
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
