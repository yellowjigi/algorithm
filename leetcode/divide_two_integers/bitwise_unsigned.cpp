//
//  2021-03-08
//  LeetCode
//  29. Divide Two Integers
//  Accepted

#include <iostream>
#include <limits>

using namespace std;

class Solution {
    int unsignedBitLength(unsigned int number) {
        int length;
        
        length = 0;
        while (number != 0) {
            ++length;
            number >>= 1;
        }

        return length;
    }

public:
    int divide(int dividend, int divisor) {
        bool minus;
        unsigned int unsigned_dividend, unsigned_divisor, d, quotient;
        int offset;

        minus = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? true : false;

        unsigned_dividend = abs(dividend);
        unsigned_divisor = abs(divisor);
        
        if ((dividend == 0) || (unsigned_dividend < unsigned_divisor)) {
            return 0;
        }

        offset = unsignedBitLength(unsigned_dividend) - unsignedBitLength(unsigned_divisor);
        quotient = 0;
        while (offset >= 0) {
            d = unsigned_divisor << offset;
            if (unsigned_dividend >= d) {
                unsigned_dividend -= d;
                quotient += 1 << offset;
            }
            --offset;
        }
        
        if (minus == false && quotient > numeric_limits<int>::max()) {
            return numeric_limits<int>::max();
        }

        return minus ? ~quotient + 1 : quotient;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    int dividend = 10, divisor = 3;
#elif (EXAMPLE == 2)
    int dividend = 7, divisor = -3;
#elif (EXAMPLE == 3)
    int dividend = 0, divisor = 1;
#elif (EXAMPLE == 4)
    int dividend = 1, divisor = 1;
#endif

    cout << "Output: " << s.divide(dividend, divisor) << endl;

    return 0;
}
