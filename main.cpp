#include "ExpressionEvaluation.hpp"
#include <iostream>
#include "stringSpliter.hpp"
#include "basicCalculator.hpp"

int main(int argc, char* argv[]) {
    std::cout<<"Welcome to my simple calculator\n";
    std::cout<<"You have entered " << argc << " arguments\n";
    std::string s;
    if(argc >= 2) {
        for(int i = 1; i < argc; ++i) {
            s += argv[i];
        }
    } else {
        std::cout<<"Example: (1+2)*3/2\n";
        s = "(1+2)*3/2";    
    }
    double result = calculator(s);
    std::cout<< s << " = " << result;
    return 0;
}