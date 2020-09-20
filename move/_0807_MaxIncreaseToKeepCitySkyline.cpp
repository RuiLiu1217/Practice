#include "headers.hpp"

int LeetCode::_0807_MaxIncreaseToKeepCitySkyline::maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
    const int rowNum = grid.size();
    if(rowNum == 0) {
        return 0;
    }
    const int colNum = grid[0].size();
    if(colNum == 0) {
        return 0;            
    }
    std::vector<int> rowMaxV = rowMax(grid);
    std::vector<int> colMaxV = colMax(grid);
    
    int sum = 0;
    for(int rowIdx = 0; rowIdx != rowNum; ++rowIdx) {
        for(int colIdx = 0; colIdx != colNum; ++colIdx) {
            sum += (std::min(rowMaxV[rowIdx], colMaxV[colIdx]) - grid[rowIdx][colIdx]);
        }
    }
    return sum;
}

std::vector<int> LeetCode::_0807_MaxIncreaseToKeepCitySkyline::rowMax(const std::vector<std::vector<int>>& grid) {
    const int rowNum = grid.size();
    if(rowNum == 0) {
        return std::vector<int>();
    }
    const int colNum = grid[0].size();
    if(colNum == 0) {
        return std::vector<int>();            
    }
    std::vector<int> res(rowNum, -1);
    for(int rowIdx = 0; rowIdx != rowNum; ++rowIdx) {
        int maxV = -1;
        for(int colIdx = 0; colIdx != colNum; ++colIdx) {
            if(maxV < grid[rowIdx][colIdx]) {
                maxV = grid[rowIdx][colIdx];
            }
        }
        res[rowIdx] = maxV;
    }
    return res;
}


std::vector<int> LeetCode::_0807_MaxIncreaseToKeepCitySkyline::colMax(const std::vector<std::vector<int>>& grid) {
    const int rowNum = grid.size();
    if(rowNum == 0) {
        return std::vector<int>();
    }
    const int colNum = grid[0].size();
    if(colNum == 0) {
        return std::vector<int>();            
    }
    std::vector<int> res(colNum, -1);
    for(int colIdx = 0; colIdx != colNum; ++colIdx) {
        int maxV = -1;
        for(int rowIdx = 0; rowIdx != rowNum; ++rowIdx) {
            if(maxV < grid[rowIdx][colIdx]) {
                maxV = grid[rowIdx][colIdx];
            }
        }
        res[colIdx] = maxV;
    }
    return res;
}
