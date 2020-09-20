#include "headers.hpp"

namespace _0839_{
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
        if(mSet[xp].rank < mSet[yp].rank) { // xp rank > yp rank
            std::swap(xp, yp);
        }
        mSet[yp].parent = xp; // let yp's parent be xp
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

}

int LeetCode::_0839_SimilarStringGroups::numSimilarGroups(std::vector<std::string>& A) {
    const int N = A.size();
    _0839_::DisjointSet set(N);
    
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            if(areSimilar(A[i], A[j])) {
                set.Union(i, j);
            }
        }
    }
    return set.groupNum();
}

bool LeetCode::_0839_SimilarStringGroups::areSimilar(const std::string& a, const std::string& b) {
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