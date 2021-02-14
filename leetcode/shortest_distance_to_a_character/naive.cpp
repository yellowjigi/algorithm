//
//  2021-02-14
//  LeetCode
//  821. Shortest Distance to a Character
//  Accepted (Runtime 100%)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> distance;
        int i, left, right, d;

        distance.reserve(s.size());
        for (i = 0; i < s.size(); ++i) {
            right = s.find(c, i);
            left = s.rfind(c, i);
            if (right == string::npos) {
                d = i - left;
            }
            else if (left == string::npos) {
                d = right - i;
            }
            else {
                d = min(i - left, right - i);
            }
            distance.push_back(d);
        }

        return distance;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    vector<int> result;
    int i;

#if (EXAMPLE == 1)
    const string str("loveleetcode");
    const char c = 'e';
#elif (EXAMPLE == 2)
    const string str("aaab");
    const char c = 'b';
#endif

    result = s.shortestToChar(str, c);

    cout << "Output: [";
    for (i = 0; i < result.size() - 1; ++i) {
        cout << result[i] << ",";
    }
    cout << result[i] << "]" << endl;

    return 0;
}
