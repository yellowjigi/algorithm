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
        vector<int> nums_copy(nums);
        int i, j;

        sort(nums_copy.begin(), nums_copy.end());

        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums_copy[i]) {
                break;
            }
        }

        if (i == nums.size()) {
            return 0;
        }

        for (j = nums.size() - 1; j >= 0; --j) {
            if (nums[j] != nums_copy[j]) {
                break;
            }
        }

        return j - i + 1;
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