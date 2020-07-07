#include "headers.hpp"
#include <unordered_map>
#include <algorithm>

// Faceboook

std::string LeetCode::_0767_ReorganizeString::reorganizeString(std::string S) {
    std::unordered_map<char, int> map;
    for(char& c : S){
        ++map[c];
    }
    for(auto m : map) {
        if(m.second * 2 > S.size() + 1) {
            return "";
        }
    }
    std::vector<std::pair<char, int>> sortedChar(map.begin(), map.end());
    std::sort(begin(sortedChar), end(sortedChar), [](std::pair<char, int> a,
                                                    std::pair<char, int> b){
        return a.second > b.second; 
    });
    std::string sample;
    for(auto s : sortedChar) {
        sample += std::string(s.second, s.first);
    }
    const int N = S.size();
    std::string res;
    for(int i = 0, j = (N - 1) / 2 + 1; i <= (N - 1) / 2; ++i, ++j) {
        res += sample[i];
        if(j < N) {
            res += sample[j];
        }
    }
    
    return res;        
}