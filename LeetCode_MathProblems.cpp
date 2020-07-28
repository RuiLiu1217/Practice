#include "LeetCode_MathProblems.hpp"
#include <cmath>
#include <climits>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <vector>
/*
Google
*/
int LC::_0007_ReverseInteger::reverse(int x) {
    long long res = 0; // Consider the overflow
    while(x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res; // The difficulty is the attention of overflow
}


// Google
bool LC::_0009_PalindromeNumber::isPalindrome(int x) {
   if(x < 0) {
        return false;
    }
    
    int t = x;
    long res = 0;
    while(t) {
        res = res * 10 + t % 10;
        t /= 10;
    }
    return res == x;
}



//! TODO: 
// Facebook
int LC::_0029_DivideTwoIntegers::divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    if(divisor == 1) {
        return dividend;
    }
    long dvd = std::labs(dividend); // LONG DATATYPE ABSOLUTE VALUE
    long dvs = std::labs(divisor);
    long ans = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    
    while (dvd >= dvs) {
        long temp = dvs, m = 1;
        while (temp << 1 <= dvd) {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return sign * ans;
}

// String, Mathematics, Recursive
int LC::_0171_ExcellSheetColumnNumber::titleToNumber(std::string s) {
    if(s.empty()) {
        return 0;
    }
    if(s.size() == 1) {
        return (s[0] - 'A' + 1);
    }
    else {
        char ss = s.back();
        std::string subS = s.substr(0, s.size() - 1);
        return titleToNumber(subS) * 26 + (ss - 'A' + 1);
    }
}

std::string LC::_0168_ExcelSheetColumnTitle::convertToTitle(int n) {
    return n == 0 ? "" : convertToTitle(n / 26) + (char) (--n % 26 + 'A');
}

// Recursive, mathematics
int LC::_0172_FactorialTrailingZeroes::trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}


int LC::_0202_HappyNumber::gat(int n) {
    int sum = 0;
    while(n > 0) {
        sum += std::pow(n % 10, 2);
        n = n / 10;
    }
    return sum;
}

bool LC::_0202_HappyNumber::isHappy(int n) {
    int newN = gat(n);
    std::unordered_set<int> loops;
    if(newN == 1) {
        return true;
    }
    while(!loops.count(newN)) {
        loops.insert(newN);
        newN = gat(newN);
        if(newN == 1) {
            return true;
        }
    }
    return false;        
}


// Very tricky solution
int LC::_0204_CountPrimes::countPrimes(int n) {
    if(n <= 2) {
        return 0;
    }
    std::vector<bool> isPrime(n,true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 4; i < n; i = i + 2) {
        isPrime[i] = false;
    }

    int sqt = std::sqrt(n);
    for(int i = 3; i <= sqt; i = i + 2) {
        if(isPrime[i]) {
            for(int j = i * i; j < n; j = j + i) {
                isPrime[j] = false;
            }
        }
    }
    return std::count(isPrime.begin(), isPrime.end(), true);   
}


// Tag: Computational Geometry
int LC::_0223_RectangleArea::computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int x = std::min(G, C) > std::max(E, A) ? (std::min(G, C) - std::max(E, A)) : 0;
    int y = std::min(D, H) > std::max(B, F) ? (std::min(D, H) - std::max(B, F)) : 0;
    return (D - B) * (C - A) + ((G - E) * (H - F) - x * y); // calculate minus first to avoid overflow
}