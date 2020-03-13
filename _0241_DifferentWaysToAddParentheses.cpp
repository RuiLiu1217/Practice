#include "headers.hpp"

 std::vector<int> diffWaysToComp(const std::string& input, int start, int end) {
    if(map.find(input.substr(start, end-start)) != map.end()) {
        return map[input.substr(start, end-start)];
    }
    if(start == end) {
        return {};
    }
    
    std::string su = input.substr(start, end-start);
    if(su.find("+") == std::string::npos && su.find("-") == std::string::npos && su.find("*") == std::string::npos) {
        return map[su] = {std::stoi(su)};
    }
        
    std::vector<int> res;
    for(int i = start; i < end; ++i) {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
            const auto& left = diffWaysToComp(input, start, i);
            const auto& right = diffWaysToComp(input, i+1, end);
            for(auto l : left) {
                for(auto r : right) {
                    if(input[i] == '+') {
                        res.push_back(l + r);
                    }
                    if(input[i] == '-') {
                        res.push_back(l - r);
                    }
                    if(input[i] == '*') {
                        res.push_back(l * r);
                    }
                }
            }
            
        }
    }
    return map[input.substr(start, end-start)] = res;
}

std::vector<int> LeetCode::_0241_DifferentWaysToAddParentheses::diffWaysToCompute(std::string input) {
    return diffWaysToComp(input, 0, input.size());
}