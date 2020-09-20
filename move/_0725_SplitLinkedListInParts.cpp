#include "headers.hpp"

std::vector<ListNode<int>*> LeetCode::_0725_SplitLinkedListInParts::splitListToParts(ListNode<int>* root, int k) {
    if(!root) {
        return std::vector<ListNode<int>*>(k, nullptr);
    }
    int ListLength = 0;
    ListNode<int>* p = root;
    while(p) {
        ++ListLength;
        p = p->next;
    }

    std::vector<int> ithLength(k, 0);
    int perLength = ListLength / k;
    for(int i = 0; i < k; ++i) {
        ithLength[i] = perLength;
    }
    int remain = ListLength - perLength * k;
    int i = 0;
    while(remain) {
        ++ithLength[i];
        --remain;
        ++i;
    }
    ListNode<int>* h = root;

    std::vector<ListNode<int>*> res(k, nullptr);
    for(int i = 0; i < k; ++i) {
        ListNode<int>* nh = new ListNode<int>(-1);
        nh->next = h;
        ListNode<int>* p = nh;
        while(ithLength[i] && p) {
            p = p->next;
            --ithLength[i];
        }
        if(p) {
            res[i] = h;
            h = p->next;
            p->next = nullptr; // need to delete the link to avoid the first element traversal to the end
        } else {
            res[i] = nullptr;
        }
        nh->next = nullptr;
        delete nh;
    }
    return res;
}

