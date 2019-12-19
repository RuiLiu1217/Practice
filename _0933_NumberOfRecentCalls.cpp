#include "headers.hpp"

LeetCode::_0933_NumberOfRecentCalls::_0933_NumberOfRecentCalls() {

}

int LeetCode::_0933_NumberOfRecentCalls::ping(int t) {
     q.push(t);
    while(!q.empty() && t - q.front() > 3000) {
        q.pop();
    }
    return q.size();
}