#include "headers.hpp"

ListNode<int>* LeetCode::_1171_RemoveZeroSumConsecutiveNodesFromLinkedList::removeZeroSumSublists(ListNode<int>* head) {
    ListNode<int>* newHead = new ListNode<int>(0);
    newHead->next = head;
    std::unordered_set<int> meetValue;
    meetValue.insert(0);
    std::stack<std::pair<ListNode<int>*, int>> st;
    st.push({newHead, 0});
    ListNode<int>* p = head;
    int sum = 0;
    while(p) {
        sum += p->val;
        
        if(meetValue.count(sum)) {
            while(!st.empty() && st.top().second != sum) {
                meetValue.erase(st.top().second);
                st.pop();
            }
            if(!st.empty()) {
                st.top().first->next = p->next;
            }
        } else {
            meetValue.insert(sum);
            st.push({p, sum});
        }
        p = p->next;
    }
    
    return newHead->next;
}