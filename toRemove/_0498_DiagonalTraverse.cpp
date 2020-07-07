#include "headers.hpp"

 /*
    Consider the indices of the diagonals of a NxM matrix. Let's use a 3x4 matrix as an example:
    
    (0, 0) (0, 1) (0, 2) (0, 3)
    (1, 0) (1, 1) (1, 2) (1, 3)
    (2, 0) (2, 1) (2, 2) (2, 3)
    (3, 0) (3, 1) (3, 2) (3, 3)
    
    The first diagonal is (0, 0). The second is (0, 1), (1, 0), the third is (2, 0), (1, 1), (0, 2), etc.
    
    It should be clear that the sum of row i and column j is equal to the index of the diagonal 
    (diagonal number - 1). e.g. for the second diagonal (index 1), all possible pairings of (i, j) 
    sum to 1, i.e. i + j = 1 for the 2nd diagonal. The maximum diagonal index is simply 
    ((N-1) + (M-1)) = N + M - 2
    
    So to solve the problem we simply need iterate through all possible diagonal indices (denote this 
    as s) and find all possible pairs (i, j) such that i + j = s. The only thing we need to concern 
    ourselves about is the order. We can find the ordering by looking at whether the diagonal index 
    is even or odd. When the diagonal index is even we want to the first pair to be (s, 0) and when 
    it is odd when want the first pair to be (0, s), and we decrease or increase i/j by 1 accordingly.
*/
    
std::vector<int> LeetCode::_0498_DiagonalTraverse::findDiagonalOrder(std::vector<std::vector<int>>& matrix) {
    if(matrix.empty()) {
        return {};
    }
    std::vector<int> res;
    const int M = matrix.size();
    const int N = matrix[0].size();
    
    for(int s = 0; s <= M + N - 2; ++s) 
    {
        // for all i + j = s
        for(int x = 0; x <= s; ++x) {
            int i = x;
            int j = s - i;
            if(s % 2 == 0) {
                std::swap(i, j);
            }
            
            if(i >= M || j >= N) {
                continue;
            }
            
            res.push_back(matrix[i][j]);
        }
    }    
    return res;
}