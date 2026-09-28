#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths)
    {
        unordered_map<int, vector<int>> adj;

        // Build the undirected graph
        for(auto& vec : paths)
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 0 means no flower assigned
        // 1, 2, 3, 4 are flower types
        vector<int> flowersAssigned(n + 1, 0);

        // Process each garden
        for(int i = 1; i <= n; i++)
        {
            bool used[5] = {false};

            // Find flowers already used by neighbors
            for(int neighbor : adj[i])
            {
                if(flowersAssigned[neighbor] != 0)
                {
                    used[flowersAssigned[neighbor]] = true;
                }
            }

            // Assign the first available flower
            for(int flower = 1; flower <= 4; flower++)
            {
                if(!used[flower])
                {
                    flowersAssigned[i] = flower;
                    break;
                }
            }
        }

        // Remove index 0 because gardens are numbered 1 to n
        return vector<int>(
            flowersAssigned.begin() + 1,
            flowersAssigned.end()
        );
    }
};

int main()
{
    Solution obj;

    int n = 4;

    vector<vector<int>> paths = {
        {1, 2},
        {3, 4}
    };

    vector<int> result = obj.gardenNoAdj(n, paths);

    cout << "Flower assignment: ";

    for(int flower : result)
    {
        cout << flower << " ";
    }

    cout << endl;

    return 0;
}