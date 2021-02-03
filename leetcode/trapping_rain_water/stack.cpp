//
//  2020-02-03
//  LeetCode
//  42. Trapping Rain Water
//  Accepted

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    struct S {
        int diff;
        int index;
    };

public:
    int trap(vector<int>& height) {
        int len = height.size();
        int i;
        int diff;
        S s;
        stack<S> st;
        int water = 0;

        for (i = 1; i < len; i++) {
            if (height[i - 1] > height[i]) {
                s.diff = height[i - 1] - height[i];
                s.index = i;
                st.push(s);
            } else if (height[i - 1] == height[i]) {
                continue;
            } else {
                diff = height[i] - height[i - 1];

                while (!st.empty()) {
                    s = st.top();
                    st.pop();

                    if (diff < s.diff) {
                        water += diff * (i - s.index);
                        s.diff -= diff;
                        st.push(s);
                        break;
                    } else if (diff == s.diff) {
                        water += diff * (i - s.index);
                        break;
                    } else {
                        water += s.diff * (i - s.index);
                        diff -= s.diff;
                    }
                }
            }
        }

        return water;
    }
};

int main(void) {
    Solution s;
    int water;

    int c[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    //int c[] = { 4,2,0,3,2,5 };

    vector<int> height(c, c + (sizeof c / sizeof c[0]));

    water = s.trap(height);

    cout << water << endl;

    return 0;
}
