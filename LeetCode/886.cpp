#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bipartiteDFS(vector<vector<int>>& adj,
                      int curr,
                      vector<int>& group,
                      int currGrp)
    {
        group[curr] = currGrp;

        for(int v : adj[curr])
        {
            // If adjacent nodes have the same group
            if(group[v] == group[curr])
                return false;

            // If v is not assigned a group
            if(group[v] == -1)
            {
                int groupOfV = 1 - currGrp;

                if(bipartiteDFS(adj, v, group, groupOfV) == false)
                    return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        // Nodes are numbered from 1 to n
        vector<vector<int>> adj(n + 1);

        // Build an undirected graph
        for(const auto& vec : dislikes)
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // -1 = not visited
        //  0 = group 0
        //  1 = group 1
        vector<int> group(n + 1, -1);

        // Graph may contain multiple disconnected components
        for(int i = 1; i <= n; i++)
        {
            if(group[i] == -1)
            {
                if(bipartiteDFS(adj, i, group, 0) == false)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;

    int n = 4;

    vector<vector<int>> dislikes = {
        {1, 2},
        {1, 3},
        {2, 4}
    };

    bool result = obj.possibleBipartition(n, dislikes);

    if(result)
        cout << "Possible Bipartition" << endl;
    else
        cout << "Not Possible" << endl;

    return 0;
}