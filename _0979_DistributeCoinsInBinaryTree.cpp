#include "headers.hpp"

/*
If the leaf of a tree has 0 coins (an excess of -1 from what 
it needs), then we should push a coin from its parent onto 
the leaf. If it has say, 4 coins (an excess of 3), then we 
should push 3 coins off the leaf. In total, the number of 
moves from that leaf to or from its parent is excess = 
Math.abs(num_coins - 1). Afterwards, we never have to consider 
this leaf again in the rest of our calculation.

Algorithm
We can use the above fact to build our answer. Let dfs(node) 
be the excess number of coins in the subtree at or below this 
node: namely, the number of coins in the subtree, minus the 
number of nodes in the subtree. Then, the number of moves we 
make from this node to and from its children is 
abs(dfs(node.left)) + abs(dfs(node.right)). After, we have an 
excess of node.val + dfs(node.left) + dfs(node.right) - 1 coins
at this node.
*/
int LeetCode::_0979_DistributeCoinsInBinaryTree::distriuteCoins(TreeNode<int>* root) {
    this->ans = 0;
    DFS(root);
    return ans;
}


int LeetCode::_0979_DistributeCoinsInBinaryTree::DFS(TreeNode<int>* root) {
    if(!root) {
        return 0;
    }
    int L = DFS(root->left);
    int R = DFS(root->right);
    this->ans += std::abs(L) + std::abs(R);
    return root->val + L + R - 1;
}