#ifndef FENWICKTREE_HPP
#define FENWICKTREE_HPP
#include <vector>
// Fenwick tree (Binary indexed tree)

// Subproblem : 
// x = 1110 (in binary), 
// How to get the last set bit?
// Solution:   (x & (-x))

class FenWickTree {
public:
    FenWickTree(int n) : sums_(n+1, 0){}
    void update(int i, int delta) {
        while(i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) const {
        int sum = 0;
        while(i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    static inline int lowbit(int i) {
        return i & (-i);
    }
    std::vector<int> sums_;
};


#endif