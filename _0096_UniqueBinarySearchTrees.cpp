#include "headers.hpp"

int LeetCode::_0096_UniqueBinarySearchTree::numTrees(int n) {
    DP.resize(n + 1, -1);
    return numTreesN(n);
}

int LeetCode::_0096_UniqueBinarySearchTree::numTreesN(int n) {
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        DP[0] = 1;
        return 1;
    }
    if(n == 1) {
        DP[1] = 1;
        return 1;
    }
    if(n == 2) {
        DP[2] = 2;
        return 2;
    }
    if(DP[n] != -1) {
        return DP[n];
    } else {
        int i = 0; 
        int sum = 0;
        for(i = 0; i != n; ++i) {
            sum += numTreesN(i) * numTreesN(n - i - 1);
        }
        DP[n] = sum;
        return sum;
    }
    
}
