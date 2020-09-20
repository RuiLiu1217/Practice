#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0429_NaryTreelevelOrderTraversal::levelOrder(NaryTreeNode<int>* root) {
    if(!root) {
        return {};
    }
    std::vector<std::vector<int>> res;
    std::queue<NaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        const int N = q.size();
        std::vector<int> tmp;
        for(int i = 0; i < N; ++i) {
            NaryTreeNode<int>* t = q.front();
            q.pop();

            tmp.push_back(t->data);

            for(int j = 0; j < t->children.size(); ++j) {
                if((t->children)[j]) {
                    q.push((t->children)[j]);
                }
            }
        }
        res.push_back(tmp);
    }
    return res;
}