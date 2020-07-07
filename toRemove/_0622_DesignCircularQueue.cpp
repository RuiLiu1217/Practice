#include "headers.hpp"

LeetCode::_0622_DesignCircularQueue::_0622_DesignCircularQueue(int k) {
    head = 0;
    tail = 0;
    N = k;
    q = std::vector<int> (k);
    empty = true;
}
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool LeetCode::_0622_DesignCircularQueue::enQueue(int value) {
    if (isFull()) return false;
    empty = false;
    q[tail] = value;
    tail = (tail+1) % N;
    return true;
}
    
/** Delete an element from the circular queue. Return true if the operation is successful. */
bool LeetCode::_0622_DesignCircularQueue::deQueue() {
    if (isEmpty()) return false;
    q[head] = 0;
    head = (head+1) % N;
    if (head == tail) empty = true;
    return true;
}

/** Get the front item from the queue. */
int LeetCode::_0622_DesignCircularQueue::Front() {
    if (isEmpty()) return -1;
    return q[head];
}

/** Get the last item from the queue. */
int LeetCode::_0622_DesignCircularQueue::Rear() {
    if (isEmpty()) return -1;
    return q[(tail-1+N)%N];
}

/** Checks whether the circular queue is empty or not. */
bool LeetCode::_0622_DesignCircularQueue::isEmpty() {
    return empty;
}

/** Checks whether the circular queue is full or not. */
bool LeetCode::_0622_DesignCircularQueue::isFull() {
    return (empty) ? false : head == tail;
}