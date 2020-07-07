#include "headers.hpp"

std::vector<TreeNode<int>*> LeetCode::_0095_UniqueBinarySearchTreeII::generateTrees(int n) {
    return generateTreeHelper(1, n);
}

std::vector<TreeNode<int>*>  LeetCode::_0095_UniqueBinarySearchTreeII::generateTreeHelper(int l, int r) {
    if(l > r) {
        return {};
    }
    if(l == r) {
        TreeNode<int>* root = new TreeNode<int>(l);
        std::vector<TreeNode<int>*> res{root};
        return res;
    }
    std::vector<TreeNode<int>*> res;
    for(int i = l; i <= r; ++i) {
        std::vector<TreeNode<int>*> lft = generateTreeHelper(l, i-1);
        std::vector<TreeNode<int>*> rgh = generateTreeHelper(i+1, r);
        if(lft.size() == 0 && rgh.size() == 0) {
            TreeNode<int>* root = new TreeNode<int>(i);
            res.push_back(root);
        } else if(lft.size() == 0 && rgh.size() != 0) {
            for(int rr = 0; rr < rgh.size(); ++rr) {
                TreeNode<int>* root = new TreeNode<int>(i);
                root->right = rgh[rr];                
                res.push_back(root);
            }
        } else if(lft.size() != 0 && rgh.size() == 0) {
            for(int ll = 0; ll < lft.size(); ++ll) {
                TreeNode<int>* root = new TreeNode<int>(i);
                root->left = lft[ll];                
                res.push_back(root);
            }
        } else {
            for(int ll = 0; ll < lft.size(); ++ll) {
                for(int rr = 0; rr < rgh.size(); ++rr) {
                    TreeNode<int>* root = new TreeNode<int>(i);
                    root->left = lft[ll];                
                    root->right = rgh[rr];                
                    res.push_back(root);
                }
            }
        }
    }
    return res;
}