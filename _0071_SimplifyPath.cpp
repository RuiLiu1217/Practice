#include "headers.hpp"
#include <sstream>

// Facebook

std::string LeetCode::_0071_SimplifyPath::simplifyPath(std::string path) {
    std::string t;
    std::stringstream ss(path);
    std::vector<std::string> v;
    while(std::getline(ss, t, '/')) {
        if(t == "" || t == ".") {
            continue;
        }
        if(t == ".." && !v.empty()) {
            v.pop_back();
        } else if(t != "..") {
            v.push_back(t);
        }
    }

    std::string res;
    for(std::string s : v) {
        res += "/" + s;
    }
    return res.empty()?"/" : res;
}