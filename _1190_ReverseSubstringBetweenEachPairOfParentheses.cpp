#include "headers.hpp"
#include <stack>
#include <queue>
string reverseParentheses(string s) {
    std::stack<char> cache;
    for(char c : s) {
        if(c == '(' || (c <= 'z' && c >= 'a')) {
            cache.push(c);
        } else if(c == ')') {
            std::queue<char> q;
            while(!cache.empty() && cache.top() != '(') {
                q.push(cache.top());
                cache.pop();
            }
            if(!cache.empty() && cache.top() == '(') {
                cache.pop();
                while(!q.empty()) {
                    cache.push(q.front());
                    q.pop();
                }
            }
        }
    }
    
    std::string res;
    while(!cache.empty()) {
        res += cache.top();
        cache.pop();
    }
    std::reverse(res.begin(), res.end());
    return res;
}