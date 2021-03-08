//
//  2021-03-08
//  LeetCode
//  29. Divide Two Integers
//  Accepted; commented ver.

#include <iostream>
#include <limits>

using namespace std;

class Solution {
    // Utility function to retrieve the number of bits
    // in the binary representation of a given unsigned integer
    int unsignedBitLength(unsigned int number) {
        int length; // return value
        
        // Calculate the number of bits using shift.
        // Increment `length` and shift `number`
        // to the right until it becomes `0`.
        length = 0;
        while (number != 0) {
            ++length;
            number >>= 1;
        }

        return length;
    }

public:
    int divide(int dividend, int divisor) {
        bool minus; // indicates if the result is minus or not
        unsigned int unsigned_dividend, unsigned_divisor; // unsigned versions
        unsigned int d; // temporary variable holding `unsigned_divisor << offset`
        unsigned int quotient;  // value we should calculate
        int offset; // amount to shift the divisor to the left in each step

        // If one of `dividend` and `divisor` is negative,
        // the result will also be negative; otherwise, positive.
        // Save it to `minus` and use this information later.
        minus = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? true : false;

        // Convert the values to unsigned integers using the `abs` function.
        // We will adjust the sign later using `minus`.
        unsigned_dividend = abs(dividend);
        unsigned_divisor = abs(divisor);
        
        // Check immediate return conditions:
        // 1) if `dividend` is 0; or
        // 2) if the unsigned version of the dividend is less than that of the divisor.
        if ((dividend == 0) || (unsigned_dividend < unsigned_divisor)) {
            return 0;
        }

        // First calculate the initial value of `offset` which indicates
        // how many bits to shift the divisor to the left in each step.
        offset = unsignedBitLength(unsigned_dividend) - unsignedBitLength(unsigned_divisor);
        
        // Initialize `quotient` to 0.
        quotient = 0;
        
        while (offset >= 0) {
            // Align the divisor to the proper position of the dividend
            // using the `offset` value to proceed with the division.
            // E.g., we need to shift `10` 4 bits to the left to compare
            // with the corresponding bits of the dividend in the following case:
            //    __1____   dividend: 0b101010
            //  10)101010   divisor: 0b10
            //     10       offset: 4
            d = unsigned_divisor << offset;
            
            // Now we can compare the two values.
            if (unsigned_dividend >= d) {
                // If and only if the dividend portion is not less than `d`,
                // `quotient` can get `1` added to its corresponding bit position.
                unsigned_dividend -= d;
                quotient += 1 << offset;
            }
            
            // To check the next bit position of `quotient`
            --offset;
        }

        // Cope with the overflow issue.
        // The biggest value (unsigned int) `quotient` can have is 2^31.
        // It matters only if the final value of `quotient` is positive
        // (which means `minus` is `false`).
        // In this case return 2^31 - 1 instead of 2^31.
        if (minus == false && quotient > numeric_limits<int>::max()) {
            return numeric_limits<int>::max();
        }

        // If we are here, it means that there is no overflow.
        // Return according to what `minus` indicates.
        // (`~quotient + 1` will get the two's complement of `quotient`.)
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
