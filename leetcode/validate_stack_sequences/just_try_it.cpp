//
//  2021-03-08
//  LeetCode
//  946. Validate Stack Sequences
//  Accepted

#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i, j;
        stack<int> stack;

        for (i = 0, j = 0; i < popped.size(); ++i) {
            stack.push(pushed[i]);
            while (!stack.empty() && stack.top() == popped[j]) {
                stack.pop();
                ++j;
            }
        }

        return stack.empty() ? true : false;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    vector<int> pushed{ 1, 2, 3, 4, 5 };
    vector<int> popped{ 4, 5, 3, 2, 1 };
#elif (EXAMPLE == 2)
    vector<int> pushed{ 1, 2, 3, 4, 5 };
    vector<int> popped{ 4, 3, 5, 1, 2 };
#endif

    cout << "Output: ";
    s.validateStackSequences(pushed, popped) ? cout << "true" : cout << "false";
    cout << endl;

    return 0;
}