#include "headers.hpp"
#include <math.h>


double LeetCode::_0812_LargestTriangleArea::largestTriangleArea(std::vector<std::vector<int>>& points) {
    double area = 0;
    for(int i = 0; i < points.size(); ++i) {
        const int Ax = points[i][0];
        const int Ay = points[i][1];
        for(int j = i+1; j < points.size(); ++j) {
            const int Bx = points[j][0];
            const int By = points[j][1];
            const int AxBy = Ax * By;
            const int BxAy = Bx * Ay;
            const int Ay_By = Ay - By;
            const int Ax_Bx = Ax - Bx;
            for(int k = j+1; k < points.size(); ++k) {
                const int Cx = points[k][0];
                const int Cy = points[k][1];
                const double t = std::abs(AxBy - BxAy - Ax_Bx * Cy + Cx * Ay_By) * 0.5; // 海伦公式 S=sqrt(p*(p-a)*(p-b)*(p-c))  || p = (a + b + c) / 2
                if(area < t) {
                    area = t;
                }
            }
        }
    }
    return area;
}