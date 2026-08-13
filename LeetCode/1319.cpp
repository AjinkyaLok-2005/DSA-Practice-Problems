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

    void unionSet(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);

        if(u == v) return;

        if(rank_[u] < rank_[v])
        {
            parent[u] = v;
        }
        else if(rank_[u] > rank_[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank_[u]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections)
    {
        if((int)connections.size() < n - 1)
            return -1;

        makeSet(n);

        for(auto& c : connections)
        {
            unionSet(c[0], c[1]);
        }

        int components = 0;
        for(int i = 0; i < n; i++)
        {
            if(findParent(i) == i)
                components++;
        }

        return components - 1;
    }
};

int main()
{
    int n, m;
    cout << "Enter n (number of computers): ";
    cin >> n;

    cout << "Enter number of connections: ";
    cin >> m;

    vector<vector<int>> connections(m, vector<int>(2));

    cout << "Enter each connection as: a b\n";
    for(int i = 0; i < m; i++)
    {
        cin >> connections[i][0] >> connections[i][1];
    }

    Solution sol;
    int result = sol.makeConnected(n, connections);

    cout << "Minimum operations needed: " << result << endl;

    return 0;
}