//
//  2021-03-06
//  LeetCode
//  991. Broken Calculator
//  Accepted

#include <iostream>

using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int min_ops = 0;

        while (Y > X) {
            Y = (Y % 2 == 0) ? (Y >> 1) : (Y + 1);
            min_ops += 1;
        }
        min_ops += X - Y;

        return min_ops;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    const int X = 2, Y = 3;
#elif (EXAMPLE == 2)
    const int X = 5, Y = 8;
#elif (EXAMPLE == 3)
    const int X = 3, Y = 10;
#elif (EXAMPLE == 4)
    const int X = 1024, Y = 1;
#endif

    cout << "Output: " << s.brokenCalc(X, Y) << endl;

    return 0;
}