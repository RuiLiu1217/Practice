#include "headers.hpp"

std::string LeetCode::_1436_DestinationCity::destCity(std::vector<std::vector<std::string>>& paths) {
    std::unordered_map<std::string, int> outDegree;
    for(auto& p : paths) {
        ++outDegree[p[0]];
        if(outDegree.find(p[1]) == outDegree.end()) {
            outDegree[p[1]] = 0;
        }            
    }
    for(auto& d : outDegree) {
        if(d.second == 0) {
            return d.first;
        }
    }
    return "";
}