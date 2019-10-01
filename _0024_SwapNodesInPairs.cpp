#include "headers.hpp"

ListNode<int>* LeetCode::_0024_SwapNodesInPairs::swapPairs(ListNode<int>* head) {
    if(!head) {
        return nullptr;
    }
    ListNode* cur = head;
    ListNode* nxt = cur->next;
    if(!nxt) {
        return cur;
    }
    ListNode* res = swapPairs(cur->next->next);
    nxt->next = cur;
    cur->next = res;
    head = nxt;
    return head;
}