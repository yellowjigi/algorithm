//
//  2021-03-01
//  LeetCode
//  13. Roman to Integer
//  Accepted; commented ver.

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int i;          // iterator
        int result;     // resultant integer
        int prev_val;   // previous arabic
        int val;        // current arabic
        unordered_map<char, int> m{ // mapping the romans to arabics
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };

        result = m[s[0]];   // Add the first value (s.length is at least 1 by the constraints)
        for (i = 1; i < s.length(); ++i) {
            prev_val = m[s[i - 1]]; // for readability
            val = m[s[i]];          // for readability
            
            result += val; // Let's just add whatever for now, and then see...
            if (val == prev_val * 5 || val == prev_val * 10) { // the 6 instances for subtraction
                // Oops, we should have subtracted the previous value
                // from the current value and then added it to the result.
                // But we have already added both of the previous and current values.
                // So we need to subtract the previous value twice.
                result -= prev_val * 2;
            }
        }

        return result;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    string str("III");
#elif (EXAMPLE == 2)
    string str("IV");
#elif (EXAMPLE == 3)
    string str("IX");
#elif (EXAMPLE == 4)
    string str("LVIII");
#elif (EXAMPLE == 5)
    string str("MCMXCIV");
#endif

    cout << "Output: " << s.romanToInt(str) << endl;

    return 0;
}
