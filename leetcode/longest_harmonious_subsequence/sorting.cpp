//
//  2021-02-07
//  LeetCode
//  594. Longest Harmonious Subsequence
//  Accepted (Runtime 99%, Memory Usage 96%)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int i, prev_len, len, max_len;

        sort(nums.begin(), nums.end());
        
        prev_len = 0;
        len = 1;
        max_len = 0;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                len++;
                continue;
            }

            if (prev_len && prev_len + len > max_len) {
                max_len = prev_len + len;
            }

            prev_len = nums[i] == nums[i - 1] + 1 ? len : 0;
            len = 1;
        }

        if (prev_len && prev_len + len > max_len) {
            max_len = prev_len + len;
        }

        return max_len;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    int i;

#if (EXAMPLE == 1)
    vector<int> nums{ 1,3,2,2,5,2,3,7 };
#elif (EXAMPLE == 2)
    vector<int> nums{ 1,2,3,4 };
#elif (EXAMPLE == 3)
    vector<int> nums{ 1,1,1,1 };
#endif

    cout << "Input: nums = [";
    for (i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] << ",";
    }
    cout << nums[i] << "]" << endl;

    cout << "Output: " << s.findLHS(nums) << endl;

    return 0;
}