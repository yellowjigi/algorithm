//
//  2021-03-01
//  LeetCode
//  784. Letter Case Permutation
//  

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<string> result;

    void perm(string& S, string s, int pos) {
        int i;
        char c;

        for (i = pos; i < S.length(); ++i) {
            if (S[i] >= '0' && S[i] <= '9') {
                s.push_back(S[i]);
            }
            else {
                break;
            }
        }

        if (s.length() == S.length()) {
            this->result.push_back(s);
            return;
        }

        c = (S[i] >= 'A' && S[i] <= 'Z') ? S[i] : S[i] - 32;
        s.push_back(c);
        perm(S, s, i + 1);
        s[i] = c + 32;
        perm(S, s, i + 1);
    }

public:
    vector<string> letterCasePermutation(string S) {
        string s;
        perm(S, s, 0);
        return this->result;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    vector<string> result;
    int i;

#if (EXAMPLE == 1)
    string S("a1b2");
#elif (EXAMPLE == 2)
    string S("3z4");
#elif (EXAMPLE == 3)
    string S("12345");
#elif (EXAMPLE == 4)
    string S("0");
#endif

    result = s.letterCasePermutation(S);

    cout << "Output: [";
    for (i = 0; i < result.size() - 1; ++i) {
        cout << "\"" << result[i] << "\"" << ",";
    }
    cout << "\"" << result[i] << "\"" << "]" << endl;

    return 0;
}