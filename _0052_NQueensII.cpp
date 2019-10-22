#include "headers.hpp"

int LeetCode::_0052_NQueensII::totalNQueens(int n) {
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    int totalSolution = 0;
    totalNQueens(board, 0, n, totalSolution);
    return totalSolution;
}

void LeetCode::_0052_NQueensII::totalNQueens(std::vector<std::vector<int>>& board, int nIdx, const int totalRows, int& totalSolution) {
    if(nIdx == totalRows) {
        ++totalSolution;
        return;
    }
    
    for(int n = 0; n < totalRows; ++n) {
        if(board[nIdx][n] == 0) {
            updateBoard(board, nIdx, n);
            totalNQueens(board, nIdx+1, totalRows, totalSolution);
            dedateBoard(board, nIdx, n);
        }
    }
}

void LeetCode::_0052_NQueensII::updateBoard(std::vector<std::vector<int>>& board, int i, int j) {
    const int N = board.size();
    ++board[i][j];
    for(int k = j+1; k < N; ++k) {
        ++board[i][k];
    }
    for(int k = j-1; k >= 0; --k) {
        ++board[i][k];
    }
    for(int k = i+1; k < N; ++k) {
        ++board[k][j];
    }
    for(int k = i-1; k >= 0; --k) {
        ++board[k][j];
    }
    for(int k1 = i+1, k2=j+1; k1 < N && k2 < N; ++k1, ++k2) {
        ++board[k1][k2];
    }
    for(int k1 = i-1, k2=j+1; k1 >= 0 && k2 < N; --k1, ++k2) {
        ++board[k1][k2];
    }
    for(int k1 = i+1, k2=j-1; k1 < N && k2 >= 0; ++k1, --k2) {
        ++board[k1][k2];
    }
    for(int k1 = i-1, k2=j-1; k1 >= 0 && k2 >= 0; --k1, --k2) {
        ++board[k1][k2];
    }
}

void LeetCode::_0052_NQueensII::dedateBoard(std::vector<std::vector<int>>& board, int i, int j) {
    const int N = board.size();
    --board[i][j];
    for(int k = j+1; k < N; ++k) {
        --board[i][k];
    }
    for(int k = j-1; k >= 0; --k) {
        --board[i][k];
    }
    for(int k = i+1; k < N; ++k) {
        --board[k][j];
    }
    for(int k = i-1; k >= 0; --k) {
        --board[k][j];
    }
    for(int k1 = i+1, k2=j+1; k1 < N && k2 < N; ++k1, ++k2) {
        --board[k1][k2];
    }
    for(int k1 = i-1, k2=j+1; k1 >= 0 && k2 < N; --k1, ++k2) {
        --board[k1][k2];
    }
    for(int k1 = i+1, k2=j-1; k1 < N && k2 >= 0; ++k1, --k2) {
        --board[k1][k2];
    }
    for(int k1 = i-1, k2=j-1; k1 >= 0 && k2 >= 0; --k1, --k2) {
        --board[k1][k2];
    }
}

