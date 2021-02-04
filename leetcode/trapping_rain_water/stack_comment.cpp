//
//  2020-02-03
//  LeetCode
//  42. Trapping Rain Water
//  Accepted; commented ver.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    // Item to store on a stack
    struct S {
        int diff;
        int index;
    };

public:
    int trap(vector<int>& height) {
        int len = height.size();
        int i;          // iterator
        int diff;       // current "valid" height after consumed
        S s;            // item
        stack<S> st;    // stack
        int water = 0;  // answer

        // We will inspect moving from left to right
        for (i = 1; i < len; i++) {
            // There are 3 cases;
            // previous_height > current_height, equal, or <
            if (height[i - 1] > height[i]) {
                // The previous height is higher than the current one.
                // We need to remember associated height and index
                // so that later we can calculate the water trapped.
                // Push to the stack.
                s.diff = height[i - 1] - height[i];
                s.index = i;
                st.push(s);
            }
	    else if (height[i - 1] == height[i]) {
                // Nothing to do.
                // TODO: further explanation
                continue;
            }
	    else { // height[i - 1] < height[i]
                // We can calculate water trapped so far.
                diff = height[i] - height[i - 1];

                // If the stack is empty, it's either 1) because the heights
                // have been only inclining so far, or 2) because all the diffs
                // of the items that have been stored on the stack have been consumed
                // by the current diff which is still larger than or equal to the last one of them.
                // For 1), no water has been trapped so far;
                // for 2), No more water can be trapped to the left of the current index.
                while (!st.empty()) {
                    s = st.top();
                    st.pop();

                    if (diff < s.diff) {
                        // * Again, this case is that 1) the stack is not empty and
                        // 2) the height has just been increased.
                        // It is definitely possible to trap water, but only to the
                        // limited amount such that the current diff can cover.
                        water += diff * (i - s.index);

                        // Also, we push the item back to the stack after we consume
                        // the corresponding amount from its diff,
                        // as it still has the remaining diff left to be consumed later.
                        s.diff -= diff;
                        st.push(s);

                        // The current diff has been consumed completely. Break.
                        break;
                    }
		    else if (diff == s.diff) {
                        // Same as above (*)
                        water += diff * (i - s.index);

                        // In this case, we do not push the item back to the stack
                        // because the diff of the item has been consumed completely.

                        // The current diff has been consumed completely. Break.
                        break;
                    }
		    else { // diff > s.diff
                        // Same as above (*) except that we now calculate the amount
                        // of the water with the diff of the item popped from the stack,
                        // not with the current diff; also, we update the current diff
                        // as s.diff amount of it has been consumed.
                        water += s.diff * (i - s.index);
                        diff -= s.diff;

                        // So in this case, as the current diff still remains,
                        // the next item will be popped from the stack (unless empty)
                        // and another layer of water to be trapped can be calculated
                        // in the next loop.
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

    // LeetCode test cases from the problem
    int c[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    //int c[] = { 4, 2, 0, 3, 2, 5 };

    vector<int> height(c, c + (sizeof c / sizeof c[0]));

    water = s.trap(height);

    cout << water << endl;

    return 0;
}
