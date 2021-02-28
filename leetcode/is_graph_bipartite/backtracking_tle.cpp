//
//  2021-02-28
//  LeetCode
//  785. Is Graph Bipartite?
//  Time Limit Exceeded (TLE)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> color;
    int num_colors;
    bool result;

    bool isSafe(vector<int>& neighbors, const int target_color) {
        int i;

        for (i = 0; i < neighbors.size(); ++i) {
            if (this->color[neighbors[i]] == target_color) {
                return false;
            }
        }

        return true;
    }

    void backtracking(vector<vector<int>>& graph, const int v) {
        int c;

        for (c = 1; c <= this->num_colors; ++c) {
            if (isSafe(graph[v], c)) {
                this->color[v] = c;
                if (v == graph.size() - 1) {
                    this->result = true;
                    return;
                }
                backtracking(graph, v + 1);
                if (this->result) {
                    return;
                }
            }
        }

        this->color[v] = 0;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        this->color = vector<int>(graph.size(), 0);
        this->num_colors = 2;
        this->result = false;

        backtracking(graph, 0);

        return this->result;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    int i, j;

#if (EXAMPLE == 1)
    vector<vector<int>> graph = {
        { 1, 2, 3 },
        { 0, 2 },
        { 0, 1, 3 },
        { 0, 2 }
    };
#elif (EXAMPLE == 2)
    vector<vector<int>> graph = {
        { 1, 3 },
        { 0, 2 },
        { 1, 3 },
        { 0, 2 }
    };
#endif

    cout << "Input: [";
    for (i = 0; i < graph.size(); ++i) {
        cout << "[";
        for (j = 0; j < graph[i].size(); ++j) {
            cout << graph[i][j];
            if (j < graph[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < graph.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    cout << "Output: ";
    if (s.isBipartite(graph)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    cout << endl;

    return 0;
}
