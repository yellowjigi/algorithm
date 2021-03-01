//
//  2021-03-01
//  LeetCode
//  1249. Minimum Remove to Make Valid Parentheses
//  Accepted

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stack;
        int i;
        
        for (i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stack.push(i);
            }
            else if (s[i] == ')') {
                if (!stack.empty() && s[stack.top()] == '(') {
                    stack.pop();
                }
                else {
                    stack.push(i);
                }
            }
        }

        while (!stack.empty()) {
            s.erase(stack.top(), 1);
            stack.pop();
        }

        return s;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    string str("lee(t(c)o)de)");
#elif (EXAMPLE == 2)
    string str("a)b(c)d");
#elif (EXAMPLE == 3)
    string str("))((");
#elif (EXAMPLE == 4)
    string str("(a(b(c)d)");
#endif

    cout << "Output: " << "\"" << s.minRemoveToMakeValid(str) << "\"" << endl;

    return 0;
}