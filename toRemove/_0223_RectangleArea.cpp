#include "headers.hpp"
// Tag: Computational Geometry
int LeetCode::_0223_RectangleArea::computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int x = std::min(G, C) > std::max(E, A) ? (std::min(G, C) - std::max(E, A)) : 0;
    int y = std::min(D, H) > std::max(B, F) ? (std::min(D, H) - std::max(B, F)) : 0;
    return (D - B) * (C - A) + ((G - E) * (H - F) - x * y); // calculate minus first to avoid overflow
}