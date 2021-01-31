#include "LeetCode_UnionFindProblems.hpp"
#include <unordered_set>
#include <vector>

int LC::_0839_SimilarStringGroups::numSimilarGroups(std::vector<std::string>& A) {
    const int N = A.size();
    class DisjointSet {
    public:
        struct Elem {
            int parent;
            int rank;
            int size;
        };
        std::vector<Elem> mSet;
        DisjointSet(int n) {
            mSet.resize(n);
            for(int i = 0; i < n; ++i) {
                mSet[i].parent = i;
                mSet[i].rank = 0;
                mSet[i].size = 1;
            }
        }
        
        int find(int x) {
            if(mSet[x].parent != x) {
                mSet[x].parent = find(mSet[x].parent);
            }
            return mSet[x].parent;
        }

        void Union(int x, int y) {
            int xp = find(x);
            int yp = find(y);
            if(xp == yp) {
                return;
            }
            if(mSet[xp].rank < mSet[yp].rank) {
                std::swap(xp, yp);
            }
            mSet[yp].parent = xp;
            if(mSet[xp].rank == mSet[yp].rank) {
                mSet[xp].rank = mSet[xp].rank + 1;
            }
        }
        
        int groupNum() {
            std::unordered_set<int> s;
            for(auto& m : mSet) {
                s.insert(find(m.parent));
            }
            return s.size();
        }
    };

    DisjointSet set(N);
    
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            if(areSimilar(A[i], A[j])) {
                set.Union(i, j);
            }
        }
    }
    return set.groupNum();
}

bool LC::_0839_SimilarStringGroups::areSimilar(const std::string& a, const std::string& b) {
    if(a.size() != b.size()) {
        return false;
    }
    int i = -1;
    int j = -1;
    int count = 0;
    for(int k = 0; k < a.size(); ++k) {
        if(a[k] != b[k]) {
            if(count == 2) {
                return false;
            }
            if(i == -1) {
                count = 1;
                i = k;
            } else {
                count = 2;
                j = k;
            }
        }
    }
    if(i != -1 && j != -1) {
        if(a[i] == b[j] && a[j] == b[i]) {
            std::string va = a;
            std::string vb = b;
            std::swap(va[i], va[j]);
            return va == vb;
        }
    }
    return a == b;        
}


int LC::_1579_RemoveMaxNumberOfEdgesToKeepGraphFullyTraversable::maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
    class UnionFind {
public:
    std::vector<int> parent;
    std::vector<int> rank;
    UnionFind(const UnionFind& rgh) {
        parent = rgh.parent;
        rank = rgh.rank;
    }
    UnionFind(int n) {
        for(int i = 0; i < n; ++i) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }
    int find(int i) {
        if(parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
    bool uni(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) {
            return false;
        }
        
        if(rank[pa] > rank[pb]) {
            parent[pb] = pa;
            ++rank[pb];
        } else {
            parent[pa] = pb;
            ++rank[pa];
        }
        return true;
    }
};
    UnionFind uf(n);
    int e1 = 0;
    int e2 = 0;
    int count = 0;
    for(auto& edge : edges) {
        if(edge[0] == 3) { // for both Alice and Bob
            if(uf.uni(edge[1] - 1, edge[2] - 1)) {
                ++e1;
                ++e2;
            } else {
                ++count;
            }
        }
    }
    
    UnionFind uf0(uf);
    for(auto& edge : edges) {
        if(edge[0] == 1) { // for alice
            if(uf.uni(edge[1] - 1, edge[2] - 1)) {
                ++e1;
            } else {
                ++count;
            }
        }
    }
    
    for(auto& edge : edges) {
        if(edge[0] == 2) {
            if(uf0.uni(edge[1] - 1, edge[2] - 1)) {
                ++e2;
            } else {
                ++count;
            }
        }
    }
    
    return e1 == n-1 && e2 == n-1 ? count : -1;

}
