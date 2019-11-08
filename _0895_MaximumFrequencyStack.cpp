#include "headers.hpp"

class _0895_MaximumFrequencyStack {
private:
    // Copy inspired by the solution
    std::map<int, int> freq; // A Map from x to the number of frequency occurences of x
    std::map<int, std::stack<int>> group; // group data according to their frequency. If push 5, 5 -->  group[1]->5,  group[2]->5 respectively.
    int maxFreq; // Keep the maximum frequency
public:

LeetCode::_0895_MaximumFrequencyStack::_0895_MaximumFrequencyStack() {
    maxFreq = 0;
}

void LeetCode::_0895_MaximumFrequencyStack::push(int x) {
    int freqOfx;
    if(freq.find(x) != freq.end()) {
        freqOfx = freq[x];
    } else {
        freqOfx = 0;
    }

    freqOfx = freqOfx + 1;
    freq[x] = freqOfx;
    if(freqOfx > maxFreq) {
        maxFreq = freqOfx;
    }
    if(group.find(freqOfx) == group.end()) {
        group[freqOfx] = std::stack<int>();
    }
    group[freqOfx].push(x);
}

int LeetCode::_0895_MaximumFrequencyStack::pop() {
    int x = group[maxFreq].top();
    group[maxFreq].pop();
    --freq[x];
    if(group[maxFreq].empty()) {
        --maxFreq;
    }
    return x;
}
