//
//  2021-03-01
//  LeetCode
//  13. Roman to Integer
//  Accepted

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int i;
        int result;
        int prev_val;
        int val;
        unordered_map<char, int> m{
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };

        result = m[s[0]];
        for (i = 1; i < s.length(); ++i) {
            prev_val = m[s[i - 1]];
            val = m[s[i]];

            result += val;
            if (val == prev_val * 5 || val == prev_val * 10) {
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
