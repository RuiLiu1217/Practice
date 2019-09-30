#include "headers.hpp"

int LeetCode::_0378_KthSmallestElementInASortedMatrix::kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
    int left = matrix[0][0];
    int right = matrix.back().back();
    while(left < right) {
        int mid = left + (right - left) / 2; // judge whether it is larger than target or not
        int cnt = search_less_equal(matrix, mid); // How many values are <= than mid;
        if(cnt < k) {
            left = mid + 1;   // the modification of the binary search
        } else {
            right = mid;
        }
    }
    return left;
}

    
int LeetCode::_0378_KthSmallestElementInASortedMatrix::search_less_equal(std::vector<std::vector<int>>& matrix, int target) {
    /*
    matrix = [
            [ 1,    5,  9],
            [10,   11, 13],
            [(12), 13, 15]
    ]
    */
    const int N = matrix.size(); // the size of the matrix along row and col directions are the same
    int i = N - 1; // For example, start from value (12) in the example
    int j = 0;
    int cnt = 0;
    while(i >= 0 && j < N) {
        if(matrix[i][j] <= target) {
            cnt += i + 1;
            ++j;
        } else {
            --i;
        }
    }
    return cnt;
}


