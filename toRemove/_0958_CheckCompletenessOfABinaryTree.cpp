#include "headers.hpp"

bool LeetCode::_0958_CheckCompletenessOfABinaryTree::siCompleteTree(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    std::queue<TreeNode<int>*> qu;
    qu.push(p);
    bool flagSet = false;
    while(!qu.empty()) {
        const int N = qu.size();
        for(int i = 0; i < N; ++i) {
            TreeNode<int>* t = qu.front();
            qu.pop();
            if(flagSet) {
                if(t->left != nullptr ||
                   t->right != nullptr) {
                       return false;
                   }
            } else {
                if(t->left == nullptr && t->right == nullptr) {
                    flagSet = true;
                } else if(t->left != nullptr && t->right == nullptr) {
                    flagSet = true;
                    qu.push(t->left);
                } else if(t->left == nullptr && t->right != nullptr) {
                    return false;
                } else {
                    qu.push(t->left);
                    qu.push(t->right);
                }
            }
        }
    }
    return true;
}

