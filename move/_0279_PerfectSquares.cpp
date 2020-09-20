#include "headers.hpp"
#include <cmath>
#include <numeric>
#include <queue>

int LeetCode::_0279_PerfectSquares::numSquares(int n) {
    if(n <= 0) {
        return 0;
    }
    static std::vector<int> DP({0});
    while(DP.size() <= n) {
        int m = DP.size();
        int cntSquares = INT_MAX;
        for(int i = 1; i * i <= m; ++i) {
            cntSquares = std::min(cntSquares, DP[m - i * i] + 1);
        }
        DP.push_back(cntSquares);
    }
    return DP[n];
}

// Other solutions:

// Math based solution:
// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
static bool is_square(int n) {
    if(n < 0) {
        return false;
    }
    int c = std::sqrt(n);
    return c * c == n;
}
static int numSquares_Math(int n) {
    // If n is a perfect square, return 1.
    if(is_square(n)) 
    {
        return 1;  
    }
    
    // The result is 4 if and only if n can be written in the 
    // form of 4^k*(8*m + 7). Please refer to 
    // Legendre's three-square theorem.
    while ((n & 3) == 0) // n%4 == 0  
    {
        n >>= 2;  
    }
    if ((n & 7) == 7) // n%8 == 7
    {
        return 4;
    }
    
    // Check whether 2 is the result.
    int sqrt_n = (int)(std::sqrt(n)); 
    for(int i = 1; i <= sqrt_n; i++)
    {  
        if (is_square(n - i*i)) 
        {
            return 2;  
        }
    }  
    
    return 3;  
}

// BFS based solution
static int numSquares_BFS(int n) {
    if(n <= 0) {
        return 0;
    }

    // perfectSquares contain all perfect square numbers which
    // are smaller than or equal to n;
    std::vector<int> perfectSquares;

    // countPerfectSquares[i-1] is the least number of perfect square
    // numbers which sum to i
    std::vector<int> countPerfectSquares(n);

    // Get all the perfect square numbers which are smaller than or
    // equal to n
    for(int i = 1; i * i <= n; ++i) {
        perfectSquares.push_back(i * i);
        countPerfectSquares[i * i - 1] = 1;
    }

    // If n is a perfect square number, return 1 immediately
     if (perfectSquares.back() == n)
    {
        return 1;
    }

    // Consider a graph which consists of number 0, 1,...,n as
    // its nodes. Node j is connected to node i via an edge if  
    // and only if either j = i + (a perfect square number) or 
    // i = j + (a perfect square number). Starting from node 0, 
    // do the breadth-first search. If we reach node n at step 
    // m, then the least number of perfect square numbers which 
    // sum to n is m. Here since we have already obtained the 
    // perfect square numbers, we have actually finished the 
    // search at step 1.
    std::queue<int> searchQ;
    for (auto& i : perfectSquares)
    {
        searchQ.push(i);
    }

    int currCntPerfectSquares = 1;
    while (!searchQ.empty())
    {
        currCntPerfectSquares++;
        
        int searchQSize = searchQ.size();
        for (int i = 0; i < searchQSize; i++)
        {
            int tmp = searchQ.front();
            searchQ.pop();
            // Check the neighbors of node tmp which are the sum 
            // of tmp and a perfect square number.
            for (auto& j : perfectSquares)
            {
                if (tmp + j == n)
                {
                    // We have reached node n.
                    return currCntPerfectSquares;
                }
                else if ((tmp + j < n) && (countPerfectSquares[tmp + j - 1] == 0))
                {
                    // If cntPerfectSquares[tmp + j - 1] > 0, this is not 
                    // the first time that we visit this node and we should 
                    // skip the node (tmp + j).
                    countPerfectSquares[tmp + j - 1] = currCntPerfectSquares;
                    searchQ.push(tmp + j);
                }
                else if (tmp + j > n)
                {
                    // We don't need to consider the nodes which are greater than n.
                    break;
                }
            }
        }
    }
    return 0;
}