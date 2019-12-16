#include "headers.hpp"
#include <algorithm>
std::vector<std::vector<int>> LeetCode::_0832_FlippingAnImage::flipAndInvertImage(
    std::vector<std::vector<int>>& A) {
    for (auto & row : A) std::reverse(row.begin(), row.end());
    for (auto & row : A) {
        for (int & i : row) {
            i ^= 1;
        }
    }
    return A;
}