#include "headers.hpp"
#include <cmath>
static std::vector<int> operator-(std::vector<int>& a, std::vector<int>& b) {
    return {a[0] - b[0], a[1] - b[1]};
}

static std::vector<int> operator+(std::vector<int>& a, std::vector<int>& b) {
    return {a[0] + b[0], a[1] + b[1]};
}

static double lenSquare(std::vector<int>& a) {
    return double(a[0]) * double(a[0]) + double(a[1]) * double(a[1]);
}

static double operator*(std::vector<int>& a, std::vector<int>& b) {
    return double(a[0]) * double(b[0]) + double(a[1]) * double(b[1]);
}

class myhash {
  public:
    size_t operator()(const std::vector<int>& a) const {
        size_t h1 = std::hash<int>()(a[0]);
        size_t h2 = std::hash<int>()(a[1]);
        return h1^h2;
    }
};


double LeetCode::_0963_MinimumAreaRectangleII::minAreaFreeRect(std::vector<std::vector<int>>& points) {
    std::unordered_set<std::vector<int>, myhash> pset;
    for(auto& v : points) {
        pset.insert(v);
    }
    double rectArea = INT_MAX;

    for(int i = 0; i < points.size(); ++i) {
        for(int j = 0; j < points.size(); ++j) {
            if(j != i) {
                std::vector<int> v1 = points[j] - points[i];
                double l1 = std::sqrt(lenSquare(v1));
                for(int k = 0; k < points.size(); ++k) {
                    if(i != k && j != k) {
                        std::vector<int> v2 = points[k] - points[i];
                        if(std::abs(v1 * v2) < 1.0e-6) {
                            std::vector<int> v4 = points[j] + v2;
                            if(pset.find(v4) != pset.end()) {
                                double l2 = std::sqrt(lenSquare(v2));
                                rectArea = std::min(rectArea, l1 * l2);
                            }
                        }
                    }
                }
            }
        }
    }
    return rectArea == INT_MAX ? 0 : rectArea;
}