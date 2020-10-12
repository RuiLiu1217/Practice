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


// Backtracking
int LC::_0200_NumberOfIslands::numIslands(std::vector<std::vector<char>>& grid) {
    const int M = grid.size();
    if(M == 0) {
        return 0;
    }
    const int N = grid[0].size();
    if(N == 0) {
        return 0;
    }
    int numIsland = 0;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(grid[i][j] == '1') {
                ++numIsland;
                eraseIsland(grid, i, j);
            }
        }
    }
    return numIsland;
}

void LC::_0200_NumberOfIslands::eraseIsland(std::vector<std::vector<char>>& grid, int i, int j) {   
    const int M = grid.size();
    if(M == 0) {
        return;
    }
    const int N = grid[0].size();
    if(N == 0) {
        return;
    }
    if(i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == '0') {
        return;
    } else {
        grid[i][j] = '0';
        eraseIsland(grid, i-1, j);
        eraseIsland(grid, i+1, j);
        eraseIsland(grid, i, j-1);
        eraseIsland(grid, i, j+1);
    }
}


std::vector<std::string> LC::_0212_WordSearchII::findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    for(auto& w : words) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == w[0]) {
                    findWords(board, i, j, w, 0);
                }
            }
        }
    }

    std::vector<std::string>myRes;
    for(auto& v : res) {
        myRes.push_back(v);
    }
    return myRes;
}

void LC::_0212_WordSearchII::findWords(std::vector<std::vector<char>>& board, int i, int j, const std::string& word, int idx) {
    if(idx == word.size() - 1 && !(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) && board[i][j] == word[idx]) {
        res.insert(word);
        return;
    }
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
        return;
    }
    if(board[i][j] == word[idx]) {
        board[i][j] = '.';
        findWords(board, i - 1, j, word, idx + 1);
        findWords(board, i + 1, j, word, idx + 1);
        findWords(board, i, j - 1, word, idx + 1);
        findWords(board, i, j + 1, word, idx + 1);
        board[i][j] = word[idx];
    }
}


std::vector<std::vector<int>> LC::_0216_CombinationSumIII::combinationSum3(int k, int n) {
    std::vector<int> tmp;
    std::vector<std::vector<int>> res;
    DFS(k, n, 1, tmp, res);
    return res;
}

 void LC::_0216_CombinationSumIII::DFS(int k, int n, int curV, 
    std::vector<int>& tmp, std::vector<std::vector<int>>& res) {
    if(k == 0 && n == 0) {
        res.push_back(tmp);
        return;
    }

    if((k == 0 && n != 0) || (k != 0 && n == 0) || (k == 1 && n > 9)) {
        return;
    }
    
    for(int t = curV; t <= 9; ++t) {
        tmp.push_back(t);
        DFS(k-1, n-t, t + 1, tmp, res); // one value can just use once.
        tmp.pop_back();
    }   
}


std::vector<std::string> LC::_0267_PalindromePermutationII::generatePalindromes(std::string S) {
    std::unordered_map<char, int> freq;
    for(char s : S) {
        ++freq[s];
    }
    int flag = 0;
    char extra = 0;
    std::string halfS;
    for(auto& c : freq) {
        if(c.second % 2 && flag == 1)  {
            return {};
        } else if(c.second % 2 && flag == 0) {
            flag = 1;
            extra = c.first;
        }
        halfS += std::string(c.second/2, c.first);
    }
    std::sort(begin(halfS), end(halfS));
    std::vector<int> visited(halfS.size(), 0);
    std::string tmp;
    std::vector<std::string> res;

    backtracking2(halfS, 0, halfS.size() - 1, res);
    if(extra && res.empty()) {
        res.push_back("");
    }
    
    std::vector<std::string> ret;
    for(auto r : res) {
        std::string rr = r;
        std::reverse(begin(rr), end(rr));
        if(extra == 0) {
            ret.push_back(r + rr);
        } else {
            ret.push_back(r + extra + rr);
        }
    }
    return ret;
}

// LeetCode:: 47 How to generate permutation with duplicates. 
void LC::_0267_PalindromePermutationII::backtracking(
    std::string hs, int level, std::vector<int>& visited, 
    std::string& tmp, std::vector<std::string>& res) {
    if(level >= hs.size()) {
        res.push_back(tmp);
    }
    for(int i = 0; i < hs.size(); ++i) {
        if(visited[i] == 1) {
            continue;
        }
        if(i > 0 && hs[i] == hs[i-1] && visited[i-1] == 0) { // avoid recalculate if duplicate character exist
            continue;
        }
        visited[i] = 1;
        tmp += hs[i];
        backtracking(hs, level + 1, visited, tmp, res);
        tmp.pop_back();
        visited[i] = 0;
    }
}

void LC::_0267_PalindromePermutationII::backtracking2(
    std::string hs, int start, int end, std::vector<std::string>& res ) {
    if(start == end) {
        res.push_back(hs);
        return;
    }

    for(int i = start; i <= end; ++i) {
        if(i != start && hs[i] == hs[start]) {
            continue;
        }
        std::swap(hs[i], hs[start]);
        backtracking2(hs, start+1, end, res);
    }
}


