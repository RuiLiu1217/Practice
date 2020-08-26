#include "headers.hpp"

class UnionFind {
public:
    std::vector<int> parent;
    int numOfComps;
    explicit UnionFind(int N) {
        parent.resize(N);
        for(int i = 0; i < N; ++i) {
            parent[i] = i;
        }
        numOfComps = N;
    }
    int find(int n) {
        if(parent[n] != n) {
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }
    
    void unionTwo(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) {
            return;
        }
        parent[pa] = pb; // For simple
        --numOfComps;
    }
    bool sameParent() {
        return numOfComps == 1;
    }
};

int _1011_TheEarliestMomentWhenEveryoneBecomeFriends::earliestAcq(std::vector<std::vector<int>>& logs, int N) {
    std::sort(begin(logs), end(logs), [](std::vector<int>& a, std::vector<int>& b){
        return a[0] < b[0];
    });
    UnionFind uf(N);
    for(auto& log : logs) {
        int time = log[0];
        uf.unionTwo(log[1], log[2]);
        if(uf.sameParent()) {
            return time;
        }
    }
    return -1;
}