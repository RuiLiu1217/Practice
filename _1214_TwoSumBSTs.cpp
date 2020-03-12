#include "headers.hpp"

class NextIterator {
private:
    std::stack<TreeNode<int>*> st;
public:
    NextIterator(TreeNode<int>* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    bool hasNext() {
        return !st.empty();
    }
    void next() {
        if(hasNext()) {
            TreeNode<int>* t = st.top();
            st.pop();
            TreeNode<int>* q = t->right;
            while(q) {
                st.push(q);
                q = q->left;
            }
        }
    }
    TreeNode<int>* get() {
        if(hasNext()) {
            return st.top();
        } else {
            return nullptr;
        }
    }
};

class PrevIterator {
private:
    std::stack<TreeNode<int>*> st;
public:
    PrevIterator(TreeNode<int>* root) {
        while(root) {
            st.push(root);
            root = root->right;
        }
    }
    bool hasPrev() {
        return !st.empty();
    }
    void prev() {
        if(hasPrev()) {
            TreeNode<int>* t = st.top();
            st.pop();
            TreeNode<int>* q = t->left;
            while(q) {
                st.push(q);
                q = q->right;
            }
        }
    }
    TreeNode<int>* get() {
        if(hasPrev()) {
            return st.top();
        } else {
            return nullptr;
        }
    }
};

class Solution {
public:
    bool twoSumBSTs(TreeNode<int>* root1, TreeNode<int>* root2, int target) {
        NextIterator ni(root1);
        PrevIterator pi(root2);
        while(ni.get() && pi.get()) {
            int v = ni.get()->val + pi.get()->val;
            if(v == target) {
                return true;
            } else if(v < target) {
                ni.next();
            } else {
                pi.prev();
            }
        }
        return false;
    }
};