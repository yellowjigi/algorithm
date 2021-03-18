//
//  2021-03-18
//  LeetCode
//  478. Generate Random Point in a Circle
//  Accepted

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    double radius;
    double x_center;
    double y_center;

    vector<double> randPointInSquare() const {
        vector<double> point;

        point.push_back((x_center - radius) + ((double)rand() / RAND_MAX) * (radius * 2));
        point.push_back((y_center - radius) + ((double)rand() / RAND_MAX) * (radius * 2));

        return point;
    }

    double distanceFromCenter(vector<double> point) const {
        return sqrt(pow(point[0] - x_center, 2) + pow(point[1] - y_center, 2));
    }

public:
    Solution(double radius, double x_center, double y_center) : radius(radius), x_center(x_center), y_center(y_center) {

    }

    vector<double> randPoint() {
        vector<double> point;

        do {
            point = randPointInSquare();
        } while (distanceFromCenter(point) > radius);

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
