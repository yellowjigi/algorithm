//
//  2021-03-06
//  LeetCode
//  991. Broken Calculator
//  Accepted; commented ver.

#include <iostream>

using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int min_ops = 0;    // minimum number of operations

        // Backward tracing strategy
        //   - We start from Y, following the shortest possible route to meet X.
        //   - Update Y: if it is even, divide it by 2; otherwise, add 1 to it.
        //   - Update min_ops also by each step.
        //   - Repeat it until Y becomes less than or equal to X.
        while (Y > X) {
            Y = (Y % 2 == 0) ? (Y >> 1) : (Y + 1);
            min_ops += 1;
        }
        
        // Now Y is less than or equal to X.
        // The only choice from X's perspective for now is decrement.
        // The number of decrement will be calculated and added to min_ops.
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
