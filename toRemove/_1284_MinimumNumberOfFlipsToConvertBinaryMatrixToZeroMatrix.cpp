#include "headers.hpp"

int LeetCode::_1284_MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrix::minFlips(std::vector<std::vector<int>>& mat) {
    M = mat.size();
    if(M == 0) {
        return 0;
    }
    N = mat[0].size();
    if(N == 0){
        return 0;
    }
    int n = getInteger(mat);
    if(!n) {
        return 0;
    }
    std::unordered_set<int> visited;
    std::queue<int> q;
    q.push(n);
    int steps = 0;
    while(!q.empty()) {
        const int QS = q.size();
        for(int i = 0; i < QS; ++i) {
            int t = q.front();
            visited.insert(t);
            q.pop();
            if(!t) {
                return steps;
            }
            for(int i = 0; i < M; ++i) {
                for(int j = 0; j < N; ++j) {
                    int nt = oneFlip(i,j, t);
                    if(visited.find(nt) == visited.end()) {
                        q.push(nt);
                    }
                }
            }
        }
        ++steps;
    }
    return -1;
}

int LeetCode::_1284_MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrix::getInteger(std::vector<std::vector<int>>& mat) {
    int res = 0;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            int idx = i * N + j;
            res |= (mat[i][j]<<idx);
        }
    }
    return res;
}

int LeetCode::_1284_MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrix::oneFlip(int i, int j, int num) {
    
    int idx = i * N + j;
    int res = num;
    res ^= (1 << idx);
    if(i > 0) {
        res ^= (1<<((i-1) * N + j));
    }
    if(i < M - 1) {
        res ^= (1<<((i+1) * N + j));
    }
    if(j > 0) {
        res ^= (1<<(i * N + j - 1));
    }
    if(j < N - 1) {
        res ^= (1<<(i * N + j + 1));
    }
    
    return res;
}