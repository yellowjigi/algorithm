//
//  2021-03-19
//  LeetCode
//  841. Keys and Rooms
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void dfs(vector<vector<int>>& adjMatrix, int i, vector<bool>& visited) {
        int j;
        
        if (visited[i] == true) {
            return;
        }
        
        visited[i] = true;
        
        for (j = 0; j < adjMatrix[i].size(); ++j) {
            dfs(adjMatrix, adjMatrix[i][j], visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        int i;
        
        dfs(rooms, 0, visited);
        
        for (i = 0; i < rooms.size(); ++i) {
            if (visited[i] == false) {
                return false;
            }
        }
        
        return true;
    }
};

#define EXAMPLE 1

int main() {
    Solution s;
    
#if (EXAMPLE == 1)
    vector<vector<int>> rooms{
        { 1 },
        { 2 },
        { 3 },
        {   }
    };
#elif (EXAMPLE == 2)
    vector<vector<int>> rooms{
        { 1, 3 },
        { 3, 0, 1 },
        { 2 },
        { 0 }
    };
#endif

    cout << "Output: ";
    s.canVisitAllRooms(rooms) ? cout << "true" : cout << "false";
    cout << endl;
    
    return 0;
}
