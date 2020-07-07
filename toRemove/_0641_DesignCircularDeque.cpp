#include "headers.hpp"

/** Initialize your data structure here. Set the size of the deque to be k. */
LeetCode::_0641_DesignCircularDeque::_0641_DesignCircularDeque(int k) {
    q = std::vector<int>(k + 1, -1);
    start = 0;
    end = 0;
    K = k + 1;
}
    
/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool LeetCode::_0641_DesignCircularDeque::insertFront(int value) {
    if(isFull()) {
        return false;
    } else {
        start = (start + K - 1) % K;
        q[start] = value;
        return true;
    }
}
    
/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool LeetCode::_0641_DesignCircularDeque::insertLast(int value) {
    if(isFull()) {
        return false;
    } else {
        q[end] = value;
        end = (end + 1) % K;
        return true;
    }
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool LeetCode::_0641_DesignCircularDeque::deleteFront() {
    if(isEmpty()) {
        return false;
    } else {
        q[start] = -1;
        start = (start + 1) % K;
        return true;
    }
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool LeetCode::_0641_DesignCircularDeque::deleteLast() {
    if(isEmpty()) {
        return false;
    } else {
        q[(end - 1 + K) % K] = -1;
        end = (end - 1 + K) % K;
        return true;
    }
}

/** Get the front item from the deque. */
int LeetCode::_0641_DesignCircularDeque::getFront() {
    return q[start];
}

/** Get the last item from the deque. */
int LeetCode::_0641_DesignCircularDeque::getRear() {
    return q[(end-1+K) % K];
}

/** Checks whether the circular deque is empty or not. */
bool LeetCode::_0641_DesignCircularDeque::isEmpty() {
    return start == end;
}

/** Checks whether the circular deque is full or not. */
bool LeetCode::_0641_DesignCircularDeque::isFull() {
    return (end+1) % K == start;
}