std::vector<std::vector<int>> LC::_0417_PacificAtlanticWaterFlow::pacificAtlantic(std::vector<std::vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) {
        return {};
    }
    
    std::vector<std::vector<int>> res;
    const int m = matrix.size();
    const int n = matrix[0].size();
    
    std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false));
    std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, false));
    
    for(int i = 0; i < m; ++i) {
        dfs(matrix, pacific, INT_MIN, i, 0);
        dfs(matrix, atlantic, INT_MIN, i, n-1);
    }
    for(int i = 0; i < n; ++i) {
        dfs(matrix, pacific, INT_MIN, 0, i);
        dfs(matrix, atlantic, INT_MIN, m-1, i);
    }
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (pacific[i][j] && atlantic[i][j]) {
                res.push_back({i, j});
            }
        }
    }
    return res;
}
    
void LC::_0417_PacificAtlanticWaterFlow::dfs(std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& visited, int pre, int i, int j) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < pre) {
        return;
    }
    
    visited[i][j] = true;
    dfs(matrix, visited, matrix[i][j], i-1, j);
    dfs(matrix, visited, matrix[i][j], i+1, j);
    dfs(matrix, visited, matrix[i][j], i, j-1);
    dfs(matrix, visited, matrix[i][j], i, j+1);
}


bool LC::_0679_24Games::judgePoint24(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    do {
        if (valid(nums)) return true;
    } while(next_permutation(nums.begin(), nums.end()));
    return false;
}

bool LC::_0679_24Games::valid(std::vector<int>& nums) {
    double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
    if (valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d)) return true;
    if (valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d)) return true;
    if (valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d)) return true;
    return false;
}
bool LC::_0679_24Games::valid(double a, double b, double c) {
    if(valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || (b && valid(a/b, c))) {
        return true;
    }
    if(valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || (c && valid(a, b/c))) {
        return true;
    }
    return false;
}
bool LC::_0679_24Games::valid(double a, double b) {
    if( std::abs(a+b-24.0) < 0.0001 ||
        std::abs(a-b-24.0) < 0.0001 ||
        std::abs(a*b-24.0) < 0.0001 ||
        (b && std::abs(a/b-24.0) < 0.0001)) {
            return true;
        }
    return false;
}

std::vector<std::vector<int>> LC::_0733_FloodFill::floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
    int M = image.size();
    if(M == 0) {
        return {};
    }
    int N = image[0].size();
    if(N == 0) {
        return {};
    }
    const int orgV = image[sr][sc];

    std::function<void(int sr, int sc)> dfs = [&](int sr, int sc) {
        if(sr < 0 || sr >= M || sc < 0 || sc >= N || image[sr][sc] == newColor) {
            return;
        }
        if(image[sr][sc] == orgV) {
            image[sr][sc] = newColor;
            dfs(sr + 1, sc);
            dfs(sr - 1, sc);
            dfs(sr, sc + 1);
            dfs(sr, sc - 1);
        }        
    };

    dfs(sr, sc);
    return image;
}


std::vector<std::string> LC::_0784_LetterCasePermutation::letterCasePermutation(std::string S) {
    std::string tmp;
    std::vector<std::string> res;
    backTracking(S, 0, tmp, res);
    return res;
}

void LC::_0784_LetterCasePermutation::backTracking(const std::string& S, int startIdx, std::string& tmp, std::vector<std::string>& res) {
    if(startIdx == S.size()) {
        res.push_back(tmp);
        return;
    }
    
    char c = S[startIdx];
    if(std::isalpha(c)) {
        tmp += std::tolower(c);
        backTracking(S, startIdx + 1, tmp, res);
        tmp.pop_back();
        tmp += std::toupper(c);
        backTracking(S, startIdx + 1, tmp, res);
        tmp.pop_back();
    } else {
        tmp += c;
        backTracking(S, startIdx + 1, tmp, res);
        tmp.pop_back();
    }
}


int LC::_1020_NumberOfEnclaves::numEnclaves(std::vector<std::vector<int>>& A) {
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

void LC::_1020_NumberOfEnclaves::DFS(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& visited, int i, int j) {
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


int LC::_1254_NumberOfClosedIslands::closedIsland(std::vector<std::vector<int>>& grid) {
    M = grid.size();
    N = grid[0].size();
    count = 0;
    if(M == 0 || N == 0) {
        return count;
    }
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if (grid[i][j] == 0) {
                bool touchEdge = false;
                DFS(grid, i, j, touchEdge);
                if(!touchEdge) {
                    ++count;
                }
            }
        }
    }
    return count;
}

void LC::_1254_NumberOfClosedIslands::DFS(std::vector<std::vector<int>>& grid, int I, int J, bool& touchEdge) {
    if(I < 0 || I >= M || J < 0 || J >= N || grid[I][J] == 1 || grid[I][J] == 2) { // Out of scope
        return;
    }
    if(grid[I][J] == 0) {
        if(I == 0 || I == M - 1 || J == 0 || J == N - 1) {  // This water touch the edge
            touchEdge = true;
        }
        grid[I][J] = 2;
        DFS(grid, I + 1, J, touchEdge);
        DFS(grid, I - 1, J, touchEdge);
        DFS(grid, I, J + 1, touchEdge);
        DFS(grid, I, J - 1, touchEdge);
    }
}

