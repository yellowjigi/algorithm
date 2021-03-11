//
//  2021-03-11
//  LeetCode
//  12. Integer to Roman
//  Accepted

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int q, r, d, i;
        string roman;
        unordered_map<int, char> um{
            { 1, 'I' },
            { 5, 'V' },
            { 10, 'X' },
            { 50, 'L' },
            { 100, 'C' },
            { 500, 'D' },
            { 1000, 'M' }
        };

        d = 1000;
        while (d != 0) {
            q = num / d;
            r = num % d;
            switch (q) {
            case 0:
                break;
            case 4:
            case 9:
                roman.push_back(um[d]);
                roman.push_back(um[num - r + d]);
                break;
            default:
                if (q >= 5) {
                    roman.push_back(um[d * 5]);
                    q -= 5;
                }
                for (i = 0; i < q; ++i) {
                    roman.push_back(um[d]);
                }
            }
            num = r;
            d /= 10;
        }

        return roman;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    int num = 3;
#elif (EXAMPLE == 2)
    int num = 4;
#elif (EXAMPLE == 3)
    int num = 9;
#elif (EXAMPLE == 4)
    int num = 58;
#elif (EXAMPLE == 5)
    int num = 1994;
#endif

    cout << "Output " << "\"" << s.intToRoman(num) << "\"" << endl;

    return 0;
}
