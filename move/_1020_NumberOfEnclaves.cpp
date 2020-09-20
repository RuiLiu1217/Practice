#include "headers.hpp"

int LeetCode::_1020_NumberOfEnclaves::numEnclaves(std::vector<std::vector<int>>& A) {
    const int M = A.size();
    if(M == 0) {
        return 0;
    }
    const int N = A[0].size();
    if(N == 0) {
        return 0;
    }
    
    std::vector<std::vector<int>> visited(M, std::vector<int>(N, 0));
    for(int j = 0; j < N; ++j) {
        DFS(A, visited, 0, j);
        DFS(A, visited, M-1, j);
    }
    
    for(int i = 0; i < M; ++i) {
        DFS(A, visited, i, 0);
        DFS(A, visited, i, N-1);
    }
    
    int c = 0;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(A[i][j] == 1) {
                ++c;
            }
        }
    }
    return c;
}

void LeetCode::_1020_NumberOfEnclaves::DFS(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& visited, int i, int j) {
    const int M = A.size();
    const int N = A[0].size();
    if(i < 0 || i >= M || j < 0 || j >= N || visited[i][j]) {
        return;
    }
    if(A[i][j] == 1 && visited[i][j] == 0) {
        A[i][j] = 3;
        visited[i][j] = 1;
        DFS(A, visited, i - 1, j);
        DFS(A, visited, i + 1, j);
        DFS(A, visited, i, j - 1);
        DFS(A, visited, i, j + 1);
    }
}