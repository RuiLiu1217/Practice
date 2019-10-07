#include "headers.hpp"

std::vector<int> LeetCode::_1122_RelativeSortArray::relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
    std::unordered_map<int, int> mapArr2;
    for(int i = 0; i < arr2.size(); ++i) {
        mapArr2[arr2[i]] = 0;
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(auto& a : arr1) {
        if(mapArr2.find(a) != mapArr2.end()) {
            ++mapArr2[a];
        } else {
            pq.push(a);
        }
    }
    
    std::vector<int> res;
    for(int i = 0; i < arr2.size(); ++i) {
        int c = mapArr2[arr2[i]];
        for(int k = 0; k < c; ++k) {
            res.push_back(arr2[i]);
        }
    }
    while(!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}