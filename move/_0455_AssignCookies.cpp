#include "headers.hpp"
#include <queue>

int LeetCode::_0455_AssignCookies::findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> G;
    for(int a : g) {
        G.push(a);
    }
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> S;
    for(int a : s) {
        S.push(a);
    }
    
    int res = 0;
    while(!S.empty()) {
        if(G.empty()) {
            return res;
        }
        if(S.top() >= G.top()) {
            res++;
            S.pop();
            G.pop();
        } else {
            S.pop();
        }
    }
    return res;
}