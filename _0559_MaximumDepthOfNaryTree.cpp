#include "headers.hpp"

int LeetCode::_0559_MaximumDepthOfNaryTree::maxDepth(NaryTreeNode<int>* root) {
    if(!root) {
        return 0;
    } else {
        int height = 0;
        for(int i = 0; i < root->children.size(); ++i) {
            int curH = maxDepth(root->children[i]);
            if(curH > height) {
                height = curH;
            }
        }
        return height + 1;
    }
}