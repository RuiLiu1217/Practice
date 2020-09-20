#include "headers.hpp"
#include <unordered_set>

static std::vector<std::string> getNextMutation(std::string t,const std::unordered_set<std::string>& bank,
                                        const std::unordered_set<std::string>& visited) {
    char S[4] = {'A', 'G', 'C', 'T'};
    std::vector<std::string> res;
    for(int i = 0; i < t.size(); ++i) {
        char ti = t[i];
        for(int c = 0; c != 4; ++c) {
            if(ti != S[c]) {
                t[i] = S[c];
                if(bank.find(t) != bank.end() && visited.find(t) == visited.end()) {
                    res.push_back(t);
                }
                t[i] = ti;
            }
        }
    }
    return res;
}

int LeetCode::_0433_MinimumGeneticMutation::minMutation(std::string start, std::string end, std::vector<std::string>& bank) {
    std::unordered_set<std::string> bankSet(bank.begin(), bank.end());
    std::unordered_set<std::string> visited;
    std::queue<std::string> Q;
    Q.push(start);
    int steps = 0;
    while(!Q.empty()) {
        const int N = Q.size();
        for(int i = 0; i < N; ++i) {
            std::string f = Q.front();
            visited.insert(f);
            Q.pop();
            
            if(f == end) {
                return steps;
            }
            
            std::vector<std::string> mutation = getNextMutation(f, bankSet, visited);
            for(int m = 0; m < mutation.size(); ++m) {
                Q.push(mutation[m]);
            }
        }
        ++steps;
    }
    return -1;
}