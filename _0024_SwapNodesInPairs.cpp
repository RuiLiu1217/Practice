#include "headers.hpp"

ListNode<int>* LeetCode::_0024_SwapNodesInPairs::swapPairs(ListNode<int>* head) {
    if(!head) {
        return nullptr;
    }
    ListNode<int>* cur = head;
    ListNode<int>* nxt = cur->next;
    if(!nxt) {
        return cur;
    }
    ListNode<int>* res = swapPairs(cur->next->next);
    nxt->next = cur;
    cur->next = res;
    head = nxt;
    return head;
}