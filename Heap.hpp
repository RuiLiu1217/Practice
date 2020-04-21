#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <unordered_map>

class Heap {
public:
    std::vector<int> heap;
    std::unordered_map<int, std::vector<int>::iterator> id;
    
};

#endif