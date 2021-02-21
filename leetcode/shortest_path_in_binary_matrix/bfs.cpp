//
//  2021-02-21
//  LeetCode
//  1091. Shortest Path in Binary Matrix
//  Accepted

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int curr_pass_size;
        int i, row, col;
        int depth = 0;

        q.push(pair<int, int>(-1, -1));

        while (!q.empty()) {
            ++depth;
            curr_pass_size = q.size();

            for (i = 0; i < curr_pass_size; ++i) {
                for (row = q.front().first - 1; row <= q.front().first + 1; ++row) {
                    for (col = q.front().second - 1; col <= q.front().second + 1; ++col) {
                        if (row >= 0 && row <= n - 1 && col >= 0 && col <= n - 1 && grid[row][col] == 0) {
                            if (row == n - 1 && col == n - 1) {
                                return depth;
                            }
                            q.push(pair<int, int>(row, col));
                            grid[row][col] = -1;
                        }
                    }
                }

                q.pop();
            }
        }

        return -1;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    int i, j;

#if (EXAMPLE == 1)
    vector<vector<int>> grid{
        { 0, 1 },
        { 1, 0 }
    };
#elif (EXAMPLE == 2)
    vector<vector<int>> grid{
        { 0, 0, 0 },
        { 1, 1, 0 },
        { 1, 1, 0 }
    };
#elif (EXAMPLE == 3)
    vector<vector<int>> grid{
        { 1, 0, 0 },
        { 1, 1, 0 },
        { 1, 1, 0 }
    };
#elif (EXAMPLE == 4)
    vector<vector<int>> grid{
        { 0 }
    };
#endif

    cout << "Input: [";
    for (i = 0; i < grid.size(); ++i) {
        cout << "[";
        for (j = 0; j < grid.size(); ++j) {
            cout << grid[i][j];
            if (j < grid.size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < grid.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    cout << "Output: " << s.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}
