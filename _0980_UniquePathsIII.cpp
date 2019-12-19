#include "headers.hpp"

static void findStart(std::vector<std::vector<int>>& grid, int& I, int& J, int& N) {
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j] == 1) {
                I = i;
                J = j;
            } else if(grid[i][j] == 0) {
                ++N;
            }
        }
    }
}

static int uniquePathsHelper(std::vector<std::vector<int>>& grid, int i, int j, int n) {
    const int M = grid.size();
    const int N = grid[0].size();

    if(i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == -1) {
        return 0;
    }

    if(grid[i][j] == 2) {
        return n == 0;
    }

    grid[i][j] = -1;
    int paths = uniquePathsHelper(grid, i + 1, j, n - 1) + 
    uniquePathsHelper(grid, i - 1, j, n - 1) + 
    uniquePathsHelper(grid, i, j - 1, n - 1) + 
    uniquePathsHelper(grid, i, j + 1, n - 1);
    grid[i][j] = 0;
    return paths;
}

int LeetCode::_0980_UniquePathsIII::uniquePathsIII(std::vector<std::vector<int>>& grid) {
    int startI = 0;
    int startJ = 0;
    int N = 1; // it have to start from 1 not 0, otherwise, the results will be 0 forever.
    findStart(grid, startI, startJ, N);
    return uniquePathsHelper(grid, startI, startJ, N);
}