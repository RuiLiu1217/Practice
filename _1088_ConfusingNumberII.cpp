#include "headers.hpp"

int LeetCode::_1088_ConfusingNumberII::confusingNumberII(int N) {
    count = 0;
    for(int x : {1, 6, 8, 9}) {
        DFS(x, N);
    }
    return count;
}

void LeetCode::_1088_ConfusingNumberII::DFS(long long n, int N) {
    if(n > N) {
        return;
    }
    if(isConfusing(n)) {
        ++count;
    }
    for(int x : {0, 1, 6, 8, 9}) {
        DFS(n * 10 + x, N);
    }
}

bool LeetCode::_1088_ConfusingNumberII::isConfusing(int x) {
    int arr[10];
    int i = 0;
    while(x) {
        arr[i++] = x % 10;
        x /= 10;
    }
    for(int l = 0, r = i - 1; l <= r; ++l, --r) {
        if(arr[l] != mp[arr[r]]) {
            return true;
        }
    }
    return false;
}