#include "headers.hpp"

void dfs(std::vector<std::vector<int>>& image, int sr, int sc, int orgV, int newColor, int M, int N) {
    if(sr < 0 || sr >= M || sc < 0 || sc >= N || image[sr][sc] == newColor) {
        return;
    }
    if(image[sr][sc] == orgV) {
        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, orgV, newColor, M, N);
        dfs(image, sr - 1, sc, orgV, newColor, M, N);
        dfs(image, sr, sc + 1, orgV, newColor, M, N);
        dfs(image, sr, sc - 1, orgV, newColor, M, N);
    }        
}

std::vector<std::vector<int>> LeetCode::_0733_FloodFill::floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
    int M = image.size();
    if(M == 0) {
        return {};
    }
    int N = image[0].size();
    if(N == 0) {
        return {};
    }
    int orgV = image[sr][sc];
    dfs(image, sr, sc, orgV, newColor, M, N);
    return image;
}