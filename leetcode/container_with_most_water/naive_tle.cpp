//
//  2021-03-01
//  LeetCode
//  11. Container With Most Water
//  Time Limit Exceeded (TLE)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i, j, area, max_area;
        
        max_area = 0;
        for (i = 0; i < height.size() - 1; ++i) {
            for (j = i + 1; j < height.size(); ++j) {
                area = min(height[i], height[j]) * (j - i);
                max_area = max(max_area, area);
            }
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
