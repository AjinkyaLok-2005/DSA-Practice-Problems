#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int, vector<pair<int, int>>> adj;

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int w = abs(x2-x1) + abs(y2-y1);

                adj[i].push_back(make_pair(j, w));
                adj[j].push_back(make_pair(i, w));
            }
        }

        vector<int> key(n, INT_MAX);
        vector<bool> mst(n, false);
        vector<int> parent(n, -1);

        key[0] = 0;

        for(int i = 0; i < n; i++)
        {
            int mini = INT_MAX;
            int u;

            for(int v = 0; v < n; v++)
            {
                if(mst[v] == false && key[v] < mini)
                {
                    u = v;
                    mini = key[v];
                }
            }

            mst[u] = true;

            for(auto neighbour : adj[u])
            {
                int v = neighbour.first;
                int w = neighbour.second;
                if(mst[v] == false && w < key[v])
                {
                    parent[v] = u;
                    key[v] = w;
                }
            }

        }

        int totalCost = 0;
        for(int i = 0; i < n; i++)
        {
            totalCost += key[i];
        }

        return totalCost;
    }
};

int main()
{
    Solution sol;

    // Example 1: expected output 20
    vector<vector<int>> points1 = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << "Test 1: " << sol.minCostConnectPoints(points1) << " (expected 20)" << endl;

    // Example 2: expected output 18
    vector<vector<int>> points2 = {{3,12},{-2,5},{-4,1}};
    cout << "Test 2: " << sol.minCostConnectPoints(points2) << " (expected 18)" << endl;

    // Edge case: single point, expected output 0
    vector<vector<int>> points3 = {{0,0}};
    cout << "Test 3: " << sol.minCostConnectPoints(points3) << " (expected 0)" << endl;

    return 0;
}