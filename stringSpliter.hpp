#ifndef STRINGSPLITTER_HPP
#define STRINGSPLITTER_HPP

#include <regex>
#include <string>
#include <vector>
#include <sstream>
namespace StringMethods {
std::vector<std::string> token(std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string tok;
    std::istringstream tokenStream(s);
    while(std::getline(tokenStream, tok, delimiter)) {
        tokens.push_back(tok);
    }
    return tokens;
}
}

#endif