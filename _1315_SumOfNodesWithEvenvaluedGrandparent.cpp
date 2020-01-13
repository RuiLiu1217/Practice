#include "headers.hpp"
#include <unordered_set>
#include <queue>

int LeetCode::_1315_SumOfNodesWithEvenvaluedGrandparent::sumEvenGrandparent(TreeNode<int>* root) {
    int sumEvenGrandparent(TreeNode<int>* root) {
    TreeNode<int>* p = root;
    std::queue<TreeNode<int>*> q;
    std::unordered_set<TreeNode<int>*> pnt;
    q.push(p);
    while(!q.empty()) {
        const int N = q.size();
        for(int i = 0; i < N; ++i) {
            TreeNode<int>* f = q.front();
            q.pop();
            
            bool canPush = ((f->val % 2) == 0);
            TreeNode<int>* fl = f->left;
            if(fl) {
                q.push(fl);
                if(canPush) {
                    if(fl->left) {
                        pnt.insert(fl->left);
                    }
                    if(fl->right) {
                        pnt.insert(fl->right);
                    }
                }
            } 
            TreeNode<int>* fr = f->right;
            if(fr) {
                q.push(fr);
                if(canPush) {
                    if(fr->left) {
                        pnt.insert(fr->left);
                    }
                    if(fr->right) {
                        pnt.insert(fr->right);
                    }
                }
            }
        }
    }
    
    int result = 0;
    for(auto p : pnt) {
        result += p->val;
    }
    return result;
}