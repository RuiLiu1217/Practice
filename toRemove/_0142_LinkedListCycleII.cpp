#include "headers.hpp"
// 使用快慢指针，先找到快慢指针相遇的地方，然后入口指针从开始点跟着慢指针一起向前走，直到相遇。
ListNode<int>* LeetCode::_0142_LinkedListCycleII::detectCycle(ListNode<int>* head) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode<int>* slow = head;
    ListNode<int>* fast = head;
    ListNode<int>* entry = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) {
            while(entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }
    return nullptr;    
}