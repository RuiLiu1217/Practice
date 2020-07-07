#include "headers.hpp"
#include <algorithm>
class UnionFind {
public:
    std::vector<int> parent;
    UnionFind(int m) {
        parent.resize(m);
        for(int i = 0; i < m; ++i) {
            parent[i] = i;
        }
    }
    int find(int m) {
        if(m != parent[m]) {
            parent[m] = find(parent[m]);
        }
        return parent[m];
    }
    void Union(int x, int y) {
        int mx = find(x);
        int my = find(y);
        if(mx != my) {
            parent[mx] = my;
        }
    }    
};


std::string smallestStringWithSwaps(std::string s, std::vector<std::vector<int>>& pairs) {
    UnionFind uf(s.size());
    for(int i = 0; i < pairs.size(); ++i) {
        uf.Union(pairs[i][0], pairs[i][1]);
    }
    
    std::vector<int> parent(s.size());
    for(int i = 0; i < parent.size(); ++i) {
        parent[i] = uf.find(i);
    }
    std::unordered_map<int, std::pair<std::string, int>> map;
    for(int i = 0; i < s.size(); ++i) {
        int parent = uf.find(i);
        if(map.find(parent) == map.end()) {
            std::string t(1,s[i]);
            map[parent] = std::make_pair(t, 0);
        } else {
            map[parent].first += s[i];
        }
    }
    for(auto& a : map) {
        std::sort(a.second.first.begin(), a.second.first.end());
    }
    for(int i = 0; i < s.size(); ++i) {
        int parent = uf.find(i);
        auto& pair = map[parent];
        s[i] = pair.first[pair.second++];
    }
    return s;
}