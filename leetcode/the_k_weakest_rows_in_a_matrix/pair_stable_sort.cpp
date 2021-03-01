//
//  2021-03-01
//  LeetCode
//  1337. The K Weakest Rows in a Matrix
//  Accepted

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    static bool comp(const pair<int, int>& i, const pair<int, int>& j) {
        return i.second < j.second;
    }

public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> strength(mat.size());
        vector<int> result(k);
        vector<int>::iterator it;
        int i;

        for (i = 0; i < mat.size(); ++i) {
            it = find(mat[i].begin(), mat[i].end(), 0); 
            strength[i].first = i;
            strength[i].second = distance(mat[i].begin(), it);
        }

        stable_sort(strength.begin(), strength.end(), comp);

        for (i = 0; i < k; ++i) {
            result[i] = strength[i].first;
        }

        return result;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    int i;
    vector<int> krows;

#if (EXAMPLE == 1)
    vector<vector<int>> mat{
        { 1, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 1 }
    };
    const int k = 3;
#elif (EXAMPLE == 2)
    vector<vector<int>> mat{
        { 1, 0, 0, 0 },
        { 1, 1, 1, 1 },
        { 1, 0, 0, 0 },
        { 1, 0, 0, 0 }
    };
    const int k = 2;
#endif

    krows = s.kWeakestRows(mat, k);

    cout << "Output: [";
    for (i = 0; i < krows.size() - 1; ++i) {
        cout << krows[i] << ",";
    }
    cout << krows[i] << "]" << endl;

    return 0;
}