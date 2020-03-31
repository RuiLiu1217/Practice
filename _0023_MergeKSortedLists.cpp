#include "headers.hpp"

/*
Google, Facebook
*/

ListNode<int>* LeetCode::_0023_MergeKeSortedLists::mergeKLists(std::vector<ListNode<int>*>& lists) {
    p = new ListNode<int>(-1);
    fh = p;
    auto Comp = [](ListNode<int>* a, ListNode<int>* b) { return a->val > b->val;};
    
    std::priority_queue<ListNode<int>*, std::vector<ListNode<int>*>, decltype(Comp)> pq{Comp};
    for(int i = 0; i < lists.size(); ++i) {
        if(lists[i]) {
            pq.push(lists[i]);
        }
    }
    while(!pq.empty()) {
        ListNode<int>* n = pq.top();
        pq.pop();
        if(n->next) {
            pq.push(n->next);
        }
        n->next = nullptr;
        p->next = n;
        p = p->next;
    }
    return fh->next;
}
