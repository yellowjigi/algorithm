//
//  2021-03-08
//  LeetCode
//  581. Shortest Unsorted Continuous Subarray
//  Accepted

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left, right, min, max, i, j;

        left = 0;
        right = -1;
        max = -100001;
        min = 100001;
        i = 0;
        j = nums.size() - 1;
        while (i < nums.size()) {
            if (nums[i] >= max) {
                max = nums[i];
            }
            else {
                right = i;
            }

            if (nums[j] <= min) {
                min = nums[j];
            }
            else {
                left = j;
            }

            ++i;
            --j;
        }

        return right - left + 1;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    vector<int> nums{ 2, 6, 4, 8, 10, 9, 15 };
#elif (EXAMPLE == 2)
    vector<int> nums{ 1, 2, 3, 4 };
#elif (EXAMPLE == 3)
    vector<int> nums{ 1 };
#endif

    cout << "Output: " << s.findUnsortedSubarray(nums) << endl;

    return 0;
}