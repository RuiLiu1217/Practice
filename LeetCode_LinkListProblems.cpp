#include "LeetCode_LinkListProblems.hpp"

LC::ListNode* LC::_0002_AddTwoNumbers::addTwoNumbers(LC::ListNode* l1, LC::ListNode* l2) {
    return addImpl(l1, l2, 0);
}

LC::ListNode* LC::_0002_AddTwoNumbers::addImpl(LC::ListNode* l1, LC::ListNode* l2, int carry) {
    if(l1 == nullptr && l2 == nullptr) {
        if(carry == 0) {
            return nullptr;
        } else {
            return new LC::ListNode(1);
        }
    } else {
        int va = l1 ? l1->val : 0;
        int vb = l2 ? l2->val : 0;
        int v = va + vb + carry;
        
        if(v >= 10) {
            v -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        LC::ListNode* t = new LC::ListNode(v);
        t->next = addImpl(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, carry);
        return t;
    }
    
}