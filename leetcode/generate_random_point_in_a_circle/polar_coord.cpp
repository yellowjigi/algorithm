//
//  2021-03-18
//  LeetCode
//  478. Generate Random Point in a Circle
//  Accepted

#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    double radius;
    double x_center;
    double y_center;
    
public:
    Solution(double radius, double x_center, double y_center): radius(radius), x_center(x_center), y_center(y_center) {

    }
    
    vector<double> randPoint() {
        double distance, theta;
        vector<double> point;
        
        distance = sqrt((double)rand() / RAND_MAX) * radius;
        theta = ((double)rand() / RAND_MAX) * 2 * M_PI;
        
        point.push_back(x_center + (distance * cos(theta)));
        point.push_back(y_center + (distance * sin(theta)));
        
        return point;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

#define EXAMPLE 1

int main() {
    vector<double> point;
    int i;
    
#if (EXAMPLE == 1)
    Solution s(1, 0, 0);
#elif (EXAMPLE == 2)
    Solution s(10, 5, -7.5);
#endif

    for (i = 0; i < 3; ++i) {
        point = s.randPoint();
        cout << "[" << point[0] << "," << point[1] << "]";
        if (i != 2) {
            cout << ",";
        }
    }
    
    return 0;
}
