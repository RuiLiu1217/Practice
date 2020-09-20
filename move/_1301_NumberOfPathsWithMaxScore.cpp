#include "headers.hpp"
std::vector<int> LeetCode::_1301_NumberOfPathsWithMaxScore::pathsWithMaxScore(std::vector<std::string>& bd) {
    const int M = bd.size();
    const int N = bd[0].size();
    const int MOD = 1000000000 + 7;
    std::vector<std::vector<char>> board(M);
    std::vector<std::vector<std::pair<int, int>>> DP(M);
    
    for(int i = 0; i < M; ++i) {
        board[i].resize(N);
        DP[i].resize(N);
        for(int j = 0; j < N; ++j) {
            board[i][j] = bd[i][j];
            DP[i][j] = std::make_pair(0, 0);
        }
    }
    // first is accumulated score;
    // second is number of paths;
    DP[M-1][N-1] = std::make_pair(0, 1);
    bool hasX = false;
    for(int j = N-2; j >= 0; --j) {
        if(!hasX) {
            if(board[M-1][j] == 'X')
            {
                DP[M-1][j] = std::make_pair(0, 0);
                hasX = true;
            } else {
                DP[M-1][j] = std::make_pair((DP[M-1][j+1].first + board[M-1][j] - '0') % MOD, 1);
            }
        } else {
            DP[M-1][j] = std::make_pair(0, 0);
        }
        
    }
    hasX = false;
    for(int i = M-2; i >= 0; --i) {
        if(!hasX) {
            if(board[i][N-1] == 'X') {
                DP[i][N-1] = std::make_pair(0, 0);
                hasX = true;
            } else {
                DP[i][N-1] = std::make_pair((DP[i+1][N-1].first + board[i][N-1] - '0') % MOD, 1);
            }
        } else {
            DP[i][N-1] = std::make_pair(0, 0);
        }
    }
    DP[0][0] = std::make_pair(0, 0);
    
    for(int i = M-2; i >= 0; --i) {
        for(int j = N-2; j >= 0; --j) {
            if(board[i][j] == 'X') {
                DP[i][j] = std::make_pair(0, 0);
            } else {
                int sc = 0;
                if(board[i][j] >= '0' && board[i][j] <= '9') {
                    sc = board[i][j] - '0';
                }
                if(!(DP[i+1][j].first == 0 && DP[i+1][j].second == 0)) {
                    DP[i][j] = std::make_pair((DP[i+1][j].first + sc) % MOD,DP[i+1][j].second);
                }
                
                if(!(DP[i][j+1].first == 0 && DP[i][j+1].second == 0)) {
                    if(DP[i][j+1].first + sc > DP[i][j].first) {
                        DP[i][j].first = (DP[i][j+1].first + sc) % MOD;
                        DP[i][j].second = DP[i][j+1].second;
                    } else if(DP[i][j+1].first + sc == DP[i][j].first) {
                        DP[i][j].second = (DP[i][j].second + DP[i][j+1].second) % MOD;
                    }
                }
                
                if(!(DP[i+1][j+1].first == 0 && DP[i+1][j+1].second == 0)) {
                    if(DP[i+1][j+1].first + sc > DP[i][j].first) {
                        DP[i][j].first = (DP[i+1][j+1].first + sc) % MOD;
                        DP[i][j].second = DP[i+1][j+1].second;
                    } else if (DP[i+1][j+1].first + sc == DP[i][j].first) {
                        DP[i][j].second = (DP[i][j].second + DP[i+1][j+1].second) % MOD;
                    }
                }
            }
        }
    }
    return {DP[0][0].first, DP[0][0].second};
}