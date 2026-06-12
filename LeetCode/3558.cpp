#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:

    int M = 1e9+7;

    typedef long long ll;
    ll power(ll base, ll exponent)
    {
        if(exponent == 0)
            return 1;

        ll half = power(base, exponent / 2);

        ll result = (half * half) % M;

        if(exponent % 2 == 1)//odd
        {
            result = (result * base) % M;
        }

        return result;
    }

    int getMaxDepth(unordered_map<int, vector<int>>& adj, int node, int parent)
    {
        int depth = 0;

        for(int ngbr: adj[node])
        {
            if(ngbr == parent)
                continue;

            depth = max(depth, getMaxDepth(adj, ngbr, node) + 1);
        }

        return depth;
    }
    
    int assignEdgeWeights(vector<vector<int>>& edges) 
    {
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d = getMaxDepth(adj, 1, -1);

        return power(2, d-1);
    }
};

int main()
{
    int n;

    cout << "Enter number of edges: ";
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2));

    cout << "Enter edges (u v): " << endl;
    for(int i = 0; i < n; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    int result = obj.assignEdgeWeights(edges);

    cout << "Maximum Edge Weight = " << result << endl;

    return 0;
}
