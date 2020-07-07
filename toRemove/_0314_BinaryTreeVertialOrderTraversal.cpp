#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0314_BinaryTreeVertialOrderTraversal::verticalOrder(TreeNode<int>* root) {
    if(!root) {
        return {};
    }
    std::map<int, std::map<int, std::vector<int>>> nodes;
    std::queue<std::pair<TreeNode<int>*, std::pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(!q.empty()) {
        const int N = q.size();
        for(int i = 0; i < N; ++i) {
            auto f = q.front();
            q.pop();
            TreeNode<int>* node = f.first;
            int x = f.second.first;
            int y = f.second.second;
            nodes[x][y].push_back(node->val);
            if(node->left) {
                q.push({node->left, {x-1,y+1}});
            }
            if(node->right) {
                q.push({node->right, {x+1, y+1}});
            }
        }
    }
    
    std::vector<std::vector<int>> res;
    for(auto n : nodes) {
        std::vector<int> col;
        for(auto t : n.second) {
            col.insert(col.end(), begin(t.second), end(t.second));
        }
        res.push_back(col);
    }
    return res;        
}
