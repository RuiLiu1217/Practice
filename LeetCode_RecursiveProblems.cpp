#include "LeetCode_RecursiveProblems.hpp"

double LC::_0050_PowXN::myPow(double x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return x;
    }
    if(n == -1) {
        return 1.0 / x;
    }
    if(n % 2 == 0) {
        return myPow(x * x, n / 2);
    } else {
        if(n > 0) {
            return myPow(x * x, n / 2) * x;
        } else {
            return myPow(x * x, n / 2) / x;
        }
    }
}


std::vector<int> LC::_0089_GrayCode::grayCode(int n) {
    if(n == 0) {
        return {0};
    }
    if(n == 1) {
        return {0, 1};
    } else {
        std::vector<int> last = grayCode(n-1);
        std::vector<int> flip(last.rbegin(), last.rend());
        for(int i = 0; i < flip.size(); ++i) {
            flip[i] |= 1<<(n-1);
            last.push_back(flip[i]);
        }
        return last;
    }
}



int LC::_0096_UniqueBinarySearchTree::numTrees(int n) {
    DP.resize(n + 1, -1);
    return numTreesN(n);
}

int LC::_0096_UniqueBinarySearchTree::numTreesN(int n) {
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
