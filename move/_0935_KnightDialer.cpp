#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0935_KnightDialer::multiply(
    const std::vector<std::vector<int>>& A,const std::vector<std::vector<int>>& B) {
    std::vector<std::vector<int>> C(10, std::vector<int>(10, 0));
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            long s = 0;
            for(int k = 0; k < 10; ++k) {
                s = (s + static_cast<long long>(A[i][k]) * B[k][j] % (1000000000 + 7)) % (1000000000 + 7);
            }
            C[i][j] = s;
        }
    }
    return C;
}

std::vector<std::vector<int>> LeetCode::_0935_KnightDialer::pow(std::vector<std::vector<int>>& A, int N) {
    if(N == 1) {
        return A;
    } else if(N % 2 == 0) {
        std::vector<std::vector<int>> t = pow(A, N/2);
        return multiply(t, t);
    } else {
        std::vector<std::vector<int>> t = pow(A, N/2);
        std::vector<std::vector<int>> t2 = multiply(t, t);
        return multiply(t2, A);
    }
}

int LeetCode::_0935_KnightDialer::summ(std::vector<std::vector<int>>& A) {
    long sum = 0;
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            sum = (sum + A[i][j]) % (1000000000+7);
        }
    }
    return sum % (1000000000+7);
}

int LeetCode::_0935_KnightDialer::knightDialer(int N) {
    if(N == 1) {
        return 10;
    } else {
        auto matrix = pow(A, N-1);
        return summ(matrix);
    }
}