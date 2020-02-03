#include "headers.hpp"

ListNode<int>* LeetCode::_0083_RemoveDuplicatesFromSortedList::deleteDuplicates(ListNode<int>* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode<int>* h = head;
    ListNode<int>* t = h->next;
    while(t != nullptr) {
        if(h->val == t-> val) {
            h->next = t->next;
            t = h->next;
            continue;
        } else {
            h = t;
            t = t->next;
        }
    }
    return head;
}

/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        std::queue<ListNode*> q;
        q.push(head);
        ListNode* t = head->next;
        while(t) {
            if(t->val != q.back()->val) {
                q.push(t);
            }
            t = t->next;
        }
        q.back()->next = nullptr;
        ListNode* h = q.front();
        q.pop();
        head = h;
        while(!q.empty()) {
            h->next = q.front();
            q.pop();
            h = h->next;
        }
        return head;
    }
};
*/