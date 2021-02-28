//
//  2021-02-28
//  LeetCode
//  785. Is Graph Bipartite?
//  Time Limit Exceeded (TLE); commented ver.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // Declare as member variables to reduce
    // the cost of passing parameters in recursive calls.
    vector<int> color;  // color of each vertex
    int num_colors;     // the number of colors (for this application it will be 2)
    bool result;        // indicator of whether the graph is found bipartite or not

    // Utility function to check if it's safe to color this vertex with target_color
    bool isSafe(vector<int>& neighbors, const int target_color) {
        int i;  // iterator

        for (i = 0; i < neighbors.size(); ++i) {
            if (this->color[neighbors[i]] == target_color) {
                // If at least one adjacent vertex (in the neighbors vector)
                // has already had this target_color, we cannot use this target_color.
                return false;
            }
        }

        // If every neighboring vertex has had a different color,
        // now it is safe to use this target_color.
        return true;
    }

    void backtracking(vector<vector<int>>& graph, const int v) {
        int c;  // iterator of colors

        // Start from 1 since the vector this->color has been
        // initialized with 0's meaning "not yet colored".
        for (c = 1; c <= this->num_colors; ++c) {
            if (isSafe(graph[v], c)) {
                // It is safe to color this vertex v with the color c
                // (i.e., all of its adjacent vertices have
                // had different colors or not yet colored).
                
                // Color this vertex.
                this->color[v] = c;
                
                if (v == graph.size() - 1) {
                    // If this vertex is the last one in the graph,
                    // we set the indicator to true and return
                    // because it means all the precedent vertices
                    // along with this last one have been safely colored.
                    this->result = true;
                    return;
                }
                
                // Recursive call with the next vertex in the graph.
                backtracking(graph, v + 1);
                
                if (this->result) {
                    // If this->result indicates true at this point,
                    // then it means that the graph has been colored successfully,
                    // which means in this application it is bipartite.
                    // We will recursively return.
                    return;
                }
            }
        }

        // We fall here if and only if
        // 1) every color has been tried; but either
        // 2-1) the indicator this->result is still false or
        // 2-2) all/some of the colors have been not safe, so we couldn't move on.
        
        // In this case, we need to reset the color of this vertex
        // so that the vertex of the upper level of the recursive calls
        // can try again with the next color from scratch.
        this->color[v] = 0;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        this->color = vector<int>(graph.size(), 0); // initialized to 0's
        this->num_colors = 2; // 2 colors are required for the bipartite application
        this->result = false; // See explanations above

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
