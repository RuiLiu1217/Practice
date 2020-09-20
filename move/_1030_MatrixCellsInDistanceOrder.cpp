#include "headers.hpp"
#include <algorithm>
std::vector<std::vector<int>> LeetCode::_1030_MatrixCellsInDistanceOrder::allCellsDistOrder(int R, int C, int r0, int c0) {
    std::vector<std::pair<int, std::vector<int>>> tab(R * C, std::pair<int, std::vector<int>>());
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            tab[i * C + j].first = ManhattonDis(i, j, r0, c0);
            tab[i * C + j].second.push_back(i);
            tab[i * C + j].second.push_back(j);
        }
    }
    std::sort(tab.begin(), tab.end(), [](auto a, auto b){
        return a.first < b.first;
    });
    std::vector<std::vector<int>> res;
    for(int i = 0; i < tab.size(); ++i) {
        res.push_back(tab[i].second);
    }
    return res;
}

int LeetCode::_1030_MatrixCellsInDistanceOrder::ManhattonDis(int i, int j, int r0, int c0) {
    return std::abs(i - r0) + std::abs(j - c0);
}
