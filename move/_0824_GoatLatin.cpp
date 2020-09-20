#include "headers.hpp"
#include <iostream>
#include <iterator>
#include <sstream>

// Facebook

std::string LeetCode::_0824_GoatLatin::toGoatLatin(std::string S) {
    std::istringstream iss(S);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                        std::istream_iterator<std::string>());
    int count = 1;
    std::string a = "a";
    std::string res;
    for(int i = 0; i < results.size(); ++i) {
        if(results[i][0] == 'a' || 
            results[i][0] == 'e' || 
            results[i][0] == 'i' || 
            results[i][0] == 'o' || 
            results[i][0] == 'u' || 
            results[i][0] == 'A' || 
            results[i][0] == 'E' || 
            results[i][0] == 'I' || 
            results[i][0] == 'O' || 
            results[i][0] == 'U') {
            results[i] = results[i] + "ma" + a;
            a = a + "a";
            res = res + results[i] + " ";
        } else {
            char F = results[i][0];
            std::string tmp(results[i].begin() + 1, results[i].end());
            tmp = tmp + F + "ma" + a;
            a = a + "a";
            res = res + tmp + " ";
        }
    }
    std::string RES(res.begin(), res.end()-1);
    return RES;
}