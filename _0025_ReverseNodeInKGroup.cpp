#include "headers.hpp"

ListNode<int>* LeetCode::_0025_ReverseNodeInKGroup::reverseGroup(ListNode<int>* head, int k) {
    // Create a fake head;
    ListNode<int>* fh = new ListNode<int>(INT_MIN);
    fh->next = head;

    int t = k;
    ListNode<int>* p = fh;
    while(t && p) {
        p = p->next;
        --t;
    }

    if(t != 0 || p == nullptr) {
        return head; // not sufficient for one group, just directly return;
    } else {
        ListNode<int>* pn = p->next;
        p->next = nullptr;
        fh->next = nullptr; delete fh;
        ListNode<int>* newHead = reverse(head);
        ListNode<int>* tmp = newHead;
        while(tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = reverseGroup(pn, k);
        return newHead;
    }
}
// Reverse a link list
ListNode<int>* LeetCode::_0025_ReverseNodeInKGroup::reverse(ListNode<int>* head) {
    ListNode<int>* pre = nullptr;
    ListNode<int>* cur = head;
    ListNode<int>* nex = head->next;
    while(cur) {
        cur->next = pre;
        pre = cur;
        cur = nex;
        if(nex) {
            nex = nex->next;
        }
    }
    return pre;
};