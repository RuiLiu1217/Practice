#include "headers.hpp"
#include <stack>
std::string LeetCode::_1209_RemoveAllAdjacentDuplicatesInStringII::removeDuplicates(std::string s, int k) {
    std::stack<char> charStack;
    std::stack<int> countStack;
    for(char c : s) {
        if(charStack.empty()) {
            charStack.push(c);
            countStack.push(1);
        } else {
            while(!countStack.empty() && countStack.top() >= k) {
                countStack.pop();
                charStack.pop();
            } 
            if(!charStack.empty() && c == charStack.top()) {
                int cnt = countStack.top();
                countStack.pop();
                ++cnt;
                countStack.push(cnt);
            } else {
                countStack.push(1);
                charStack.push(c);  
            }
        }
    }
    
    while(!countStack.empty() && countStack.top() >= k) {
        countStack.pop();
        charStack.pop();
    }
    std::string res;
    while(!countStack.empty() && !charStack.empty()) {
        int cou = countStack.top();
        countStack.pop();
        char ch = charStack.top();
        charStack.pop();
        
        for(int i = 0; i < cou; ++i) {
            res += ch;
        }
    }
    std::reverse(res.begin(), res.end());
    
    return res;
}
