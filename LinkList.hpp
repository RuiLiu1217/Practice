#ifndef LINKLIST_HPP
#define LINKLIST_HPP
template<typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(const T& v) : val(v), next(nullptr) {}
};
#endif