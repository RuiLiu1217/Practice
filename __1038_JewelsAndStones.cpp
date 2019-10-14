#include "headers.hpp"
#include <unordered_set>
int LintCode::_1038_JewelsAndStones::numJewelInStones(std::string& J, std::string& S) {
    std::unordered_set<char> jewels;
    for(int i = 0; i < J.size(); ++i) {
        jewels.insert(J[i]);
    }

    int bt = 0;
    for(int i = 0; i < S.size(); ++i) {
        if(jewels.find(S[i]) != jewels.end()) {
            ++bt;
        }
    }
    return bt;
}
    