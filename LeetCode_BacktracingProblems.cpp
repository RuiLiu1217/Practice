#include "LeetCode_BacktracingProblems.hpp"
#include <functional>

/*
Google
*/
std::vector<std::string> LC::_0017_LetterCombinationsOfAPhoneNumber::letterCombinations(std::string& digits) {
    const int N = digits.size();
    if(N == 0) {
        return {};
    }
    std::vector<std::string> res;
    std::unordered_map<char, std::vector<char>> map;
    map['2'] = {'a', 'b', 'c'};
    map['3'] = {'d', 'e', 'f'};
    map['4'] = {'h', 'h', 'i'};
    map['5'] = {'j', 'k', 'l'};
    map['6'] = {'m', 'n', 'o'};
    map['7'] = {'p', 'q', 'r', 's'};
    map['8'] = {'t', 'u', 'v'};
    map['9'] = {'w', 'x', 'y', 'z'};
    std::function<void(int, int, std::string)> backtracing = [&](int i, int N, std::string tmp){
        if(i == N) {
            res.push_back(tmp);
            return;
        }
        auto nxtChar = map[digits[i]];
        for(auto n : nxtChar) {
            backtracing(i + 1, N, tmp + n);
        }
    };

    backtracing(0, N, "");
    return res;
}



/*
Google
*/
std::vector<std::string> LC::_0022_GenerateParentheses::generateParenthesis(int n) {
    if(n == 0) {
        return {};
    }
    std::vector<std::string> res;
    std::function<void(int, int, std::string)> backtracing = [&](int l, int r, std::string v){
        if(l < 0 || r < 0 || l > r) {
            return;
        }
        if(l == r && l == 0) {
            res.push_back(v);
            return;
        }
        backtracing(l - 1, r, v + "(");
        backtracing(l, r - 1, v + ")");
    };

    backtracing(n, n, "");
    return res;
}

// Solver of the sudoku
void LC::_0037_SudokuSolver::solveSudoku(std::vector<std::vector<char>>& board) {
    if(board.size() == 0 || board[0].size() == 0) {
        return;
    }

    std::function<bool(int row, int col, char c)> isValid = [&](int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] != '.' && board[i][col] == c) return false; //check row
            if(board[row][i] != '.' && board[row][i] == c) return false; //check column
            if( board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' && 
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c ) 
                return false; //check 3*3 block
        }
        return true;
    };

    std::function<bool()> solve = [&]() {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; ++c) {
                        if(isValid(i, j, c)) {
                            board[i][j] = c;
                            if(solve()) {
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
    };

    solve();
    return;        
}


std::vector<std::vector<std::string>> LC::_0051_NQueens::solveNQueens(int n) {
    std::string ol(n, '.');
    std::vector<std::string> tmp(n, ol);
    std::vector<std::vector<std::string>> res;
    solve(tmp, 0, n, res);
    return res;
}
    
void LC::_0051_NQueens::solve(std::vector<std::string>& tmp, int curN, int n, std::vector<std::vector<std::string>>& res) {
    if(curN == n) {
        res.push_back(tmp);
        return;
    }
    std::vector<int> available = availableQ(tmp, curN, n);
    for(int i = 0; i < available.size(); ++i) {
        if(available[i]) {
            tmp[curN][i] = 'Q';
            solve(tmp, curN + 1, n, res);
            tmp[curN][i] = '.';
        }
    }
}
    
std::vector<int> LC::_0051_NQueens::availableQ(std::vector<std::string> tmp, int curN, int n) {
    std::vector<int> available(n, 1);
    for(int i = 0; i < curN; ++i) {
        int dis = std::abs(curN - i);
        for(int j = 0; j < n; ++j) {
            if(tmp[i][j] == 'Q') {
                available[j] = 0;
                if(j + dis < n && j + dis >= 0) {
                    available[j + dis] = 0;
                }
                if(j - dis >= 0 && j - dis < n) {
                    available[j - dis] = 0;
                }
            }
        }
    }
    return available;
}


int LC::_0052_NQueensII::totalNQueens(int n) {
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    int totalSolution = 0;
    totalNQueens(board, 0, n, totalSolution);
    return totalSolution;
}

void LC::_0052_NQueensII::totalNQueens(std::vector<std::vector<int>>& board, int nIdx, const int totalRows, int& totalSolution) {
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

void LC::_0052_NQueensII::updateBoard(std::vector<std::vector<int>>& board, int i, int j) {
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

void LC::_0052_NQueensII::dedateBoard(std::vector<std::vector<int>>& board, int i, int j) {
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

