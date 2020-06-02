#include "headers.hpp"
#include <sstream>

std::string LeetCode::_1451_RearrangeWordsInASentence::arrangeWords(std::string text) {
    std::istringstream iss(text);
    std::string token;
    std::vector<std::pair<std::string, int>> tokens;
    int i = 0;
    while(getline(iss, token, ' ')) {
        token[0] = std::tolower(token[0]);
        tokens.push_back({token, i++});
    }
    std::sort(begin(tokens), end(tokens), [](auto pa, auto pb){
        return pa.first.size() < pb.first.size() || (pa.first.size() == pb.first.size() && pa.second < pb.second);
    });
    
    std::string res;
    for(int i = 0; i < tokens.size(); ++i) {
        if(!res.empty()) {
            res += " ";
        }
        if(i == 0) {
            tokens[i].first[0] = std::toupper(tokens[i].first[0]);
        }
        res += tokens[i].first;
        
    }
    return res;
}
