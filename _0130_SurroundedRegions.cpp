#include "headers.hpp"

void LeetCode::_0130_SurroundedRegions::solve(std::vector<std::vector<char>>& board) {
    // die to '.' first
    if(board.empty() || board[0].empty()) {
        return;
    }
    const int M = board.size();
    const int N = board[0].size();
    
    for(int i = 0; i < M; ++i) {
        DFS(board, i, 0, M, N, 'O', '.');
        DFS(board, i, N-1, M, N, 'O', '.');
    }
    for(int j = 0; j < N; ++j) {
        DFS(board, 0, j, M, N, 'O', '.');
        DFS(board, M-1, j, M, N, 'O', '.');
    }
    
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(board[i][j] == '.') {
                board[i][j] = 'O';
            } else {
                board[i][j] = 'X';
            }
        }
    }
}

void LeetCode::_0130_SurroundedRegions::DFS(
    std::vector<std::vector<char>>& board, 
    int i, int j, const int M, const int N,
    const char orig, const char newc) {
    if(i < 0 || i >= M || j < 0 || j >= N) {
        return;
    }
    if(board[i][j] == orig) {
        board[i][j] = newc;
        DFS(board, i + 1, j, M, N, orig, newc);
        DFS(board, i - 1, j, M, N, orig, newc);
        DFS(board, i, j + 1, M, N, orig, newc);
        DFS(board, i, j - 1, M, N, orig, newc);
    }
}