#include "headers.hpp"
#include <numeric>
#include <algorithm>

// Facebook

// Hint: merge sort inspired
std::vector<std::vector<int>> LeetCode::_0986_IntervalListIntersections::intervalIntersection(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {
    std::vector<std::vector<int>> res;
    for(auto i =0, j = 0; i < A.size() && j < B.size(); ) {
        if(A[i][1] < B[j][0]) {
            ++i;
        } else if(A[i][0] > B[j][1]) {
            ++j;
        } else {
            res.push_back({std::max(A[i][0], B[j][0]), std::min(A[i][1], B[j][1])});
            if(A[i][1] > B[j][1]) {
                ++j;
            } else {
                ++i;
            }
        }
    }
    return res;
}
