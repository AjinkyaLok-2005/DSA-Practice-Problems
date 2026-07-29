#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkCycleDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, unordered_map<int, list<int>>& adj)
    {
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neighbour : adj[node])
        {
            if(!visited[neighbour])
            {
                bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
                if(cycleDetected)
                    return true;
            }
            else if(dfsVisited[neighbour])
            {
                return true;
            }
        }

        dfsVisited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;

        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i])
            {
                bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
                if(cycleFound)
                    return false;   // cycle found -> can't finish
            }
        }

        return true;   // no cycle anywhere -> can finish
    }
};

int main()
{
    Solution sol;

    // Example 1: numCourses = 2, prerequisites = [[1,0]] -> expected true
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Example 1 (expected true): " 
         << (sol.canFinish(numCourses1, prerequisites1) ? "true" : "false") 
         << endl;

    // Example 2: numCourses = 2, prerequisites = [[1,0],[0,1]] -> expected false
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Example 2 (expected false): " 
         << (sol.canFinish(numCourses2, prerequisites2) ? "true" : "false") 
         << endl;

    // Extra test: no prerequisites at all -> expected true
    int numCourses3 = 3;
    vector<vector<int>> prerequisites3 = {};
    cout << "Example 3 (expected true): " 
         << (sol.canFinish(numCourses3, prerequisites3) ? "true" : "false") 
         << endl;

    return 0;
}