#ifndef FENWICKTREE_HPP
#define FENWICKTREE_HPP
#include <vector>
// Fenwick tree (Binary indexed tree)

// Subproblem : 
// x = 1110 (in binary), 
// How to get the last set bit?
// Solution:   (x & (-x))

class FenwickTree {
private:
    std::vector<int> BIT;
    int N;
public:
    FenwickTree(const std::vector<int>& a) {
        BIT.resize(a.size() + 1);
        N = a.size();
        for(int i = 1; i <= N; ++i) {
            update(i, a[i-1]);
        }
    }
    void update(int x, int val) {
        for(; x <= N; x += (x & -x)) {
            BIT[x] += val;
        }
    }

    void query(int x) {
        int sum = 0;
        for(; x >= 0; x -= (x &(-x))) {
            sum += BIT[x];
        }
    }
}


#endif