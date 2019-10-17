#include "headers.hpp"
#include <algorithm>
void LeetCode::_0048_RotateImage::rotate(std::vector<std::vector<int>>& matrix) {
    const size_t N = matrix.size();
    for(size_t i = 0; i < N - 1; ++i) {
        for(size_t j = i + 1; j < N; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i < matrix.size(); ++i) {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}