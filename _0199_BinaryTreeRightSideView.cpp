#include "headers.hpp"
#include <queue>
#include <stack>
// Tree Level-traversal
std::vector<int> LeetCode::_0199_BinaryTreeRightSideView::rightSideView(TreeNode<int>* root) {
    if(!root) {
        return std::vector<int>();
    }
    std::queue<TreeNode<int>*> Q;
    std::vector<int> res;
    Q.push(root);
    
    while(!Q.empty()) {
        const int N = Q.size();
        int v = -1;
        for(int i = 0; i < N; ++i) {
            auto t = Q.front();
            Q.pop();
            v = t->val;
            if(t->left) {
                Q.push(t->left);
            }
            if(t->right) {
                Q.push(t->right);
            }
        }
        res.push_back(v);            
    }
    return res;
}