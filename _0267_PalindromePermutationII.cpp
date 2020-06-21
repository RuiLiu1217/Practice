#include "headers.hpp"

std::vector<std::string> LeetCode::_0267_PalindromePermutationII::generatePalindromes(std::string S) {
    std::unordered_map<char, int> freq;
    for(char s : S) {
        ++freq[s];
    }
    int flag = 0;
    char extra = 0;
    std::string halfS;
    for(auto& c : freq) {
        if(c.second % 2 && flag == 1)  {
            return {};
        } else if(c.second % 2 && flag == 0) {
            flag = 1;
            extra = c.first;
        }
        halfS += std::string(c.second/2, c.first);
    }
    std::sort(begin(halfS), end(halfS));
    std::vector<int> visited(halfS.size(), 0);
    std::string tmp;
    std::vector<std::string> res;
    backtracking(halfS, 0, visited, tmp, res);
    std::vector<std::string> ret;
    for(auto r : res) {
        std::string rr = r;
        std::reverse(begin(rr), end(rr));
        if(extra == 0) {
            ret.push_back(r + rr);
        } else {
            ret.push_back(r + extra + rr);
        }
    }
    return ret;
}

// LeetCode:: 47 How to generate permutation with duplicates. 
void LeetCode::_0267_PalindromePermutationII::backtracking(std::string hs, int level, std::vector<int>& visited, std::string& tmp, std::vector<std::string>& res) {
    if(level >= hs.size()) {
        res.push_back(tmp);
    }
    for(int i = 0; i < hs.size(); ++i) {
        if(visited[i] == 1) {
            continue;
        }
        if(i > 0 && hs[i] == hs[i-1] && visited[i-1] == 0) {
            continue;
        }
        visited[i] = 1;
        tmp += hs[i];
        backtracking(hs, level + 1, visited, tmp, res);
        tmp.pop_back();
        visited[i] = 0;
    }
}
