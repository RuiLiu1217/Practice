#include "headers.hpp"


std::vector<int> LeetCode::_0971_FlipBinaryTreeToMatchPreorderTraversal::flipMatchVoyage(TreeNode<int>* root, std::vector<int>& voyage) {
	TreeNode<int>* p = root;
    std::stack<TreeNode<int>*> st;
    int voIdx = 0;
    std::vector<int> res;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            if(p->val != voyage[voIdx]) {
                return {-1};
            }
            if(p->left && p->right) {
                if((voIdx+1) < voyage.size() && p->left->val != voyage[voIdx+1]) {
                    TreeNode<int>* tmp = p->left;
                    p->left = p->right;
                    p->right = tmp;
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
