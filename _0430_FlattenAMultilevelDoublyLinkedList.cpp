#include "headers.hpp"

LeetCode::_0430_FlattenAMultilevelDoublyLinkedList::Node* 
LeetCode::_0430_FlattenAMultilevelDoublyLinkedList::flatten(LeetCode::_0430_FlattenAMultilevelDoublyLinkedList::Node* head) {
    LeetCode::_0430_FlattenAMultilevelDoublyLinkedList::Node* curP = head;
    while(curP) {
        if(curP->child != nullptr) {
            LeetCode::_0430_FlattenAMultilevelDoublyLinkedList::Node* nh = flatten(curP->child);
            LeetCode::_0430_FlattenAMultilevelDoublyLinkedList::Node* nt = nh;
            while(nt->next != nullptr) {
                nt = nt->next;
            }
            LeetCode::_0430_FlattenAMultilevelDoublyLinkedList::Node* q = curP->next;
            nh->prev = curP;
            nt->next = q;
            curP->next = nh;
            if(q) {
                q->prev = nt;
            }
            curP->child = nullptr;                
        }
        curP = curP->next;
    }
    return head;
}