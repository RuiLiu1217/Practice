#include "headers.hpp"

std::string LeetCode::_0838_PushDominoes::pushDominoes(std::string dominoes) {
    const int N = dominoes.size();
    std::vector<int> leftSteps(N, INT_MAX);
    std::vector<int> rightSteps(N, INT_MAX);
    std::stack<int> cache;
    for(int i = 0; i < N; ++i) {
        if(dominoes[i] == '.') {
            cache.push(i);
        } else if(dominoes[i] == 'L') {
            while(!cache.empty()) {
                leftSteps[cache.top()] = i - cache.top();
                cache.pop();
            }
            leftSteps[i] = 0;
        } else if(dominoes[i] == 'R') {
            while(!cache.empty()) {
                leftSteps[cache.top()] = INT_MAX;
                cache.pop();
            }
            leftSteps[i] = INT_MAX;
        }
    }
    for(int i = N -1; i >= 0; --i) {
        if(dominoes[i] == '.') {
            cache.push(i);
        } else if(dominoes[i] == 'R') {
            while(!cache.empty()) {
                rightSteps[cache.top()] = cache.top() - i;
                cache.pop();
            }
            rightSteps[i] = 0;
        } else if(dominoes[i] == 'L') {
            while(!cache.empty()) {
                rightSteps[cache.top()] = INT_MAX;
                cache.pop();
            }
            rightSteps[i] = INT_MAX;
        }
    }
    std::string res;
    for(int i = 0; i < N; ++i) {
        if(leftSteps[i] < rightSteps[i]) {
            res += 'L';
        } else if(leftSteps[i] > rightSteps[i]) {
            res += 'R';
        } else {
            res += '.';
        }
    }
        
    return res;
}
