#include "headers.hpp"

ListNode<int>* LeetCode::_0002_AddTwoNumbers::addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2) {
    int carry = 0;
    ListNode<int>* head = new ListNode<int>(-1);
    ListNode<int>* p = head;
    while(l1 || l2 || carry) {
        int sum = 0;
        if(l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        ListNode<int>* n = new ListNode<int>(0);
        if(sum >= 10) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        n->val = sum;
        
        p->next = n;
        p = p->next;
    }
    ListNode<int>* q = head->next;
    delete head;
    return q;
}