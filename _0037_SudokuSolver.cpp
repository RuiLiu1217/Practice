#include "headers.hpp"

static bool isValid(std::vector<std::vector<char>>& board, int row, int col, char c) {
    for(int i = 0; i < 9; i++) {
        if(board[i][col] != '.' && board[i][col] == c) return false; //check row
        if(board[row][i] != '.' && board[row][i] == c) return false; //check column
        if(board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' && 
board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
    }
    return true;
}


static bool solve(std::vector<std::vector<char>>& board) {
    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[i].size(); ++j) {
            if(board[i][j] == '.') {
                for(char c = '1'; c <= '9'; ++c) {
                    if(isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if(solve(board)) {
                            return true;
                        } else {
                            board[i][j] = '.';
                        }
                    }
                }
                
                return false;
            }
        }
    }
    return true;
}


void LeetCode::_0037_SudokuSolver::solveSudoku(std::vector<std::vector<char>>& board) {
    if(board.size() == 0 || board[0].size() == 0) {
        return;
    }
    solve(board);
    return;        
}