#include "headers.hpp"

/*
class Solution {
private:
    ListNode* head;
    ListNode* p;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        head = new ListNode(INT_MAX);
        p = head;
        merge(lists);
        ListNode* h = head->next;
        head->next = nullptr;
        delete head;
        return h;
    }
    
    void merge(std::vector<ListNode*>& lists) {
        int I = 0;
        int minV = INT_MAX;
        int count = 0;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i]) {
                if(lists[i]->val < minV) {
                    minV = lists[i]->val;
                    I = i;
                }
            } else {
                ++count;
            }
        }
        if(count == lists.size()) {
            return;
        }
        p->next = lists[I];
        lists[I] = lists[I]->next;
        p = p->next;
        
        merge(lists);
    }
};
*/


/*
Google
*/

ListNode<int>* LeetCode::_0023_MergeKeSortedLists::mergeKLists(std::vector<ListNode<int>*>& lists) {
    if(lists.empty()) {
        return nullptr;
    }
    std::vector<ListNode<int>*> lst = lists;
    std::vector<bool> notChoose(lists.size(), false);
    int minVal = INT_MAX;
    int baseIdx = -1;
    for(int i = 0; i < lists.size(); ++i) {
        if(lists[i] == nullptr) {
            notChoose[i] = true;
            continue;
        }
        if(lists[i]->val < minVal) {
            minVal = lists[i]->val;
            baseIdx = i;
        }
    }

    if (finishSorting(notChoose)) {
        return nullptr;
    }
    ListNode<int>* Head = lists[baseIdx];
    ListNode<int>* ptr = Head;
    notChoose[baseIdx] = true;
    
    while(!finishSorting(notChoose)) {
        int minVal = INT_MAX;
        int minIdx = -1;
        for(int i = 0; i < lst.size(); ++i) {    
            if(notChoose[i] == false) {
                if(lst[i]->val < minVal) {
                    minVal = lst[i]->val;
                    minIdx = i;
                }
            }
        }
        ListNode<int>* p = lst[minIdx];
        lst[minIdx] = lst[minIdx]->next;
        if(lst[minIdx] == nullptr) {
            notChoose[minIdx] = true;
        }
        
        ListNode<int>* tmpMov = ptr;
        while (tmpMov && tmpMov->val < p->val) {
            tmpMov = tmpMov->next;
        }
        
        if (ptr != tmpMov) {
            while (ptr->next != tmpMov) {
                ptr = ptr->next;
            }
        }
        p->next = ptr->next;
        ptr->next = p;
        ptr = ptr->next;
    }
    return Head;
}

bool LeetCode::_0023_MergeKeSortedLists::finishSorting(std::vector<bool> notChoose) {
    for(int i = 0; i != notChoose.size(); ++i) {
        if(notChoose[i] == false) {
            return false;
        }
    }
    return true;
}