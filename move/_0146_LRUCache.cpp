#include "headers.hpp"
// 抄答案的，需要认真从头再看尤其是list 的各种操作，需要熟悉。
LeetCode::_0146_LRUCache::_0146_LRUCache(int capacity) : mCapacity(capacity) {}

int LeetCode::_0146_LRUCache::get(int key) {
    const auto it = mMap.find(key);
    if(it == mMap.end()) {
        return -1;
    } else {
        // EXAMPLE: void splice (iterator position, list& x, iterator i);   
        // transfers only the element pointed by i from x into the container.
        // Transfers elements from x into the container, inserting them at position. 
        // This effectively inserts those elements into the container and removes them 
        // from x, altering the sizes of both containers. The operation does not involve 
        // the construction or destruction of any element. They are transferred, no 
        // matter whether x is an lvalue or an rvalue, or whether the value_type supports
        //  move-construction or not.
        mCache.splice(mCache.begin(), mCache, it->second);  // Move this key to the front of the list. 
        return it->second->second;
    }
}

void LeetCode::_0146_LRUCache::put(int key, int value) {
    const auto it = mMap.find(key);
    if(it != mMap.end()) {
        it->second->second = value;
        mCache.splice(mCache.begin(), mCache, it->second);
        return;
    }

    if(mCache.size() == mCapacity) {
        const auto& node = mCache.back();
        mMap.erase(node.first);
        mCache.pop_back();
    }
    mCache.emplace_front(key, value);
    mMap[key] = mCache.begin();
}


class Solution {
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    };
private:
    int capacity;
    int numOfNodes;
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> map;
public:
    Solution(int cap):capacity(cap) {
        numOfNodes = 0;
        head = nullptr;
        tail = head;
    }
    int get(int key) {
        if(map.find(key) == map.end()) {
            return -1;
        } else {
            Node* p = map[key];
            p->prev->next = p->next;
            p->next->prev = p->prev;
            head->prev = p;
            p->prev = nullptr;
            p->next = head;
            head = p;
            return p->val;
        }
    }
    void put(int key, int value) {
        if(map.find(key) != nullptr) {
            Node* p = map[key];
            p->prev->next = p->next;
            p->next->prev = p->prev;
            head->prev = p;
            p->prev = nullptr;
            p->next = head;
            head = p;
        } else {
            if(numOfNodes == capacity) {
                Node* todel = tail;
                tail = tail->prev;
                tail->next = nullptr;
                todel->prev = nullptr;
                todel->next = nullptr;
                delete todel;
                --numOfNodes;
            }
            Node* p = new Node(value);
            map[key] = p;
            p->next = head;
            if(head) {
                head->prev = p;
            } else {
                tail = p;
            }            
            head = p;
            ++numOfNodes;
        }
    }
};