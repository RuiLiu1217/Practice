#include "headers.hpp"
#include <set>
int LeetCode::_0771_JewelsAndStones::numJewelsInStones(std::string J, std::string S) {
    std::set<char> Js;
    for(auto a : J) {
        Js.insert(a);
    }
    int jnum = 0;
    for(auto b : S) {
        if(Js.find(b) != Js.end()) {
            jnum++;
        }
    }
    return jnum;
}