#include "headers.hpp"
#include <algorithm>
int LeetCode::_0120_Triangle::minimumTotal(std::vector<std::vector<int>>& triangle) {
    /*std::vector<std::vector<int>> DP = triangle;
    DP[0][0] = triangle[0][0];
    for(int i = 1; i < DP.size(); ++i) {
        for(int j = 0; j <= i; ++j) {
            if(j == 0) {
                DP[i][j] = DP[i-1][j] + triangle[i][j];
            } else if(j == i) {
                DP[i][j] = DP[i-1][j-1] + triangle[i][j];
            } else {
                DP[i][j] = std::min(DP[i-1][j-1], DP[i-1][j]) + triangle[i][j];
            }
        }
    }
    DP.back().resize(triangle.size());
    auto it = std::min_element(DP.back().begin(), DP.back().end());
    return *it;
    */
    
    std::vector<int> DP[2];
    DP[0].resize(1);
    DP[0] = triangle[0];
    for(int i = 1; i < triangle.size(); ++i) {
        const int rowIdx = i % 2;
        const int lstIdx = (i-1) % 2;
        DP[rowIdx].resize(i + 1);
        for(int j = 0; j <= i; ++j) {
            if(j == 0) {
                DP[rowIdx][j] = DP[lstIdx][j] + triangle[i][j];
            } else if(j == i) {
                DP[rowIdx][j] = DP[lstIdx][j-1] + triangle[i][j];
            } else {
                DP[rowIdx][j] = std::min(DP[lstIdx][j-1], DP[lstIdx][j]) + triangle[i][j];
            }
        }
    }
    std::vector<int>& r = DP[(triangle.size() - 1) % 2];
    auto it = std::min_element(r.begin(), r.end());
    return *it;
}
