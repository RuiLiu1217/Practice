#include "headers.hpp"
#include <stack>
#include <algorithm>

bool LeetCode::_0331_VerifyPreorderSerializationOfABinaryTree::isValidSerialization(std::string preorder) {
    std::stack<std::pair<std::string, int>> Q;
    if(preorder.size() == 1 && preorder[0] == '#') {
        return true;
    }
    preorder += ',';
    std::string curStr;
    
    for(int i =0 ; i < preorder.size(); ++i) {
        char c = preorder[i];
        if(c == ',') {
            if(!curStr.empty()) {
                if(curStr == "#") {
                    if(Q.empty()) {
                        return false;
                    } else {
                        if(Q.top().second == 2) {
                            auto& t = Q.top();
                            t.second = 1;
                        } else {
                            while(!Q.empty() && Q.top().second == 1) {
                                Q.pop();
                            }
                            if(!Q.empty()) {
                                Q.top().second = 1;
                            } else {
                                return i == preorder.size() - 1;
                            }   
                        }
                    }
                } else {
                    Q.push(std::make_pair(curStr, 2));
                }
                curStr.clear();
            } else {
                return false;
            }
        } else {
            curStr += c;
        }
    }
    return Q.empty();
}