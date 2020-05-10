#include "headers.hpp"

bool LeetCode::_0036_ValidSudoku::isValidSudoku(std::vector<std::vector<char>> &board) {
    for(int i = 0; i != 9; ++i) {
        if(existDuplicatePerRow(board, i)) {
            return false;
        }
    }
    for(int i = 0; i != 9; ++i) {
        if (existDuplicatePerColumn(board, i)) {
            return false;
        }
    }
    for(int i = 0; i != 3; ++i) {
        for(int j = 0; j != 3; ++j) {
            if (existDuplicatePerSquare(board, i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool LeetCode::_0036_ValidSudoku::existDuplicatePerSquare(std::vector<std::vector<char>> &board, int i, int j) {
    std::vector<int> ext(9, 0);
    for(int ii = 0; ii != 3; ++ii) {
        for(int jj = 0; jj != 3; ++jj) {
            char tmp = board[ii+i*3][jj+j*3];
            if(containDup(tmp, ext)) {
                return true;
            }
        }
    }
    return false;
    return false;
}

bool LeetCode::_0036_ValidSudoku::existDuplicatePerRow(std::vector<std::vector<char>> &board, int i) {
    std::vector<int> ext(9, 0);
    for(int ii = 0; ii != 9; ++ii) {
        char tmp = board[i][ii];
        if(containDup(tmp, ext)) {
            return true;
        }
    }
    return false;
}

bool LeetCode::_0036_ValidSudoku::existDuplicatePerColumn(std::vector<std::vector<char>> &board, int j) {
    std::vector<int> ext(9, 0);
    for(int ii = 0; ii != 9; ++ii) {
        char tmp = board[ii][j];
        if(containDup(tmp, ext)) {
            return true;
        }
    }
    return false;
}
