#include "headers.hpp"
/*
Google

Count the occurrence of all numbers in A and B,
and also the number of domino with two same numbers.

Try all possibilities from 1 to 6.
If we can make number i in a whole row,
it should satisfy that countA[i] + countB[i] - same[i] = n

Take example of
A = [2,1,2,4,2,2]
B = [5,2,6,2,3,2]

countA[2] = 4, as A[0] = A[2] = A[4] = A[5] = 2
countB[2] = 3, as B[1] = B[3] = B[5] = 2
same[2] = 1, as A[5] = B[5] = 2

We have countA[2] + countB[2] - same[2] = 6,
so we can make 2 in a whole row.

Time O(N), Space O(1)
*/
int LeetCode::_1007_MinimumDominoRotationsForEqualRow::minDominoRotations(std::vector<int>& A, std::vector<int>& B) {
    std::vector<int> countA(7, 0);
    std::vector<int> countB(7, 0);
    std::vector<int> same(7, 0);
    int n = A.size();
    for(int i = 0; i < n; ++i) {
        ++countA[A[i]];
        ++countB[B[i]];
        if(A[i] == B[i]) {
            ++same[A[i]];
        }
    }

    for(int i = 1; i < 7; ++i) {
        if(countA[i] + countB[i] - same[i] == n) {
            return n - std::max(countA[i], countB[i]);
        }
    }
    return -1;
}

/*  Solution 2
    Solution 2
Try make A[0] in a whole row,
the condition is that A[i] == A[0] || B[i] == A[0]
a and b are the number of swap to make a whole row A[0]

Try B[0]
the condition is that A[i] == B[0] || B[i] == B[0]
a and b are the number of swap to make a whole row B[0]

Return -1
*/
static int minDominoRotations2(std::vector<int>& A, std::vector<int>& B) {
    int n = A.size();
    for (int i = 0, a = 0, b = 0; i < n && (A[i] == A[0] || B[i] == A[0]); ++i) {
        if (A[i] != A[0]) a++;
        if (B[i] != A[0]) b++;
        if (i == n - 1) return std::min(a, b);
    }
    for (int i = 0, a = 0, b = 0; i < n && (A[i] == B[0] || B[i] == B[0]); ++i) {
        if (A[i] != B[0]) a++;
        if (B[i] != B[0]) b++;
        if (i == n - 1) return std::min(a, b);
    }
    return -1;
}

/*  But Why?
Find intersection set s of all {A[i], B[i]}
s.size = 0, no possible result.
s.size = 1, one and only one result.
s.size = 2, it means all dominoes are [a,b] or [b,a], try either one.
s.size > 2, impossible.
*/