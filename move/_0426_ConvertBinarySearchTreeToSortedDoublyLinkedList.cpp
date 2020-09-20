#include "headers.hpp"

// Facebook

using Nod = LeetCode::_0426_ConvertBinarySearchTreeToSortedDoublyLinkedList::Node;
Nod* LeetCode::_0426_ConvertBinarySearchTreeToSortedDoublyLinkedList::treeToDoublyList(Nod* root) {
    std::pair<Nod*, Nod*> res = conn(root);
    return res.first;
}

std::pair<Nod*, Nod*> LeetCode::_0426_ConvertBinarySearchTreeToSortedDoublyLinkedList::conn(Nod* root) {
    if(!root) {
        return {nullptr, nullptr};
    }
    if(root->left == nullptr && root->right == nullptr) {
        root->left = root;
        root->right = root;
        return {root, root};
    }
    auto [lhead, ltail] = conn(root->left);
    auto [rhead, rtail] = conn(root->right);
    if(lhead == nullptr && rhead == nullptr) {
        root->left = root;
        root->right = root;
        return {root, root};
    } else if(lhead == nullptr && rhead != nullptr) {
        root->right = rhead;
        rhead->left = root;
        root->left = rtail;
        rtail->right = root;
        return {root, rtail};
    } else if(lhead != nullptr && rhead == nullptr) {
        root->left = ltail;
        root->right = lhead;
        lhead->left = root;
        ltail->right = root;
        return {lhead, root};
    } else {
        root->left = ltail;
        root->right = rhead;
        ltail->right = root;
        rhead->left = root;
        lhead->left = rtail;
        rtail->right = lhead;
        return {lhead, rtail};
    }
}