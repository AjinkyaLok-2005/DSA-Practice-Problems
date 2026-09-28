#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool DFS(vector<vector<int>>& graph, int curr,
             vector<int>& color, int currColor)
    {
        color[curr] = currColor;

        for(int v : graph[curr])
        {
            // If adjacent node has the same color
            if(color[v] == color[curr])
                return false;

            // If the node is not colored
            if(color[v] == -1)
            {
                int colorOfV = 1 - currColor;

                if(DFS(graph, v, color, colorOfV) == false)
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++)
        {
            // If node is not colored, start DFS
            if(color[i] == -1)
            {
                if(DFS(graph, i, color, 1) == false)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    bool result = obj.isBipartite(graph);

    if(result)
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is NOT Bipartite" << endl;

    return 0;
}