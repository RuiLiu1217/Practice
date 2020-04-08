#include "headers.hpp"

std::vector<int> LeetCode::_0501_FindModeInBinarySearchTree::findMode(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    std::stack<TreeNode<int>*> st;
    std::vector<int> res;
    int preV = INT_MIN;
    int count = 0;
    int maxCount = INT_MIN;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            TreeNode<int>* t = st.top();
            st.pop();
            
            if(t->val == preV) {
                ++count;
            } else {
                preV = t->val;
                count = 1;
            }

            if(count > maxCount) {
                res.clear();
                res.push_back(t->val);
                maxCount = count;
            } else if(count == maxCount) {
                res.push_back(t->val);
            }
            p = t->right; 
        }
    }
    return res;
}