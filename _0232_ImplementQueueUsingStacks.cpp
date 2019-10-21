#include "headers.hpp"

LeetCode::_0232_ImplementQueueUsingStacks::_0232_ImplementQueueUsingStacks(){

}
void LeetCode::_0232_ImplementQueueUsingStacks::push(int x) {
    while(!right.empty()){
        left.push(right.top());
        right.pop();
    }
    left.push(x);
}
int LeetCode::_0232_ImplementQueueUsingStacks::pop() {
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    int a = right.top();
    
    right.pop();
    return a;
}
int LeetCode::_0232_ImplementQueueUsingStacks::peek() {
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    return right.top();
}
bool LeetCode::_0232_ImplementQueueUsingStacks::empty() {
    return (left.empty() && right.empty());
}