#include "headers.hpp"

// Copy from a solution
// Trie implementation

void LeetCode::_0211_AddAndSearchWordDataStructureDesign::addWord(std::string word) {
    TrieNode* node = root;
    for(char c : word) {
        if(!node->children[c - 'a']) {
            node->children[c - 'a'] = new TrieNode();
        }
        node = node->children[c - 'a'];
    }
    node->word = true;
}

bool LeetCode::_0211_AddAndSearchWordDataStructureDesign::search(std::string word) {
    return search(word.c_str(), root);
}

bool LeetCode::_0211_AddAndSearchWordDataStructureDesign::search(const char* word, TrieNode* node) {
    for(int i = 0; word[i] && node; ++i) {
        if(word[i] != '.') {
            node = node->children[word[i] - 'a'];
        } else {
            TrieNode* tmp = node;
            for(int j = 0; j < 26; ++j) {
                node = tmp->children[j];
                if(search(word + i + 1, node)) {
                    return true;
                }
            }
        }
    }
    return node && node->word;
}