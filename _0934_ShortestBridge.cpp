#include "headers.hpp"

int LeetCode::_0934_ShortestBridge::shortestBridge(std::vector<std::vector<int>>& A) {
    for(int i = 0, found = 0; !found && i < A.size(); ++i) {
        for(int j = 0; !found && j < A[i].size(); ++j) {
            found = paint(A, i, j);
        }
    }

    for(int color = 2; ; ++color) {
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < A[i].size(); ++j) {
                if(A[i][j] == color && (
                    (expand(A, i-1, j, color) ||
                     expand(A, i+1, j, color) ||
                     expand(A, i, j-1, color) ||
                     expand(A, i, j+1, color)))) 
                {
                    return color - 2;
                }
            }
        }
    }
}

int LeetCode::_0934_ShortestBridge::paint(std::vector<std::vector<int>>& A, int i, int j) {
    if(i < 0 || j < 0 || i == A.size() || j == A[0].size() || A[i][j] != 1) {
        return 0;
    }
    A[i][j] = 2;
    return 1 + paint(A, i + 1, j) + paint(A, i - 1, j) + paint(A, i, j + 1) + paint(A, i, j - 1);
}

bool LeetCode::_0934_ShortestBridge::expand(std::vector<std::vector<int>>& A, int i, int j, int color) {
    if(i < 0 || j < 0 || i == A.size() || j == A[0].size()) {
        return false;
    }
    if(A[i][j] == 0) {
        A[i][j] = color + 1;
    }
    return A[i][j] == 1; // it means we meet the other island
}