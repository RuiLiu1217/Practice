#include "LeetCode_BacktracingProblems.hpp"
#include <functional>
#include <algorithm>
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



std::vector<std::vector<int>> LC::_0039_CombinationSum::combinationSum(std::vector<int>& candidates, int target) {
    std::vector<int> tmp;
    std::vector<std::vector<int>> res;

    std::function<void(int)> fun = [&](int target) {
        if(target < 0) {
            return;
        }
        if(target == 0) {
            res.push_back(tmp);
        }

        for(int i = 0; i < candidates.size(); ++i) { // select element from the beginning each time
            // <= is to avoid reselect for example, after 1, 2 are generated, we should not generate 2, 1 again.
            if(tmp.empty() || (!tmp.empty() && tmp.back() <= candidates[i])) { 
                tmp.push_back(candidates[i]);
                fun(target - candidates[i]);
                tmp.pop_back();
            }
        }
    };

    fun(target);
    return res;
}

std::vector<std::vector<int>> LC::_0046_Permutations::permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;

    std::function<void(int)> permuteFun = [&](int begin) {
        if (begin == nums.size() - 1) {
            result.push_back(nums);
            return;
        }

        for (int i = begin; i < nums.size(); ++i) {
            std::swap(nums[begin], nums[i]);
            permuteFun(begin + 1);
            std::swap(nums[begin], nums[i]);
        }
    };

    permuteFun(0);
    return result;
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



std::vector<std::vector<int>> LC::_0077_Combinations::combine(int n, int k) {
    N = n;
    K = k;
    std::vector<std::vector<int>> res;
    if(n < k) {
        return res;
    }
    std::vector<int> temp;
    std::function<void(int, int)> comb = [&](int start, int num) {
        if(num == K){
            res.push_back(temp);
            return;
        }
        for(int i = start; i < N; i++) {
            temp.push_back(i+1);
            comb(i + 1, num + 1);
            temp.pop_back();
        }
    };
    comb(0, 0);
    return res;
}


std::vector<std::vector<int>> LC::_0078_Subsets::subsets(std::vector<int>& nums) {
    if(nums.size() == 0) {
        std::vector<std::vector<int>> res;
        res.push_back(std::vector<int>());
        return res;
    }
    std::function<std::vector<std::vector<int>>(int, int)> subset = [&](int beg, int end) {
        if(beg == end) {
            std::vector<std::vector<int>> res;
            res.push_back(std::vector<int>());
            return res;
        }

        int num = nums[beg];
        std::vector<std::vector<int>> sub1 = subset(beg+1, end);
        std::vector<std::vector<int>> res;
        res.reserve(sub1.size() * 2);
        for(int i = 0; i < sub1.size(); ++i) {
            auto t = sub1[i];
            res.push_back(t);
            t.push_back(num);
            res.push_back(t);
        }
        return res;
    };
    return subset(0, nums.size());
}


bool LC::_0079_WordSearch::exist(std::vector<std::vector<char>>& board, std::string word) {
    bool res = false;
    int end = word.size();
    
    std::function<bool(int, int, int)> EXIST = [&] (int i, int j, int start) {
         if(start == end) {
            return true;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }

        if(board[i][j] == word[start]) {
            char t = board[i][j];
            board[i][j] = '1';
            if (!(EXIST( i + 1, j, start + 1) ||
                EXIST(i - 1, j, start + 1) ||
                EXIST(i, j + 1, start + 1) ||
                EXIST(i, j - 1, start + 1))) {
                    board[i][j] = t;
                    return false;
            } else {
                board[i][j] = t;
                return true;
            }
        } else {
            return false;
        }
    };

    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[i].size(); ++j) {
            if (EXIST(i, j, 0)) {
                return true;
            }
        }
    }
    return res;
}



std::vector<std::vector<int>> LC::_0090_SubsetII::subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    std::vector<int> tmp;
    subset(res, tmp, nums, 0);
    return res;
}
    
void LC::_0090_SubsetII::subset(std::vector<std::vector<int>>& res, std::vector<int>& tmp,
            std::vector<int>& nums, int pos) {
    res.push_back(tmp);
    for(int i = pos; i < nums.size(); ++i) {
        if(i != pos && nums[i] == nums[i-1]) {
            continue;
        }
        tmp.push_back(nums[i]);
        subset(res, tmp, nums, i + 1); // i + 1, not pos + 1
        tmp.pop_back();
    }
}


void LC::_0130_SurroundedRegions::solve(std::vector<std::vector<char>>& board) {
    const int M = board.size();
    const int N = board[0].size();

    std::function<void(int, int, const char, const char)> dfs = [&] (int i, int j, const char orig, const char newc) {
        if(i < 0 || i >= M || j < 0 || j >= N) {
            return;
        }
        if(board[i][j] == orig) {
            board[i][j] = newc;
            dfs(i + 1, j, orig, newc);
            dfs(i - 1, j, orig, newc);
            dfs(i, j + 1, orig, newc);
            dfs(i, j - 1, orig, newc);
        }
    };

    // die to '.' first
    if(board.empty() || board[0].empty()) {
        return;
    }
    
    for(int i = 0; i < M; ++i) {
        dfs(i, 0, 'O', '.');
        dfs(i, N-1, 'O', '.');
    }
    for(int j = 0; j < N; ++j) {
        dfs(0, j, 'O', '.');
        dfs(M-1, j, 'O', '.');
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