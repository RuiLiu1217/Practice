#include "headers.hpp"

LeetCode::_0117_PopulatingNextRightPointersInEachNodeII::Node* LeetCode::_0117_PopulatingNextRightPointersInEachNodeII::connect(Node* root) {
    if(root == nullptr) {
        return nullptr;
    }
    Node* p = root;
    std::queue<std::pair<Node*, int>> q;
    q.push({p, 0});
    while(!q.empty()) {
        const int N = q.size();
        for(int i = 0; i < N; ++i) {
            auto a = q.front();
            auto t = a.first;
            
            q.pop();
            if(!q.empty() && a.second == q.front().second) {
                t->next = q.front().first;
            }
            if(t->left) {
                q.push({t->left, a.second + 1});
            }
            if(t->right) {
                q.push({t->right, a.second + 1});
            }
        }
    }
    return root;
}

/* Space Complexity O(1) Solution */
struct myNode {
    int val;
    myNode* left;
    myNode* right;
    myNode* next;
    myNode(int v, myNode* l, myNode* r, myNode* n) : val(v), left(l), right(r), next(n) {}
};

myNode* connect(myNode* root) {
    myNode* dummy = new myNode(0, nullptr, nullptr, nullptr);
    myNode* cur = dummy;
    myNode* head = root;
    while(root) {
        if(root->left) {
            cur->next = root->left;
            cur = cur->next;
        }
        if(root->right) {
            cur->next = root->right;
            cur = cur->next;
        }
        root = root->next;
        if(!root) {
            cur = dummy;
            root = dummy->next;
            dummy->next = nullptr;
        }
    }
    return head;
}