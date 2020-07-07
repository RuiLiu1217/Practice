#include "headers.hpp"

ListNode<int>*  LeetCode::_0082_RemoveDuplicatesFromSortedListII::deleteDuplicates(ListNode<int>* head) {
    ListNode<int>* nh = new ListNode<int>(INT_MAX);
    nh->next = head;
    ListNode<int>* p = nh;
    while(p->next && p->next->next) {
        if(p->next->val == p->next->next->val) { // Found duplicates
            ListNode<int>* q = p->next->next;
            while(q && q->val == p->next->val) {
                q = q->next;
            }
            // Delete duplicate lists
            ListNode<int>* t = p->next;
            while(t != q) {
                ListNode<int>* m = t;
                t = t->next;
                delete m;
            }
            
            // re-point to the next position
            p->next = q;
        } else {
            p = p->next;
        }
    }
    head = nh->next;
    delete nh;
    return head;
}
