#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP
#include <memory>

struct RBNode {
    int val;
    RBNode* left;
    RBNode* right;
    int N;
    bool color;
    bool isRed() {
        return color;
    }
    RBNode(int v, int n, bool col) : val(v), N(n), color(col) {}
};

class RedBlackBST {
private:
    RBNode* root;
    bool isRed(RBNode* h);
    RBNode* rotateLeft(RBNode* h);
    RBNode* rotateRight(RBNode* h);
    void flipColors(RBNode* h);
    int size(RBNode* r) {
        if(r == nullptr) {
            return 0;
        } else {
            return r->N;
        }
    }
    int size() {
        return size(root);
    }
public:
    void put(int val) {
        root = put(root, val);
    }
    
private:
    RBNode* put(RBNode* h, int val) {
        if(h == nullptr) {
            return (new RBNode(val, 1, true));
        }

        if (h->val < val) {
            h->left = put(h->left, val);
        } else if(h->val > val) {
            h->right = put(h->right, val);
        } else {
            h->val = val;
        }

        if(isRed(h->right) && !isRed(h->left)) {
            h = rotateLeft(h);
        }

        if(isRed(h->left) && isRed(h->left->left)) {
            h = rotateRight(h);
        }

        if(isRed(h->left) && isRed(h->right)) {
            flipColors(h);
        }
        h->N = size(h->left) + size(h->right) + 1;
        return h;
    }
};

#endif