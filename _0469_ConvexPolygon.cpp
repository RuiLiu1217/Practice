#include "headers.hpp"

bool LeetCode::_0469_ConvexPolygon::isConvex(std::vector<std::vector<int>>& points) {
    points.push_back(points.front());
    std::vector<std::vector<int>> vectors;
    for(int i = 1; i < points.size(); ++i) {
        vectors.push_back({points[i][0] - points[i-1][0], points[i][1] - points[i-1][1]});
    }
    vectors.push_back(vectors.front());
    std::vector<int> isPositive;
    
    for(int i = 1; i < vectors.size(); ++i) {
        const int v = (vectors[i-1][0] * vectors[i][1] - vectors[i][0] * vectors[i-1][1]);
        if (v > 0) {
            isPositive.push_back(1);
        } else if (v < 0){ 
            isPositive.push_back(-1);
        } else {
            isPositive.push_back(0);
        }
    }

    int ii = 0;
    while(ii < isPositive.size() && isPositive[ii] == 0) {
        ++ii;
    }
    if(ii == isPositive.size()) {
        return false;
    }
    int val = isPositive[ii];
    for(int i = 0; i < isPositive.size(); ++i) {
        if(isPositive[i] != val) {
            if(isPositive[i] == 0) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}