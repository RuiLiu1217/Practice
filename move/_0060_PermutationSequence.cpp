#include "headers.hpp"
#include <queue>

std::string LeetCode::_0060_PermutationSequence::getNext(std::string S) {
    int j = S.size() - 1;
    std::priority_queue<char> q;
    for(; j > 0; --j) {
        if(S[j] > S[j-1]) {
            break;
        } else {
            q.push(S[j]);
        }
    }

    std::string res(S.begin(), S.begin() + j);
    if(!q.empty()) {
        res += q.top();
        q.pop();
    }
    q.push(S[j]);
    while(!q.empty()) {
        res += q.top();
        q.pop();
    }
    return res;
}