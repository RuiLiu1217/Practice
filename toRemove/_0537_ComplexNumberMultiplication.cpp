#include "headers.hpp"
#include <sstream>
// The useage of stringstream

std::string LeetCode::_0537_ComplexNumberMultiplication::complexNumberMultiply(std::string a, std::string b) {     
    int ra, ia, rb, ib;
    char buff;
    std::stringstream aa(a), bb(b), ans;
    aa >> ra >> buff >> ia >> buff;
    bb >> rb >> buff >> ib >> buff;
    ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
    return ans.str();
    
}