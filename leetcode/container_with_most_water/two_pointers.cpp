//
//  2021-03-01
//  LeetCode
//  11. Container With Most Water
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left, right, area, max_area;

        left = 0;
        right = height.size() - 1;
        max_area = 0;
        while (left != right) {
            area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, area);

            height[left] < height[right] ? ++left : --right;
        }

        return max_area;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    vector<int> height{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
#elif (EXAMPLE == 2)
    vector<int> height{ 1, 1 };
#elif (EXAMPLE == 3)
    vector<int> height{ 4, 3, 2, 1, 4 };
#elif (EXAMPLE == 4)
    vector<int> height{ 1, 2, 1 };
#endif

    cout << "Output: " << s.maxArea(height) << endl;

    return 0;
}
