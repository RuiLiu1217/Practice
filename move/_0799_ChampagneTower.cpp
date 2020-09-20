#include "headers.hpp"

double LeetCode::_0799_ChampagneTower::champagneTower(int poured, int query_row, int query_glass) {
    std::vector<std::vector<double>> A(101, std::vector<double>(101, 0));
    A[0][0] = poured;
    for(int k = 0; k <= query_row; ++k) {
        for(int i = 0; i <= k; ++i) {
            if(A[k][i] > 1.0) {
                A[k+1][i] += (A[k][i] - 1.0) / 2.0;
                A[k+1][i+1] += (A[k][i] - 1.0) / 2.0;
                A[k][i] = 1.0;
            }
        }
    }
    return A[query_row][query_glass] > 1.0 ? 1.0 : A[query_row][query_glass];
}