//
//  2021-03-06
//  LeetCode
//  240. Search a 2D Matrix II
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i, j;

        i = 0;
        j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] > target) {
                --j;
            }
            else if (matrix[i][j] < target) {
                ++i;
            }
            else {
                return true;
            }
        }

        return false;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;

#if (EXAMPLE == 1)
    vector<vector<int>> matrix{
        { 1, 4, 7, 11, 15 },
        { 2, 5, 8, 12, 19 },
        { 3, 6, 9, 16, 22 },
        { 10, 13, 14, 17, 24 },
        { 18, 21, 23, 26, 30 }
    };
    int target = 5;
#elif (EXAMPLE == 2)
    vector<vector<int>> matrix{
        { 1, 4, 7, 11, 15 },
        { 2, 5, 8, 12, 19 },
        { 3, 6, 9, 16, 22 },
        { 10, 13, 14, 17, 24 },
        { 18, 21, 23, 26, 30 }
    };
    int target = 20;
#endif

    cout << "Output: ";
    s.searchMatrix(matrix, target) ? cout << "true" : cout << "false";
    cout << endl;

    return 0;
}