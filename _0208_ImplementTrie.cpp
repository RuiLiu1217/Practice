#include "headers.hpp"
#include <string>

LeetCode::_0208_ImplementTrie::_0208_ImplementTrie() {}
    
    
void LeetCode::_0208_ImplementTrie::insert(std::string word) {
    _0208_ImplementTrie* p = this;
    for(int i = 0; i < word.size(); ++i) {
        if(p->children.find(word[i]) == p->children.end()) {
            p->children[word[i]] = new _0208_ImplementTrie();
        }
        p = p->children[word[i]];
    }
    p->isWord = true;   
}
    
bool LeetCode::_0208_ImplementTrie::search(std::string word) {
    _0208_ImplementTrie* p = this;
    for(int i = 0; i < word.size(); ++i) {
        if(p->children.find(word[i]) == p->children.end()) {
            return false;
        } else {
            p = p->children[word[i]];
        }
    }
    return p->isWord;
}



bool LeetCode::_0208_ImplementTrie::startsWith(std::string prefix) {
    _0208_ImplementTrie* p = this;
    for(int i = 0; i < prefix.size(); ++i) {
        if(p->children.find(prefix[i]) == p->children.end()) {
            return false;
        } else {
            p = p->children[prefix[i]];
        }
    }
    return (p != nullptr);
}

