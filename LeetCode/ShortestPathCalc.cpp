#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adj; // adjacency list: [node] -> [(neighbor, weight)]
    int n;

public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);

        for(auto &edge : edges) {
            addEdge(edge);
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];
        adj[u].push_back({v, cost});
    }
    
    int shortestPath(int node1, int node2) {
        if (node1 == node2) return 0;
        if (node1 < 0 || node1 >= n || node2 < 0 || node2 >= n) return -1;
        
        // Initialize distances with infinity
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        
        // Set to store (distance, node) pairs, sorted by distance
        set<pair<int, int>> s;
        s.insert({0, node1});
        
        while (!s.empty()) {
            // Get the node with smallest distance
            auto it = s.begin();
            int currentDist = it->first;
            int currentNode = it->second;
            s.erase(it);
            
            // If we reached the target node, return the distance
            if (currentNode == node2) {
                return currentDist;
            }
            
            // Explore all neighbors
            for (auto &neighbor : adj[currentNode]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                
                // Check for integer overflow
                if (currentDist > INT_MAX - weight) {
                    continue; // Skip to avoid overflow
                }
                
                int newDist = currentDist + weight;
                
                // If we found a shorter path to nextNode
                if (newDist < dist[nextNode]) {
                    // Remove the old distance if it exists
                    if (dist[nextNode] != INT_MAX) {
                        s.erase({dist[nextNode], nextNode});
                    }
                    
                    // Update the distance and add to set
                    dist[nextNode] = newDist;
                    s.insert({newDist, nextNode});
                }
            }
        }
        
        // If we couldn't reach node2
        return -1;
    }
};

void testGraph() {
    // Test case 1: Simple graph
    cout << "Test Case 1: Simple graph\n";
    int n1 = 4;
    vector<vector<int>> edges1 = {{0, 1, 1}, {0, 2, 4}, {1, 2, 2}, {1, 3, 5}, {2, 3, 1}};
    
    Graph g1(n1, edges1);
    cout << "Shortest path from 0 to 3: " << g1.shortestPath(0, 3) << " (expected: 4)\n";
    cout << "Shortest path from 0 to 2: " << g1.shortestPath(0, 2) << " (expected: 3)\n";
    cout << "Shortest path from 1 to 3: " << g1.shortestPath(1, 3) << " (expected: 3)\n";
    cout << "Shortest path from 3 to 0: " << g1.shortestPath(3, 0) << " (expected: -1)\n";
    cout << endl;

    // Test case 2: Same node
    cout << "Test Case 2: Same node\n";
    int n2 = 3;
    vector<vector<int>> edges2 = {{0, 1, 1}, {1, 2, 1}};
    
    Graph g2(n2, edges2);
    cout << "Shortest path from 0 to 0: " << g2.shortestPath(0, 0) << " (expected: 0)\n";
    cout << endl;

    // Test case 3: No path
    cout << "Test Case 3: No path\n";
    int n3 = 3;
    vector<vector<int>> edges3 = {{0, 1, 1}};
    
    Graph g3(n3, edges3);
    cout << "Shortest path from 0 to 2: " << g3.shortestPath(0, 2) << " (expected: -1)\n";
    cout << "Shortest path from 2 to 0: " << g3.shortestPath(2, 0) << " (expected: -1)\n";
    cout << endl;

    // Test case 4: Single node
    cout << "Test Case 4: Single node\n";
    int n4 = 1;
    vector<vector<int>> edges4 = {};
    
    Graph g4(n4, edges4);
    cout << "Shortest path from 0 to 0: " << g4.shortestPath(0, 0) << " (expected: 0)\n";
    cout << endl;

    // Test case 5: Large weights
    cout << "Test Case 5: Large weights\n";
    int n5 = 3;
    vector<vector<int>> edges5 = {{0, 1, 1000}, {1, 2, 2000}};
    
    Graph g5(n5, edges5);
    cout << "Shortest path from 0 to 2: " << g5.shortestPath(0, 2) << " (expected: 3000)\n";
    cout << endl;

    // Test case 6: Add edges dynamically
    cout << "Test Case 6: Add edges dynamically\n";
    int n6 = 3;
    vector<vector<int>> initialEdges6 = {{0, 1, 1}};
    
    Graph g6(n6, initialEdges6);
    cout << "Before adding edge - path from 0 to 2: " << g6.shortestPath(0, 2) << " (expected: -1)\n";
    
    g6.addEdge({1, 2, 1});
    cout << "After adding edge - path from 0 to 2: " << g6.shortestPath(0, 2) << " (expected: 2)\n";
}

int main() {
    cout << "Testing Graph with Dijkstra's Algorithm\n";
    cout << "=======================================\n\n";
    
    testGraph();
    
    return 0;
}