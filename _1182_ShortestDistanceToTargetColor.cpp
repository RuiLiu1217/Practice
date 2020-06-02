#include "headers.hpp"



std::vector<int> LeetCode::_1182_ShortestDistanceToTargetColor::shortestDistanceColor(std::vector<int>& colors, std::vector<std::vector<int>>& queries) {
    std::vector<std::vector<int>> distance(3, std::vector<int>(colors.size(), INT_MAX));
    distance[0] = calDistance(colors, 1);
    distance[1] = calDistance(colors, 2);
    distance[2] = calDistance(colors, 3);
    
    std::vector<int> res;
    for(auto& query : queries) {
        res.push_back(distance[query[1] - 1][query[0]]);
    }
    for(int i = 0; i < res.size(); ++i) {
        if(res[i] == INT_MAX) {
            res[i] = -1;
        }
    }
    return res;
}

std::vector<int> LeetCode::_1182_ShortestDistanceToTargetColor::calDistance(std::vector<int>& colors, int targetColor) {
        std::vector<int> left(colors.size(), INT_MAX);
        for(int i = 0; i < colors.size(); ++i) {
            if(colors[i] == targetColor) {
                left[i] = 0;
            } else {
                if(i != 0 && left[i-1] != INT_MAX) {
                    left[i] = left[i-1] + 1;
                }
            }
        }
        
        std::vector<int> right(colors.size(), INT_MAX);
        for(int i = colors.size() - 1; i >= 0; --i) {
            if(colors[i] == targetColor) {
                right[i] = 0;
            } else {
                if(i != colors.size() - 1 && right[i+1] != INT_MAX) {
                    right[i] = right[i+1] + 1;
                }
            }
        }
        std::vector<int> res(colors.size(), INT_MAX);
        for(int i = 0; i < colors.size(); ++i) {
            res[i] = std::min(left[i], right[i]);
        }
        return res;
    }