#include "headers.hpp"

void LeetCode::_0362_DesignHitCounter::hit(int timestamp) {
    if(head == nullptr) {
        Node* t = new Node();
        t->timeStamp = timestamp;
        t->hitNum = 1;
        head = t;
        tail = t;
    } else {
        if(tail->timeStamp == timestamp) {
            ++tail->hitNum;
        } else {
            Node *t = new Node();
            t->timeStamp = timestamp;
            t->hitNum = 1;
            t->prev = tail;
            tail->next = t;
            tail = tail->next;
        }
    }
}

int LeetCode::_0362_DesignHitCounter::getHits(int timestamp) {
    Node* t = head;
    int sum = 0;
    while(t != nullptr) {
        if(timestamp - t->timeStamp < 300) {
            sum += t->hitNum;
        }
        t = t->next;
    }
    return sum;
}