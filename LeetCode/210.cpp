#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool hasCycle;

    void DFS(vector<bool>& visited, vector<bool>& inRecursion,
             unordered_map<int, vector<int>>& adj, int v, stack<int>& st)
    {
        visited[v] = true;
        inRecursion[v] = true;

        for(int& u : adj[v])
        {
            if(inRecursion[u] == true)
            {
                hasCycle = true;
                return;
            }

            if(!visited[u])
            {
                DFS(visited, inRecursion, adj, u, st);

                if(hasCycle)
                    return;
            }
        }

        st.push(v);
        inRecursion[v] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        hasCycle = false;
        stack<int> st;

        unordered_map<int, vector<int>> adj;

        for(auto& vec : prerequisites)
        {
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i])
            {
                DFS(visited, inRecursion, adj, i, st);

                if(hasCycle)
                    return {};
            }
        }

        vector<int> result;

        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

int main()
{
    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    Solution obj;

    vector<int> result = obj.findOrder(numCourses, prerequisites);

    if(result.empty())
    {
        cout << "No valid course order exists (Cycle detected)." << endl;
    }
    else
    {
        cout << "Course Order: ";

        for(int course : result)
        {
            cout << course << " ";
        }

        cout << endl;
    }

    return 0;
}