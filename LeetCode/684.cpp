#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> parent, rank_;

    void makeSet(int n)
    {
        parent.resize(n);
        rank_.resize(n);

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank_[i] = 0;
        }
    }

    int findParent(int node)
    {
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }
    
    void unionSet(int a, int b, vector<vector<int>>& additional)
    {
        int u = findParent(a);
        int v = findParent(b);

        if(u == v)
            return (void)additional.push_back({a, b});

        if(rank_[u] > rank_[v])
        {
            parent[v] = u;
        }
        else if(rank_[u] < rank_[v])
        {
            parent[u] = v;
        }
        else
        {
            parent[v] = u;
            rank_[u]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        makeSet(n+1);

        vector<vector<int>> additional;

        for(auto& e : edges)
        {
            unionSet(e[0], e[1], additional);
        }

        int m = additional.size();

        return additional[m-1];
        
    }   
};

int main()
{
    int n;
    cout << "Enter number of edges: ";
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2));
    cout << "Enter each edge as: a b\n";
    for(int i = 0; i < n; i++)
        cin >> edges[i][0] >> edges[i][1];

    Solution sol;
    vector<int> result = sol.findRedundantConnection(edges);

    cout << "Redundant edge: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}