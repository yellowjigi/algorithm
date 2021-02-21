//
//  2021-02-21
//  LeetCode
//  1342. Number of Steps to Reduce a Number to Zero
//  Accepted

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;

        while (num) {
            if (num & 1) {
                --num;
            }
            else {
                num >>= 1;
            }
            ++count;
        }

        return count;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    int num = 14;
#elif (EXAMPLE == 2)
    int num = 8;
#elif (EXAMPLE == 3)
    int num = 123;
#endif

    cout << "Input: " << num << endl;
    cout << "Output: " << s.numberOfSteps(num) << endl;

    return 0;
}
