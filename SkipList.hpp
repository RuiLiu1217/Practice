#ifndef SKIPLIST_HPP
#define SKIPLIST_HPP
#include <bits/stdc++.h>
#include <memory>

class Node {
public:
    int key;
    Node** forward;
    Node(int key, int level) {
        this->key = key;
        forward = new Node*[level + 1];
        for(int i = 0; i <= level; ++i) {
            forward[i] = nullptr;
        }        
    }
};


class SkipList {
    
}


#endif