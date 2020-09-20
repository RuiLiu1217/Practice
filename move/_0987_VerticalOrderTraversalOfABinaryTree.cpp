#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0987_VerticalOrderTraversalOfABinaryTree::verticalTraversal(TreeNode<int>* root) {
    std::map<int, std::map<int, std::set<int>>> nodes;
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
            nodes[x][y].insert(node->val);
            if(node->left) {
                q.push({node->left, {x-1,y+1}});
            }
            if(node->right) {
                q.push({node->right, {x+1,y+1}});
            }
        }
    }

    std::vector<std::vector<int>> ans;
    for(auto n : nodes) {
        std::vector<int> col;
        for(auto t : n.second) {
            col.insert(col.end(), t.second.begin(), t.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}


void LeetCode::_0987_VerticalOrderTraversalOfABinaryTree::traverse(TreeNode<int>* root, int x, int y) {
    if(root) {
        nodesDFS[x][y].insert(root->val);
        traverse(root->left, x - 1, y + 1);
        traverse(root->right, x + 1, y + 1);
    }
}

std::vector<std::vector<int>> LeetCode::_0987_VerticalOrderTraversalOfABinaryTree::verticalTraversalDFS(TreeNode<int>* root) {
    traverse(root, 0, 0);
    std::vector<std::vector<int>> ans;
    for(auto p : nodesDFS) {
        std::vector<int> col;
        for(auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

