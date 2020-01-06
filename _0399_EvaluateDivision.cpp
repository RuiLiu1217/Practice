#include "headers.hpp"

void LeetCode::_0399_EvaluateDivision::resetVisit() {
    for(auto& n : node) {
        visited[n] = false;
    }
}
std::vector<std::string> LeetCode::_0399_EvaluateDivision::getAdj(std::string a) {
    if(adjMap.find(a) == adjMap.end()) {
        return {};
    }
    return adjMap[a];
}
    

std::vector<double> LeetCode::_0399_EvaluateDivision::calcEquation(
    std::vector<std::vector<std::string>>& equations, 
    std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
    for(int i = 0; i < equations.size(); ++i) {
        node.insert(equations[i][0]);
        node.insert(equations[i][1]);
        edge[{equations[i][0], equations[i][1]}] = values[i];
        edge[{equations[i][1], equations[i][0]}] = 1.0 / values[i];
        adjMap[equations[i][0]].push_back(equations[i][1]);
        adjMap[equations[i][1]].push_back(equations[i][0]);
    }
    resetVisit();
    std::vector<double> res;
    for(int i = 0; i < queries.size(); ++i) {
        res.push_back(calculate(queries[i][0], queries[i][1]));
        resetVisit();
    }
    return res;
}

double LeetCode::_0399_EvaluateDivision::calculate(std::string a, std::string b) {    
    if(node.find(a) == node.end() || node.find(b) == node.end()) {
        return -1.0;
    }
    
    if(a == b) {
        return 1.0;
    }
    
    std::vector<std::string> adjA = getAdj(a);
    visited[a] = true;
    for(int i = 0; i < adjA.size(); ++i) {
        if(visited[adjA[i]] == false) {
            double v = calculate(adjA[i], b);
            if(v != -1.0) {
                return v * edge[std::make_pair(a, adjA[i])];
            }
        }
    }
    return -1.0;
}