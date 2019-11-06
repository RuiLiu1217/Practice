#include "headers.hpp"

std::string LeetCode::_0316_RemoveDuplicateLetters::removeDuplicateLetters(std::string s) {
    int count[26] = {0};
    bool used[26] = {false};
    std::string res = "0";
    for(char& c : s) {
        ++count[c-'a'];
    }
    
    for(char& c : s) {
        --count[c - 'a']; // 用掉一个字符
        if(used[c - 'a']) { // 如果这个字符已经用过了，那就继续，也就是不再往结果字符串中添加这个字符了。
            continue;
        }
        // 当当前结果字符串最后一个字符比要放进去的字符大，而且字符串最后一位的字符在count中还有，
        // 也就是可以继续在后面找补回来，那么就先把最后字符串中的那个字符删掉，然后把对应这个字符标
        // 记为没用过。否则就在这个位子上一定要放这个字符了，否则没机会了。
        while(res.size() > 0 && res.back() > c && count[res.back() - 'a'] > 0) { 
            used[res.back() - 'a'] = false;
            res.pop_back();
        }
        res += c;
        used[c - 'a'] = true; // 放完这个字符后，就标记说这个字符已经用过了。
    }
    return res.substr(1);
}
