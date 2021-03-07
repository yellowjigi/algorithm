//
//  2021-03-08
//  LeetCode
//  856. Score of Parentheses
//  Accepted

#include <iostream>
#include <string>

using namespace std;

class Solution {
    int parenth(string& S, int& i) {
        int sum = 0;

        ++i;
        while (S[i] == '(') {
            sum += parenth(S, i);
            ++i;
        }

        return sum == 0 ? 1 : sum << 1;
    }

public:
    int scoreOfParentheses(string S) {
        int i = 0;
        int sum = 0;

        while (i < S.length()) {
            sum += parenth(S, i);
            ++i;
        }

        return sum;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    string S("()");
#elif (EXAMPLE == 2)
    string S("(())");
#elif (EXAMPLE == 3)
    string S("()()");
#elif (EXAMPLE == 4)
    string S("(()(()))");
#endif

    cout << "Output: " << s.scoreOfParentheses(S) << endl;

    return 0;
}
