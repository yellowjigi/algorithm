//
//  2021-03-01
//  LeetCode
//  413. Arithmetic Slices
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int i, diff, count, result;

        if (nums.size() < 3) {
            return 0;
        }

        count = 2;
        result = 0;
        diff = nums[1] - nums[0];
        for (i = 2; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == diff) {
                ++count;
            }
            else {
                result += (count - 1) * (count - 2) / 2;
                count = 2;
            }
            diff = nums[i] - nums[i - 1];
        }

        if (count >= 3) {
            result += (count - 1) * (count - 2) / 2;
        }

        return result;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    vector<int> nums{ 1, 2, 3, 4 };
#elif (EXAMPLE == 2)
    vector<int> nums{ 1 };
#endif

    cout << "Output: " << s.numberOfArithmeticSlices(nums) << endl;

    return 0;
}
