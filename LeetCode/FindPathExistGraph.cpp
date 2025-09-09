#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        if(source == destination)
        {
            return true;
        }

        unordered_map<int, list<int>> adj;

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, int> visited;
    
        visited[source] = 1;
        queue<int> q;
        q.push(source);

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            if(front == destination)
            {
                return true;
            }

            for(auto neighbour : adj[front])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        return false;

    }
};

// Test function
void testValidPath() {
    Solution solution;
    
    // Test case 1: The provided test case that was failing
    int n1 = 10;
    vector<vector<int>> edges1 = {{4,3}, {1,4}, {4,8}, {1,7}, {6,4}, {4,2}, {7,4}, {4,0}, {0,9}, {5,4}};
    int source1 = 5;
    int destination1 = 9;
    
    bool result1 = solution.validPath(n1, edges1, source1, destination1);
    cout << "Test case 1 (5 to 9): " << (result1 ? "Path exists" : "No path") << endl;
    cout << "Expected: Path exists" << endl << endl;
    
    // Test case 2: Same graph, different path
    int source2 = 3;
    int destination2 = 9;
    bool result2 = solution.validPath(n1, edges1, source2, destination2);
    cout << "Test case 2 (3 to 9): " << (result2 ? "Path exists" : "No path") << endl;
    cout << "Expected: Path exists" << endl << endl;
    
    // Test case 3: No path (disconnected components)
    int n3 = 4;
    vector<vector<int>> edges3 = {{0,1}, {2,3}};
    int source3 = 0;
    int destination3 = 3;
    bool result3 = solution.validPath(n3, edges3, source3, destination3);
    cout << "Test case 3 (0 to 3 in disconnected graph): " << (result3 ? "Path exists" : "No path") << endl;
    cout << "Expected: No path" << endl << endl;
    
    // Test case 4: Direct connection
    int n4 = 2;
    vector<vector<int>> edges4 = {{0,1}};
    int source4 = 0;
    int destination4 = 1;
    bool result4 = solution.validPath(n4, edges4, source4, destination4);
    cout << "Test case 4 (0 to 1): " << (result4 ? "Path exists" : "No path") << endl;
    cout << "Expected: Path exists" << endl << endl;
    
    // Test case 5: Single node
    int n5 = 1;
    vector<vector<int>> edges5 = {};
    int source5 = 0;
    int destination5 = 0;
    bool result5 = solution.validPath(n5, edges5, source5, destination5);
    cout << "Test case 5 (single node): " << (result5 ? "Path exists" : "No path") << endl;
    cout << "Expected: Path exists" << endl << endl;
}

int main() {
    testValidPath();
    return 0;
}